using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;

// Google ARCore Extensions
using Google.XR.ARCoreExtensions;
using System;
using TMPro;

public class CloudAnchorManager : MonoBehaviour
{
    // 상태 변수
    public enum Mode { READY, HOST, HOST_PENDING, RESOLVE, RESOLVE_PENDING };
    
    // 버튼
    public Button hostButton;       // 클라우드 앵커 등록
    public Button resolveButton;    // 클라우드 앵커 조회
    public Button resetButton;      // 리셋
    public Button confirmButton;

    // 메시지 출력 텍스트
    public TextMeshProUGUI messageText;

    // 상태변수
    public Mode mode = Mode.READY;
    // AnchorManager    // 로컬 앵커를 생성하기 위한 클래스
    public ARAnchorManager anchorManager;
    // ArRaycastManager
    public ARRaycastManager raycastManager;

    // 증강시킬 객체 프리팹
    public GameObject anchorPrefab;
    // 저장 객체 변수 (삭제하기 위한 용도)
    private GameObject anchorGameObject;

    // 로컬앵커 저장 변수
    private ARAnchor localAnchor;
    // 클라우드 앵커 변수
    private ARCloudAnchor cloudAnchor;


    // Raycast Hit
    private List<ARRaycastHit> hits = new List<ARRaycastHit>();

    // 클라우드 앵커 ID 저장하기 위한 키 값 (PlayerPregs.SetString("키", 값));
    private const string cloudAnchorKey = "CLOUD_ANCHOR_ID";
    // 클라우드 앵커 ID
    private string strCloudAnchorId;

    private bool isResolving = false; // 리졸빙 중 여부를 추적
    private bool isConfirmed = false;
    
    private float scale = 1.0f;
    private float angle = 0.0f;

    private List<string> cloudAnchorIds = new List<string>(); // Cloud Anchor ID 리스트
    private const string cloudAnchorListKey = "CLOUD_ANCHOR_IDS";

    // Cloud Anchor ID 저장
    private void SaveCloudAnchorId(string id)
    {
        // 기존 ID 로드
        LoadCloudAnchorIds();

        // 새 ID 추가
        if (!cloudAnchorIds.Contains(id))
        {
            cloudAnchorIds.Add(id);
        }

        string json = JsonUtility.ToJson(new SerializableList<string>(cloudAnchorIds));
        PlayerPrefs.SetString(cloudAnchorListKey, json);
        PlayerPrefs.Save();
        Debug.Log($"Cloud Anchor ID 저장 완료: {id}");
    }

    // Cloud Anchor ID 불러오기
    private void LoadCloudAnchorIds()
    {
        if (PlayerPrefs.HasKey(cloudAnchorListKey))
        {
            string json = PlayerPrefs.GetString(cloudAnchorListKey);
            Debug.Log($"로드된 JSON 데이터: {json}");

            cloudAnchorIds = JsonUtility.FromJson<SerializableList<string>>(json).ToList();
        }
        else
        {
            cloudAnchorIds = new List<string>();
        }

        Debug.Log($"로드된 Cloud Anchor ID 개수: {cloudAnchorIds.Count}");
        foreach (var id in cloudAnchorIds)
        {
            Debug.Log($"로드된 ID: {id}");
        }
    }

    void Start()
    {
        // 버튼 이벤트 연결
        hostButton.onClick.AddListener(() => OnHostClick());
        resolveButton.onClick.AddListener(() => OnResolveClick());
        resetButton.onClick.AddListener(() => OnResetClick());
        confirmButton.onClick.AddListener(() => OnConfirmClick());

        strCloudAnchorId = PlayerPrefs.GetString(cloudAnchorKey, "");

        messageText.text = "시작";
    }

    void Update()
    {
        if (mode == Mode.HOST && !isConfirmed)
        {
            UpdateLocalAnchorPosition();
            //HostProcessing();
        }
        if (mode == Mode.RESOLVE)
        {
            ResolveAllCloudAnchors();
        }

    }

    private void UpdateLocalAnchorPosition()
    {
        if (Input.touchCount < 1) return;

        Touch touch = Input.GetTouch(0);
        if (touch.phase != TouchPhase.Began) return;

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
            anchorGameObject = Instantiate(anchorPrefab, localAnchor.transform);
            
            Debug.Log("로컬 앵커 위치 업데이트 완료");
        }
    }

    public void UpdateScale(float sliderValue)
    {
        scale = sliderValue;
        Debug.Log($"Scale 슬라이더 값: {sliderValue}");

        if (anchorGameObject)
        {
            anchorGameObject.transform.localScale = Vector3.one * scale;
        }
        else
        {
            Debug.LogError("anchorGameObject가 null입니다.");
        }
    }

    public void UpdateRotation(float sliderValue)
    {
        angle = sliderValue;
        Debug.Log($"Rotation 슬라이더 값: {sliderValue}");

        if (anchorGameObject)
        {
            anchorGameObject.transform.localRotation = Quaternion.Euler(new Vector3(0, angle, 0));  // min=0, max=360으로 해야함
        }
        else
        {
            Debug.LogError("anchorGameObject가 null입니다.");
        }
    }

    void Hosting()
    {
        if (Input.touchCount < 1) return;

        Touch touch = Input.GetTouch(0);
        if (touch.phase != TouchPhase.Began) return;


        // 로컬 앵커가 존재하는지 여부를 확인
        if (localAnchor == null)
        {
            // Raycast 발사
            if (raycastManager.Raycast(touch.position, hits, TrackableType.PlaneWithinPolygon))
            {
                var hitPose = hits[0].pose; // 첫번째로 충돌이 일어난 위치

                // 로컬 앵커를 생성
                localAnchor = anchorManager.AddAnchor(hitPose);
                // 로컬 앵커 위치에 증강시키고 변수에 저장
                anchorGameObject = Instantiate(anchorPrefab, localAnchor.transform);
                Debug.Log("로컬 앵커 생성 완료");
                
                // 클라우드 앵커 생성 시작
                HostCloudAnchor();
                mode = Mode.HOST_PENDING; // 중복 터치 방지
            }
        }
        else{
            Debug.Log("로컬 앵커가 이미 있음");
        }
    }

    private void HostCloudAnchor()
    {
        // 클라우드 앵커 호스팅
        HostCloudAnchorPromise promise = anchorManager.HostCloudAnchorAsync(localAnchor, 1);

        if (promise == null)
        {
            Debug.LogError("클라우드 앵커 호스팅 실패");
            return;
        }
        messageText.text = "클라우드 앵커 생성중";
        StartCoroutine(HostCloudAnchorCoroutine(promise));
    }

    private IEnumerator HostCloudAnchorCoroutine(HostCloudAnchorPromise promise)
    {
        while (promise.State == PromiseState.Pending)
        {
            yield return null; // 대기
        }

        // 호스팅 결과 확인
        HostCloudAnchorResult result = promise.Result;

        if (result.CloudAnchorState == CloudAnchorState.Success)
        {
            strCloudAnchorId = result.CloudAnchorId;
            Debug.Log($"클라우드 앵커 생성 성공: ID = {strCloudAnchorId}");
            messageText.text = "클라우드 앵커 생성 성공";

            // ID 저장 (예: PlayerPrefs 사용)
            /*PlayerPrefs.SetString("CLOUD_ANCHOR_ID", strCloudAnchorId);
            PlayerPrefs.Save(); // 강제 저장*/
            // ID 리스트에 추가 및 저장
            SaveCloudAnchorId(strCloudAnchorId);

            // 초기화
            //cloudAnchor = null;
            // 기존에 증강된 객체를 삭제
            //Destroy(anchorGameObject);

            mode = Mode.READY;
        }
        else
        {
            Debug.LogError($"클라우드 앵커 생성 실패: {result.CloudAnchorState}");
            messageText.text = "클라우드 앵커 생성 실패";

            // 에러 발생 시 모드를 READY로 초기화하여 중복 요청 방지
            mode = Mode.READY;

            // 에러 종류에 따라 추가 로직 (예: 사용자 알림)
            if (result.CloudAnchorState == CloudAnchorState.ErrorResourceExhausted)
            {
                Debug.LogError("리소스 초과: API 요청 한도 초과. 하루 할당량을 확인하세요.");
            }
            else if (result.CloudAnchorState == CloudAnchorState.ErrorInternal)
            {
                Debug.LogError("클라우드 앵커 생성 중 내부 에러 발생.ARCore 설정을 확인하세요.");
            }
            else
            {
                Debug.LogError("클라우드 앵커 생성 중 내부 에러 제외 다른 에러 발생.");
            }
        }
    }


    public void ResolveAllCloudAnchors()
    {
        if (isResolving)
        {
            //Debug.LogWarning("리졸빙 작업이 이미 진행 중입니다.");
            return;
        }

        LoadCloudAnchorIds();

        if (cloudAnchorIds.Count == 0)
        {
            Debug.LogError("저장된 Cloud Anchor ID가 없습니다.");
            messageText.text = "저장된 클라우드 앵커가 없음";
            return;
        }

        Debug.Log($"총 {cloudAnchorIds.Count}개의 Cloud Anchor를 리졸빙 시작합니다.");
        //mode = Mode.RESOLVE_PENDING;
        StartCoroutine(ResolveAllCloudAnchorsCoroutine());
    }

    private IEnumerator ResolveAllCloudAnchorsCoroutine()
    {
        isResolving = true;

        foreach (string cloudAnchorId in cloudAnchorIds)
        {
            Debug.Log($"클라우드 앵커 리졸빙 시작: ID = {cloudAnchorId}");
            messageText.text = $"클라우드 앵커 리졸빙 시작: ID = {cloudAnchorId}";
            ResolveCloudAnchorPromise promise = anchorManager.ResolveCloudAnchorAsync(cloudAnchorId);

            if (promise == null)
            {
                Debug.LogError($"클라우드 앵커 리졸빙 요청 실패: ID = {cloudAnchorId}");
                messageText.text = $"클라우드 앵커 리졸빙 요청 실패: ID = {cloudAnchorId}";
                continue;
            }

            float timeout = 30f;
            float elapsedTime = 0f;
            while (promise.State == PromiseState.Pending && elapsedTime < timeout)
            {
                yield return new WaitForSeconds(1f);
                elapsedTime += 1f;
            }

            // 리졸빙 결과 확인
            if (promise.State == PromiseState.Pending)
            {
                Debug.LogError($"클라우드 앵커 리졸빙 타임아웃: ID = {cloudAnchorId}");
                messageText.text = $"클라우드 앵커 리졸빙 타임아웃: ID = {cloudAnchorId}";
                continue;
            }

            ResolveCloudAnchorResult result = promise.Result;

            if (result.CloudAnchorState == CloudAnchorState.Success)
            {
                Debug.Log($"클라우드 앵커 리졸빙 성공: ID = {cloudAnchorId}");
                messageText.text = $"클라우드 앵커 리졸빙 성공: ID = {cloudAnchorId}";
                var resolvedAnchor = result.Anchor;
                if (resolvedAnchor != null)
                {
                    Instantiate(anchorPrefab, resolvedAnchor.transform.position, resolvedAnchor.transform.rotation);
                    Debug.Log($"증강 오브젝트 생성 완료: ID = {cloudAnchorId}");
                }
                else
                {
                    Debug.LogError($"리졸빙된 앵커가 null입니다: ID = {cloudAnchorId}");
                }
            }
            else
            {
                Debug.LogError($"클라우드 앵커 리졸빙 실패: ID = {cloudAnchorId}, 상태: {result.CloudAnchorState}");
                messageText.text = $"클라우드 앵커 리졸빙 실패: ID = {cloudAnchorId}, 상태: {result.CloudAnchorState}";
            }
        }

        Debug.Log("모든 클라우드 앵커 리졸빙 작업 완료");
        isResolving = false;
        mode = Mode.READY;
    }

    // MainCamera 태그로 지정된 카메라의 위치와 각도를 Pose 데이터 타입으로 반환
    public Pose GetCameraPose()
    {
        return new Pose(Camera.main.transform.position, Camera.main.transform.rotation);
    }


    private void OnHostClick()
    {
        if (mode == Mode.READY)
        {
            mode = Mode.HOST; // 상태 변경
            Debug.Log("Hosting 시작");
        }
        else
        {
            Debug.LogWarning("이미 Hosting 중입니다.");
        }
    }

    private void OnResolveClick()
    {
        if (mode == Mode.READY)
        {
            mode = Mode.RESOLVE; // 상태 변경
            Debug.Log("모든 Cloud Anchor 리졸빙 시작");
        }
        else
        {
            Debug.LogWarning("리졸빙 중에는 다른 작업을 수행할 수 없습니다.");
        }
    }

    private void OnResetClick()
    {
        // 클라우드 앵커가 null이 아닌 경우에만 해제
        if (cloudAnchor != null)
        {
            Debug.Log("클라우드 앵커 제거");
            Destroy(cloudAnchor.gameObject);
            cloudAnchor = null; // Null로 설정하여 이후 호출 방지
        }

        // 로컬 앵커가 null이 아닌 경우에만 해제
        if (localAnchor != null)
        {
            Debug.Log("로컬 앵커 제거");
            Destroy(localAnchor.gameObject);
            localAnchor = null; // Null로 설정하여 이후 호출 방지
        }

        // 앵커와 연결된 객체 삭제
        if (anchorGameObject != null)
        {
            Debug.Log("앵커 객체 제거");
            Destroy(anchorGameObject);
            anchorGameObject = null; // Null로 설정하여 이후 호출 방지
        }

        // 저장된 Cloud Anchor ID 삭제
        PlayerPrefs.DeleteKey(cloudAnchorListKey); // 저장된 ID 삭제
        PlayerPrefs.Save(); // 변경 사항 저장
        cloudAnchorIds.Clear(); // 메모리 내 리스트도 초기화
        Debug.Log("저장된 Cloud Anchor ID가 모두 삭제되었습니다.");

        // 상태 초기화
        Debug.Log("Reset 완료");
        mode = Mode.READY;
    }

    private void OnConfirmClick()
    {
        if (mode == Mode.HOST && localAnchor != null)
        {
            isConfirmed = true;
            Debug.Log("로컬 앵커 위치가 확정되었습니다.");
            StartCoroutine(StartHosting());
        }
        else
        {
            Debug.LogWarning("로컬 앵커가 없거나 Hosting 상태가 아닙니다.");
        }
    }

    private IEnumerator StartHosting()
    {
        Debug.Log("클라우드 앵커 호스팅 시작");
        messageText.text = "클라우드 앵커 생성중";

        HostCloudAnchorPromise promise = anchorManager.HostCloudAnchorAsync(localAnchor, 1);
        if (promise == null)
        {
            Debug.LogError("클라우드 앵커 호스팅 실패");
            messageText.text = "클라우드 앵커 생성 실패";
            yield break;
        }

        while (promise.State == PromiseState.Pending)
        {
            yield return null;
        }

        HostCloudAnchorResult result = promise.Result;

        if (result.CloudAnchorState == CloudAnchorState.Success)
        {
            strCloudAnchorId = result.CloudAnchorId;
            Debug.Log($"클라우드 앵커 생성 성공: ID = {strCloudAnchorId}");
            messageText.text = "클라우드 앵커 생성 성공";

            // 클라우드 앵커 ID 저장
            SaveCloudAnchorId(strCloudAnchorId);

            mode = Mode.READY;
            isConfirmed = false;
        }
        else
        {
            Debug.LogError($"클라우드 앵커 생성 실패: {result.CloudAnchorState}");
            messageText.text = $"클라우드 앵커 생성 실패: {result.CloudAnchorState}";
            mode = Mode.READY;
            isConfirmed = false;
        }
    }

    // SerializableList 클래스 (JSON 직렬화를 위한 헬퍼)
    [Serializable]
    private class SerializableList<T>
    {
        public List<T> List;
        public SerializableList(List<T> list)
        {
            List = list;
        }

        public List<T> ToList()
        {
            return List ?? new List<T>();
        }
    }
}