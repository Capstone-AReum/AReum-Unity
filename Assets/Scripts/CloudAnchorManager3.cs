using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using Google.XR.ARCoreExtensions;
using UnityEngine.Networking;
using Siccity.GLTFUtility;
using UnityEngine.EventSystems;

// Main Scene에서 Resolve, (Reset) 시 사용
public class CloudAnchorManager3 : MonoBehaviour
{
    // 상태 변수
    public enum Mode { READY, HOST, HOST_PENDING, RESOLVE, RESOLVE_PENDING };

    // 버튼
    public Button resolveButton;
    public Button resetButton;

    // 메시지 출력 텍스트
    public TextMeshProUGUI messageText;

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

    private GameObject speechBubbleInstance; // 말풍선 인스턴스
    private GameObject targetObject; // 대상 3D 오브젝트
    private RectTransform speechBubbleRect;
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
    private bool isConfirmed = false;

    // Cloud Anchor 데이터 관리용
    private Dictionary<string, AnchorData> anchorDataMap = new Dictionary<string, AnchorData>();

    // 현재 변환 정보
    private float scale = 1.0f;
    private float angle = 0.0f;

    void Start()
    {
        resolveButton.onClick.AddListener(OnResolveClick);
        resetButton.onClick.AddListener(OnResetClick);

        // AnchorData 로드
        LoadAnchorData();
        messageText.text = "시작";
    }

    void Update()
    {
        if (mode == Mode.RESOLVE)
        {
            ResolveAllCloudAnchors();
        }
        if (targetObject != null)
        {
            UpdateSpeechBubblePosition();
        }
    }

    private void OnResolveClick()
    {
        if (mode == Mode.READY)
        {
            mode = Mode.RESOLVE; // 상태를 RESOLVE로 변경
            messageText.text = "클라우드 앵커 리졸빙 시작";
            Debug.Log("클라우드 앵커 리졸빙 시작");

            // 모든 클라우드 앵커 리졸빙 시작
            ResolveAllCloudAnchors();
        }
        else
        {
            Debug.LogWarning("현재 상태에서 리졸빙 작업을 시작할 수 없습니다.");
            messageText.text = "리졸빙 불가능한 상태입니다.";
        }
    }

    public void ResolveAllCloudAnchors()
    {
        if (isResolving) return;

        if (anchorDataMap.Count == 0)
        {
            Debug.LogError("저장된 Cloud Anchor가 없습니다.");
            messageText.text = "저장된 클라우드 앵커가 없음";
            mode = Mode.READY;
            return;
        }

        StartCoroutine(ResolveAllCloudAnchorsCoroutine());
    }

    private IEnumerator ResolveAllCloudAnchorsCoroutine()
    {
        isResolving = true;

        foreach (var kvp in anchorDataMap)
        {
            string cloudAnchorId = kvp.Key;
            AnchorData data = kvp.Value;

            messageText.text = $"클라우드 앵커 리졸빙 시작: ID = {cloudAnchorId}";

            ResolveCloudAnchorPromise promise = anchorManager.ResolveCloudAnchorAsync(cloudAnchorId);

            if (promise == null)
            {
                Debug.LogError($"클라우드 앵커 리졸빙 요청 실패: ID = {cloudAnchorId}");
                messageText.text = $"클라우드 앵커 리졸빙 요청 실패: ID = {cloudAnchorId}";
                continue;
            }

            float timeout = 20f;
            float elapsedTime = 0f;

            while (promise.State == PromiseState.Pending && elapsedTime < timeout)
            {
                yield return new WaitForSeconds(1f);
                elapsedTime += 1f;
            }

            // 타임아웃이면
            if (promise.State == PromiseState.Pending)
            {
                Debug.LogError($"클라우드 앵커 리졸빙 타임아웃: ID = {cloudAnchorId}");
                messageText.text = $"클라우드 앵커 리졸빙 타임아웃: ID = {cloudAnchorId}";
                continue;
            }

            if (promise.Result.CloudAnchorState == CloudAnchorState.Success)
            {
                Debug.Log($"클라우드 앵커 리졸빙 성공: ID = {cloudAnchorId}");
                messageText.text = $"클라우드 앵커 리졸빙 성공: ID = {cloudAnchorId}";

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
                        CreateSpeechBubble(loadedObject, $"Photo ID: {data.sourceId}");
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
                messageText.text = $"클라우드 앵커 리졸빙 실패: ID = {cloudAnchorId}, 상태: {promise.Result.CloudAnchorState}";
            }
        }
        mode = Mode.READY;
    }

    public void CreateSpeechBubble(GameObject target, string message)
    {
        if (speechBubblePrefab == null || uiCanvas == null || arCamera == null)
        {
            Debug.LogError("SpeechBubbleManager: 필요한 요소가 설정되지 않았습니다.");
            return;
        }

        // 이미 해당 타겟에 말풍선이 있으면 삭제 후 새로 생성
        if (speechBubbleMap.ContainsKey(target))
        {
            Destroy(speechBubbleMap[target]);
            speechBubbleMap.Remove(target);
        }

        // 새로운 말풍선 생성
        GameObject bubbleInstance = Instantiate(speechBubblePrefab, uiCanvas.transform);
        RectTransform bubbleRect = bubbleInstance.GetComponent<RectTransform>();

        targetObject = target;  // 필요없을것같긴한데

        // 텍스트 설정
        var bubbleText = bubbleInstance.GetComponentInChildren<TextMeshProUGUI>();
        if (bubbleText != null)
        {
            bubbleText.text = message;
        }

        // 말풍선을 맵에 저장
        speechBubbleMap[target] = bubbleInstance;
        Debug.Log($"{bubbleText.text} 말풍선 생성됨");
    }

    private void UpdateSpeechBubblePosition()
    {
        RectTransform canvasRect = uiCanvas.GetComponent<RectTransform>();

        foreach (var pair in speechBubbleMap)
        {
            GameObject target = pair.Key; // 클라우드 앵커 GLB 오브젝트
            GameObject bubble = pair.Value; // 말풍선

            if (target == null || bubble == null)
            {
                Debug.Log("null임");
                continue;
            }

            RectTransform bubbleRect = bubble.GetComponent<RectTransform>();

            // 3D 오브젝트의 월드 좌표를 화면 좌표로 변환
            Vector3 screenPosition = arCamera.WorldToScreenPoint(target.transform.position);

            // 화면 좌표를 UI 캔버스의 로컬 좌표로 변환
            Vector2 uiPosition;
            if (RectTransformUtility.ScreenPointToLocalPointInRectangle(canvasRect, screenPosition, arCamera, out uiPosition))
            {
                // 말풍선 위치 업데이트
                bubbleRect.anchoredPosition = uiPosition + new Vector2(0, 150); // 오브젝트 위로 약간 올림
            }

            // 화면 밖으로 나가거나 AR 카메라에서 보이지 않으면 숨기기
            /*if (screenPosition.z < 0 || !RectTransformUtility.RectangleContainsScreenPoint(canvasRect, screenPosition, arCamera))
            {
                bubble.SetActive(false);
            }
            else
            {
                bubble.SetActive(true);
            }*/
            bubble.SetActive(true);

            // 말풍선을 카메라 방향으로 설정
            Vector3 cameraForward = arCamera.transform.forward;
            Vector3 cameraUp = arCamera.transform.up;
            bubble.transform.rotation = Quaternion.LookRotation(cameraForward, cameraUp);
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

    private void OnResetClick()
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
        messageText.text = "Cloud Anchor가 모두 삭제되었습니다.";
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
}