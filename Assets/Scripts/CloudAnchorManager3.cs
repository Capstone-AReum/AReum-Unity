using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;
using UnityEngine.Audio;

using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using Google.XR.ARCoreExtensions;
using UnityEngine.Networking;
using Siccity.GLTFUtility;
using UnityEngine.EventSystems;
using Newtonsoft.Json;
using UnityEngine.SceneManagement;
using NativeGalleryNamespace;

// Main Scene에서 Resolve 시 사용
public class CloudAnchorManager3 : MonoBehaviour
{
    // 상태 변수
    public enum Mode { READY, HOST, HOST_PENDING, RESOLVE, RESOLVE_PENDING };

    // 버튼
    public Button resolveButton;
    //public Button resetButton;

    // 상태변수
    public Mode mode = Mode.READY;

    // AnchorManager
    public ARAnchorManager anchorManager;

    // ArRaycastManager
    public ARRaycastManager raycastManager;

    // 증강시킬 객체 프리팹
    public GameObject anchorPrefab;

    // 말풍선 프리팹
    [SerializeField] private Canvas uiCanvas; // 말풍선 UI가 배치될 캔버스
    [SerializeField] private Camera arCamera; // AR 카메라
    [SerializeField] private GameObject speechBubblePrefab; // 말풍선 프리팹

    // ProgressBar 관련
    [SerializeField] private GameObject progressPanel; // 진행바 부모 패널
    [SerializeField] private TextMeshProUGUI infoText; // resolve 진행 과정 설명
    [SerializeField] private Slider resolveProgressBar; // resolve 작업 진행바
    private float resolveProgress = 0f; // 진행 상태 (0 ~ 100)

    // 클라우드 앵커 오브젝트와 말풍선을 매핑하기 위한 Dictionary
    private Dictionary<GameObject, GameObject> speechBubbleMap = new Dictionary<GameObject, GameObject>();

    // 저장 객체 변수 (삭제용)
    private GameObject anchorGameObject;

    // 로컬 앵커 저장 변수
    private ARAnchor localAnchor;

    // 클라우드 앵커 변수
    private ARCloudAnchor cloudAnchor;

    // Raycast Hit
    private List<ARRaycastHit> hits = new List<ARRaycastHit>();

    private bool isResolving = false;

    // Cloud Anchor 데이터 관리용
    private Dictionary<string, AnchorData> anchorDataMap = new Dictionary<string, AnchorData>();

    // 음성 관련
    private AudioSource audioSource; // 음성 파일 재생용
    private Dictionary<int, AudioClip> audioClipCache = new Dictionary<int, AudioClip>(); // 음성 파일 캐싱

    void Start()
    {
        resolveButton.onClick.AddListener(OnResolveClick);

        // 슬라이더 초기화
        if (resolveProgressBar != null)
        {
            progressPanel.gameObject.SetActive(false);
            resolveProgressBar.value = 0;
            resolveProgressBar.gameObject.SetActive(false);
            Debug.Log("Settings DONE");
        }

        // AnchorData 로드
        LoadAnchorData();
    }

    void Update()
    {
        if (mode == Mode.RESOLVE)
        {
            ResolveAllCloudAnchors();
        }
        if (mode == Mode.READY)
        {
            UpdateSpeechBubblePosition();
        }
    }

    public void OnResolveClick()
    {
        progressPanel.gameObject.SetActive(true);

        if (mode == Mode.READY)
        {
            mode = Mode.RESOLVE; // 상태를 RESOLVE로 변경
            Debug.Log("클라우드 앵커 리졸빙 시작");

            // 모든 클라우드 앵커 리졸빙 시작
            ResolveAllCloudAnchors();
        }
        else
        {
            Debug.LogWarning("현재 상태에서 리졸빙 작업을 시작할 수 없습니다.");
            infoText.text = "리졸빙 불가능한 상태입니다.";
        }
    }

    public void ResolveAllCloudAnchors()
    {
        if (isResolving) return;

        if (anchorDataMap.Count == 0)
        {
            Debug.LogError("저장된 Cloud Anchor가 없습니다.");
            infoText.text = "저장된 클라우드 앵커가 없습니다.";
            mode = Mode.READY;
            return;
        }

        StartCoroutine(ResolveAllCloudAnchorsCoroutine());
    }

    private IEnumerator ResolveAllCloudAnchorsCoroutine()
    {
        isResolving = true;

        if (resolveProgressBar != null)
        {
            resolveProgressBar.gameObject.SetActive(true); // 슬라이더 표시
        }

        int totalAnchors = anchorDataMap.Count; // 클라우드 앵커 총 개수
        int resolvedCount = 0;  // 실패든 성공이든 리졸빙 완료된 클라우드 앵커 개수
        int failedCount = 0;    // 실패한 클라우드 앵커 개수

        foreach (var kvp in anchorDataMap)
        {
            string cloudAnchorId = kvp.Key;
            AnchorData data = kvp.Value;

            infoText.text = $"클라우드 앵커를 리졸빙 하는 중입니다.. ({resolvedCount - failedCount}/{totalAnchors} 성공)";

            ResolveCloudAnchorPromise promise = anchorManager.ResolveCloudAnchorAsync(cloudAnchorId);

            if (promise == null)
            {
                Debug.LogError($"클라우드 앵커 리졸빙 요청 실패: ID = {cloudAnchorId}");
                continue;
            }

            float timeout = 20f;
            float elapsedTime = 0f;

            while (promise.State == PromiseState.Pending && elapsedTime < timeout)
            {
                yield return new WaitForSeconds(1f);
                float progress = (((resolvedCount * timeout) + elapsedTime) / (timeout * totalAnchors)) * 100f; // 타임아웃 기준 진행도 계산
                UpdateResolveProgress(progress);
                elapsedTime += 1f;
            }

            // 타임아웃이면
            if (promise.State == PromiseState.Pending)
            {
                Debug.LogError($"클라우드 앵커 리졸빙 타임아웃: ID = {cloudAnchorId}");

                resolvedCount++;
                //UpdateResolveProgress((float)resolvedCount / totalAnchors * 100f); // 전체 진행도 업데이트

                failedCount++;
                infoText.text = $"클라우드 앵커를 리졸빙 하는 중입니다.. ({resolvedCount - failedCount}/{totalAnchors} 성공)";

                continue;
            }

            if (promise.Result.CloudAnchorState == CloudAnchorState.Success)
            {
                Debug.Log($"클라우드 앵커 리졸빙 성공: ID = {cloudAnchorId}");

                resolvedCount++;
                float progress = (((resolvedCount * timeout) + elapsedTime) / (timeout * totalAnchors)) * 100f;
                UpdateResolveProgress(progress);// 전체 진행도 업데이트

                infoText.text = $"클라우드 앵커를 리졸빙 하는 중입니다.. ({resolvedCount - failedCount}/{totalAnchors} 성공)";

                ARCloudAnchor resolvedAnchor = promise.Result.Anchor;

                if (resolvedAnchor != null)
                {
                    // GLB 파일 로드
                    StartCoroutine(LoadGLBFile(data.glbFilePath, (loadedObject) =>
                    {
                        loadedObject.transform.position = resolvedAnchor.transform.position;
                        loadedObject.transform.rotation = resolvedAnchor.transform.rotation;
                        loadedObject.transform.localScale = Vector3.one * data.scale;
                        loadedObject.transform.Rotate(0, data.rotationY, 0);

                        Debug.Log($"GLB Object 적용 완료: {data.glbFilePath}");

                        // 말풍선 생성
                        CreateSpeechBubble(loadedObject, data.sourceId);
                    }));
                }
                else
                {
                    Debug.LogError($"리졸빙된 앵커가 null입니다: ID = {cloudAnchorId}");
                }
            }
            else
            {
                Debug.LogError($"클라우드 앵커 리졸빙 실패: ID = {cloudAnchorId}, 상태: {promise.Result.CloudAnchorState}");
            }
        }
        mode = Mode.READY;
        isResolving = false;

        // 진행 바를 숨기기 위한 코루틴 호출
        StartCoroutine(HideProgressPanelAfterDelay(3.0f));
    }

    private void UpdateResolveProgress(float progress)
    {
        if (resolveProgressBar != null)
        {
            resolveProgressBar.value = progress;
        }
    }


    public void CreateSpeechBubble(GameObject target, int sourceId)
    {
        if (speechBubblePrefab == null || uiCanvas == null || arCamera == null)
        {
            Debug.LogError("SpeechBubbleManager: 필요한 요소가 설정되지 않았습니다.");
            return;
        }

        string getPhotoDetailUrl = "http://ec2-43-200-16-231.ap-northeast-2.compute.amazonaws.com/albums";
        string url = $"{getPhotoDetailUrl}/{sourceId}/details";

        StartCoroutine(LoadPhotoDetails(target, url));
    }

    IEnumerator LoadPhotoDetails(GameObject target, string url)
    {
        // 말풍선 새로 생성
        GameObject bubbleInstance = Instantiate(speechBubblePrefab, uiCanvas.transform);
        var bubbleText = bubbleInstance.GetComponentInChildren<TextMeshProUGUI>();
        var button = bubbleInstance.GetComponentInChildren<Button>(); // 말풍선 내 버튼 컴포넌트

        UnityWebRequest request = UnityWebRequest.Get(url);
        yield return request.SendWebRequest();

        if (request.result == UnityWebRequest.Result.Success)
        {
            string jsonResponse = request.downloadHandler.text;
            PhotoItemDetail photo = JsonConvert.DeserializeObject<PhotoItemDetail>(jsonResponse);

            // 사진 정보를 UI에 표시
            if (bubbleText != null)
            {
                bubbleText.text = photo.title;
            }

            // 버튼 클릭 이벤트 추가
            if (button != null)
            {
                button.onClick.AddListener(() => OnBubbleClicked(photo.id));
            }

            // SpeechBubbleManager를 통해 관리
            SpeechBubbleManager.Instance.AddSpeechBubble(target, bubbleInstance);

            Debug.Log($"'{photo.title}' 말풍선 생성됨");
        }
        else
        {
            Debug.LogError($"Failed to load photo details: {request.error}");
        }
    }

    private void OnBubbleClicked(int id)
    {
        AlbumManager.selectedPhotoId = id;
        string apiUrl = $"http://ec2-43-200-16-231.ap-northeast-2.compute.amazonaws.com/albums/{id}/sounds";

        // 이미 다운로드된 AudioClip이 있다면 바로 재생
        if (audioClipCache.ContainsKey(id))
        {
            PlayAudio(audioClipCache[id]);
        }
        else
        {
            // MP3 URL을 가져오고 음성 파일 다운로드 및 재생
            StartCoroutine(FetchAudioUrlAndPlay(apiUrl, id));
        }
    }

    private IEnumerator FetchAudioUrlAndPlay(string apiUrl, int id)
    {
        // 첫 번째 요청: MP3 파일의 URL 문자열 가져오기
        UnityWebRequest urlRequest = UnityWebRequest.Get(apiUrl);
        yield return urlRequest.SendWebRequest();

        if (urlRequest.result == UnityWebRequest.Result.Success)
        {
            // 서버에서 반환된 MP3 URL 문자열
            string mp3Url = urlRequest.downloadHandler.text;
            mp3Url = mp3Url.Trim('"'); // 앞뒤 따옴표 제거
            Debug.Log($"Processed MP3 URL: {mp3Url}");

            // 두 번째 요청: MP3 파일 다운로드 및 재생
            StartCoroutine(DownloadAndPlayAudio(mp3Url, id));
        }
        else
        {
            Debug.LogError($"Failed to fetch MP3 URL: {urlRequest.error}");
        }
    }

    private IEnumerator DownloadAndPlayAudio(string mp3Url, int id)
    {
        // URL 공백 제거
        mp3Url = mp3Url.Trim();

        UnityWebRequest audioRequest = UnityWebRequestMultimedia.GetAudioClip(mp3Url, AudioType.MPEG);
        yield return audioRequest.SendWebRequest();

        if (audioRequest.result == UnityWebRequest.Result.Success)
        {
            AudioClip audioClip = DownloadHandlerAudioClip.GetContent(audioRequest);

            if (audioClip != null)
            {
                audioClipCache[id] = audioClip;
                PlayAudio(audioClip);
            }
            else
            {
                Debug.LogError("Audio clip is null.");
            }
        }
        else
        {
            Debug.LogError($"Failed to download MP3 file: {audioRequest.error}");
        }
    }


    private void PlayAudio(AudioClip clip)
    {
        if (audioSource == null)
        {
            // AudioSource가 없으면 동적으로 생성
            audioSource = gameObject.AddComponent<AudioSource>();
        }

        // AudioSource 설정 및 재생
        audioSource.clip = clip;
        audioSource.Play();

        Debug.Log("Audio playing...");
    }

    private void UpdateSpeechBubblePosition()
    {
        if (uiCanvas == null || arCamera == null)
        {
            Debug.LogError("Canvas 또는 AR 카메라가 null입니다.");
            return;
        }

        RectTransform canvasRect = uiCanvas.GetComponent<RectTransform>();

        foreach (var pair in SpeechBubbleManager.Instance.SpeechBubbleMap)
        {
            GameObject target = pair.Key; // 클라우드 앵커 GLB 오브젝트
            GameObject bubble = pair.Value; // 말풍선

            if (target == null || bubble == null)
            {
                //Debug.LogWarning("Target 또는 Bubble이 null입니다.");
                continue;
            }

            RectTransform bubbleRect = bubble.GetComponent<RectTransform>();

            // 3D 오브젝트의 월드 좌표를 화면 좌표로 변환
            Vector3 screenPosition = arCamera.WorldToScreenPoint(target.transform.position);

            /*if (screenPosition.z < 0)
            {
                Debug.LogWarning("AR 객체가 카메라 뒤에 있습니다.");
                bubble.SetActive(true);
                continue;
            }*/

            // 화면 좌표를 UI 캔버스의 로컬 좌표로 변환
            Vector2 uiPosition;
            if (RectTransformUtility.ScreenPointToLocalPointInRectangle(canvasRect, screenPosition, arCamera, out uiPosition))
            {
                // 말풍선 위치 업데이트
                bubbleRect.anchoredPosition = uiPosition + new Vector2(0, 150); // 오브젝트 위로 약간 올림
                bubble.SetActive(true);
            }
            else
            {
                //Debug.LogWarning("RectTransformUtility.ScreenPointToLocalPointInRectangle 실패.");
                //왜 실패하는거지..? 근데 이걸 true로 해줘야 원래 위치에 잘 나옴
                bubble.SetActive(true);
            }

            // 말풍선을 카메라 방향으로 설정
            Vector3 cameraForward = arCamera.transform.forward;
            Vector3 cameraUp = arCamera.transform.up;
            bubble.transform.rotation = Quaternion.LookRotation(cameraForward, cameraUp);
            bubble.SetActive(true);
        }
    }


    private IEnumerator LoadGLBFile(string url, Action<GameObject> onLoaded)
    {
        UnityWebRequest request = UnityWebRequest.Get(url);

        yield return request.SendWebRequest();

        if (request.result == UnityWebRequest.Result.Success)
        {
            byte[] glbData = request.downloadHandler.data;

            // GLB 데이터 로드 (GLTF/GLB 라이브러리 사용 필요)
            GameObject loadedObject = ImportGLB(glbData);

            if (loadedObject != null)
            {
                Debug.Log($"GLB 파일 로드 성공: {url}");
                onLoaded.Invoke(loadedObject);
            }
            else
            {
                Debug.LogError($"GLB 파일 로드 실패: {url}");
            }
        }
        else
        {
            Debug.LogError($"GLB 파일 다운로드 실패: {url} | Error: {request.error}");
        }
    }

    private GameObject ImportGLB(byte[] glbData)
    {
        try
        {
            // GLB 파일 데이터를 Unity 오브젝트로 변환
            ImportSettings settings = new ImportSettings(); // 필요한 설정을 초기화
            GameObject loadedObject = Importer.LoadFromBytes(glbData, settings);

            if (loadedObject != null)
            {
                Debug.Log("GLB 파일 로드 성공");
            }
            else
            {
                Debug.LogError("GLB 파일 로드 실패: 로드된 오브젝트가 null입니다.");
            }

            return loadedObject;
        }
        catch (Exception ex)
        {
            Debug.LogError($"GLB 파일 로드 중 예외 발생: {ex.Message}");
            return null;
        }
    }

    private void LoadAnchorData()
    {
        if (PlayerPrefs.HasKey("AnchorDataMap"))
        {
            string json = PlayerPrefs.GetString("AnchorDataMap");

            // SerializableDictionary 역직렬화
            SerializableDictionary<string, AnchorData> serializableData = JsonUtility.FromJson<SerializableDictionary<string, AnchorData>>(json);

            // 일반 Dictionary로 변환
            anchorDataMap = serializableData.ToDictionary();
            Debug.Log("AnchorData 로드 완료");
        }
        else
        {
            anchorDataMap = new Dictionary<string, AnchorData>();
            Debug.Log("저장된 AnchorData가 없습니다.");
        }
    }

    public void OnResetClick()
    {
        // 1. 모든 GLB 오브젝트와 로컬 앵커 삭제
        if (anchorGameObject != null)
        {
            Destroy(anchorGameObject);
            anchorGameObject = null;
        }

        if (localAnchor != null)
        {
            Destroy(localAnchor.gameObject);
            localAnchor = null;
        }

        // 2. 클라우드 앵커 삭제
        if (cloudAnchor != null)
        {
            Destroy(cloudAnchor.gameObject);
            cloudAnchor = null;
        }

        // 3. AnchorDataMap 초기화 및 PlayerPrefs 삭제
        anchorDataMap.Clear();
        PlayerPrefs.DeleteKey("AnchorDataMap");
        PlayerPrefs.Save();

        // 4. 모든 말풍선 삭제
        foreach (var bubble in speechBubbleMap.Values)
        {
            Destroy(bubble);
        }
        speechBubbleMap.Clear();

        // 5. 상태 초기화
        Debug.Log("Reset 완료: 모든 오브젝트 및 앵커 삭제");
        mode = Mode.READY;
    }

    // UI 터치는 AR 상의 터치로 인식되지 않게 하기 위한 함수
    // ray를 먼저 쏴보고 부딪힌 뭔가가 있으면 RaycastManager을 쏘지 않음
    bool isPointOverUIObject(Vector2 pos)
    {
        PointerEventData eventDataCurPosition = new PointerEventData(EventSystem.current);
        eventDataCurPosition.position = pos;
        List<RaycastResult> results = new List<RaycastResult>();
        EventSystem.current.RaycastAll(eventDataCurPosition, results);
        return results.Count > 0;
    }

    private IEnumerator HideProgressPanelAfterDelay(float delay)
    {
        yield return new WaitForSeconds(delay);
        if (progressPanel != null)
        {
            progressPanel.SetActive(false);
        }
    }

}