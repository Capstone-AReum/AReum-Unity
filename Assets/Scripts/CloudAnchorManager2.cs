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

public class CloudAnchorManager2 : MonoBehaviour
{
    // 상태 변수
    public enum Mode { READY, HOST, HOST_PENDING, RESOLVE, RESOLVE_PENDING };

    // 버튼
    public Button confirmButton;

    // 팝업
    public TextMeshProUGUI headText;
    public GameObject popupPanel;
    public TextMeshProUGUI popupText;    // 팝업 내부 TextMeshPro
    public Button okButton;         // 팝업의 확인 버튼

    // 상태변수
    public Mode mode = Mode.READY;

    // AnchorManager
    public ARAnchorManager anchorManager;

    // ArRaycastManager
    public ARRaycastManager raycastManager;

    // 저장 객체 변수 (삭제용)
    private GameObject anchorGameObject;

    // 로컬 앵커 저장 변수
    private ARAnchor localAnchor;

    // Raycast Hit
    private List<ARRaycastHit> hits = new List<ARRaycastHit>();

    private bool isConfirmed = false;

    // Cloud Anchor 데이터 관리용
    private Dictionary<string, AnchorData> anchorDataMap = new Dictionary<string, AnchorData>();

    // 현재 변환 정보
    private float scale = 0.5f;
    private float angle = 0.0f;

    private bool isModelingDone = false; // 3D 모델링 완료 여부 체크용

    void Start()
    {
        popupPanel.SetActive(false);

        confirmButton.onClick.AddListener(OnConfirmClick);

        // AnchorData 로드
        LoadAnchorData();

        mode = Mode.HOST;
        Debug.LogWarning("호스팅 시작");
        //messageText.text = "원하는 위치에 배치해주세요.";
    }

    void Update()
    {
        if (mode == Mode.HOST && !isConfirmed)
        {
            string glbFileUrl = "https://cap-areum.s3.ap-northeast-2.amazonaws.com/models/Dv9_fHKTiCK8Cs4I9ndVAA.glb";
            UpdateLocalAnchorPosition(glbFileUrl);
        }
    }

    private void UpdateLocalAnchorPosition(string glbFileUrl)
    {
        if (Input.touchCount < 1) return;

        Touch touch = Input.GetTouch(0);
        Vector2 touchPosition = touch.position;
        if (touch.phase != TouchPhase.Began) return;

        // 터치가 다른 UI 컴포넌트에서 일어났는지 확인
        if (isPointOverUIObject(touchPosition))
        {
            return;
        }

        // Raycast로 터치 위치의 평면 확인
        if (raycastManager.Raycast(touch.position, hits, TrackableType.PlaneWithinPolygon))
        {
            var hitPose = hits[0].pose;

            // 기존 로컬 앵커 제거
            if (localAnchor != null)
            {
                Destroy(localAnchor.gameObject);
                localAnchor = null;
            }

            // 새로운 로컬 앵커 생성
            localAnchor = anchorManager.AddAnchor(hitPose);

            // 기존 앵커 객체 삭제 후 새로 생성
            if (anchorGameObject != null)
            {
                Destroy(anchorGameObject);
            }

            // GLB 파일 로드 및 설정
            StartCoroutine(LoadGLBFile(glbFileUrl, (loadedObject) =>
            {
                anchorGameObject = loadedObject;
                anchorGameObject.transform.SetParent(localAnchor.transform, false);
                Debug.Log("로컬 앵커와 GLB Object 생성 완료");
            }));
        }
    }

    public void UpdateScale(float sliderValue)
    {
        scale = sliderValue;

        if (anchorGameObject)
        {
            anchorGameObject.transform.localScale = Vector3.one * scale;
        }
    }

    public void UpdateRotation(float sliderValue)
    {
        angle = sliderValue;

        if (anchorGameObject)
        {
            anchorGameObject.transform.localRotation = Quaternion.Euler(0, angle, 0);
        }
    }

    private void OnConfirmClick()
    {
        if (mode == Mode.HOST && localAnchor != null)
        {
            isConfirmed = true;
            Debug.Log("로컬 앵커 위치가 확정되었습니다.");

            popupPanel.SetActive(true);
            popupText.text = "클라우드 앵커를 생성하는 중입니다...";
            okButton.gameObject.SetActive(false);

            StartCoroutine(ConfirmAndSwitchScene());
        }
        else
        {
            Debug.LogWarning("로컬 앵커가 없거나 Hosting 상태가 아닙니다.");
        }
    }

    private IEnumerator ConfirmAndSwitchScene()
    {
        // StartHosting 코루틴이 완료될 때까지 대기
        yield return StartCoroutine(StartHosting());
    }

    private IEnumerator StartHosting()
    {
        HostCloudAnchorPromise promise = anchorManager.HostCloudAnchorAsync(localAnchor, 1);
        if (promise == null)
        {
            Debug.LogError("클라우드 앵커 호스팅 실패");

            popupText.text = "클라우드 앵커를 생성하지 못했습니다.";
            okButton.gameObject.SetActive(true);

            yield break;
        }

        while (promise.State == PromiseState.Pending)
        {
            yield return null;
        }

        HostCloudAnchorResult result = promise.Result;

        if (result.CloudAnchorState == CloudAnchorState.Success)
        {
            string cloudAnchorId = result.CloudAnchorId;

            Debug.Log($"클라우드 앵커 생성 성공: ID = {cloudAnchorId}");

            popupText.text = "클라우드 앵커를 생성하였습니다.";
            okButton.gameObject.SetActive(true);

            SaveAnchorData(cloudAnchorId, scale, angle, "https://cap-areum.s3.ap-northeast-2.amazonaws.com/models/Dv9_fHKTiCK8Cs4I9ndVAA.glb");

            mode = Mode.READY;
            isConfirmed = false;
        }
        else
        {
            Debug.LogError($"클라우드 앵커 생성 실패: {result.CloudAnchorState}");

            popupText.text = $"클라우드 앵커를 생성하지 못했습니다.\n({result.CloudAnchorState})";
            okButton.gameObject.SetActive(true);

            mode = Mode.READY;
            isConfirmed = false;
        }
    }

    private IEnumerator LoadGLBFile(string url, Action<GameObject> onLoaded)
    {
        //messageText.text = "3D 모델 로드 중";
        popupPanel.SetActive(true);
        popupText.text = "3D 모델을 불러오는 중입니다...";
        okButton.gameObject.SetActive(false);

        UnityWebRequest request = UnityWebRequest.Get(url);

        yield return request.SendWebRequest();

        popupPanel.SetActive(false);

        if (request.result == UnityWebRequest.Result.Success)
        {
            byte[] glbData = request.downloadHandler.data;

            // GLB 데이터 로드 (GLTF/GLB 라이브러리 사용 필요)
            GameObject loadedObject = ImportGLB(glbData);

            if (loadedObject != null)
            {
                headText.text = "     위치, 크기, 각도를 조정한 후 완료 버튼을 눌러주세요.";
                headText.fontSize = 40;
                Debug.Log($"GLB 파일 로드 성공: {url}");
                onLoaded.Invoke(loadedObject);
            }
            else
            {
                //messageText.text = "3D 모델 로드 실패";
                popupPanel.SetActive(true);
                popupText.text = "3D 모델을 불러오는 데 실패했습니다.";
                okButton.gameObject.SetActive(true);

                Debug.LogError($"GLB 파일 로드 실패: {url}");
            }
        }
        else
        {
            //messageText.text = "3D 모델 로드 실패";
            popupPanel.SetActive(true);
            popupText.text = $"3D 모델을 불러오는 데 실패했습니다.\n{request.error}";
            okButton.gameObject.SetActive(true);
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

    private void SaveAnchorData(string cloudAnchorId, float scale, float rotationY, string glbFilePath)
    {
        AnchorData data = new AnchorData(scale, rotationY, glbFilePath);
        anchorDataMap[cloudAnchorId] = data;

        // SerializableDictionary로 변환
        SerializableDictionary<string, AnchorData> serializableData = new SerializableDictionary<string, AnchorData>();
        serializableData.FromDictionary(anchorDataMap);

        // JSON 직렬화 후 저장
        string json = JsonUtility.ToJson(serializableData);
        PlayerPrefs.SetString("AnchorDataMap", json);
        PlayerPrefs.Save();

        Debug.Log($"AnchorData 저장 완료: ID={cloudAnchorId}, Scale={scale}, RotationY={rotationY}, GLB Path={glbFilePath}");
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
