using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;

// Google ARCore Extensions
using Google.XR.ARCoreExtensions;
using System;

public class CloudAnchorManager : MonoBehaviour
{
    // 상태 변수
    public enum Mode { READY, HOST, HOST_PENDING, RESOLVE, RESOLVE_PENDING };
    
    // 버튼
    public Button hostButton;       // 클라우드 앵커 등록
    public Button resolveButton;    // 클라우드 앵커 조회
    public Button resetButton;      // 리셋

    // 메시지 출력 텍스트
    public Text messageText;

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

    void Start()
    {
        // 버튼 이벤트 연결
        hostButton.onClick.AddListener(() => OnHostClick());
        resolveButton.onClick.AddListener(() => OnResolveClick());
        resetButton.onClick.AddListener(() => OnResetClick());

        strCloudAnchorId = PlayerPrefs.GetString(cloudAnchorKey, "");
    }

    void Update()
    {
        if (mode == Mode.HOST)
        {
            Hosting();
            //HostProcessing();
        }
        /*if (mode == Mode.HOST_PENDING)
        {
            HostPending();
        }*/
        if (mode == Mode.RESOLVE)
        {
            Resolving();
        }
        /*if (mode == Mode.RESOLVE_PENDING)
        {
            ResolvePending();
        }*/

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
                // 로컬 앵커를 생성
                localAnchor = anchorManager.AddAnchor(hits[0].pose);
                // 로컬 앵커 위치에 증강시키고 변수에 저장
                anchorGameObject = Instantiate(anchorPrefab, localAnchor.transform);
                Debug.Log("로컬 앵커 생성 완료");
                
                // 클라우드 앵커 생성 시작
                HostCloudAnchor();
                mode = Mode.HOST_PENDING; // 중복 터치 방지
            }
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

            // ID 저장 (예: PlayerPrefs 사용)
            PlayerPrefs.SetString("CLOUD_ANCHOR_ID", strCloudAnchorId);
            PlayerPrefs.Save(); // 강제 저장

            // 초기화
            //cloudAnchor = null;
            // 기존에 증강된 객체를 삭제
            //Destroy(anchorGameObject);

            mode = Mode.READY;
        }
        else
        {
            Debug.LogError($"클라우드 앵커 생성 실패: {result.CloudAnchorState}");

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


    void Resolving()
    {
        // 중복 호출 방지
        if (mode != Mode.RESOLVE) return;

        // cloudAnchorKey가 존재하지 않을 경우
        if (!PlayerPrefs.HasKey(cloudAnchorKey))
        {
            Debug.LogError("저장된 클라우드 앵커 키가 없습니다.");
            mode = Mode.READY; // 상태 초기화
            return;
        }
        //messageText.text = "";

        // 클라우드 앵커 ID 가져오기
        strCloudAnchorId = PlayerPrefs.GetString(cloudAnchorKey, "");
        if (string.IsNullOrEmpty(strCloudAnchorId))
        {
            Debug.LogError("클라우드 앵커 ID가 없습니다.");
            mode = Mode.READY; // 상태 초기화
            return;
        }

        // 클라우드 앵커 ID 받아옴. (포톤, 파이어베이스)
        //strCloudAnchorId = PlayerPrefs.GetString(cloudAnchorKey); //이게 있어야 하는건가 아래 함수 안에거가 있어야 하는건가

        ResolveCloudAnchor();
        mode = Mode.RESOLVE_PENDING; // 리졸빙 진행 중으로 상태 변경
    }

    // 클라우드 앵커 리졸빙
    public void ResolveCloudAnchor()
    {
        if (isResolving)
        {
            Debug.LogWarning("이미 리졸빙 작업이 진행 중입니다.");
            return;
        }
        
        // anchorManager가 null인지 확인
        if (anchorManager == null)
        {
            Debug.LogError("ARAnchorManager가 초기화되지 않았습니다.");
            mode = Mode.READY; // 상태 초기화
            return;
        }

        strCloudAnchorId = PlayerPrefs.GetString("CLOUD_ANCHOR_ID", "");
        if (string.IsNullOrEmpty(strCloudAnchorId))
        {
            Debug.LogError("저장된 클라우드 앵커 ID가 없습니다.");
            mode = Mode.READY; // 상태 초기화
            return;
        }

        // ResolveCloudAnchorPromise 반환
        ResolveCloudAnchorPromise promise = anchorManager.ResolveCloudAnchorAsync(strCloudAnchorId);
        if (promise == null)
        {
            Debug.LogError("클라우드 앵커 리졸빙 요청 실패");
            mode = Mode.READY; // 상태 초기화
            return;
        }

        StartCoroutine(ResolveCloudAnchorCoroutine(promise));
    }

    private IEnumerator ResolveCloudAnchorCoroutine(ResolveCloudAnchorPromise promise)
    {
        // 중복 호출 방지
        if (isResolving)
        {
            Debug.LogWarning("이미 리졸빙 작업이 진행 중입니다.");
            yield break;
        }

        isResolving = true; // 리졸빙 시작
        Debug.Log("클라우드 앵커 리졸빙 시작");

        float checkInterval = 1f; // 1초 간격으로 상태 확인
        float timeout = 30f; // 최대 30초 대기
        float elapsedTime = 0f;

        while (promise.State == PromiseState.Pending && elapsedTime < timeout)
        {
            yield return new WaitForSeconds(checkInterval);
            elapsedTime += checkInterval;
        }

        // 리졸빙 타임아웃 처리
        if (promise.State == PromiseState.Pending)
        {
            Debug.LogError("클라우드 앵커 리졸빙 타임아웃");
            mode = Mode.READY;
            isResolving = false; // 작업 종료 플래그 해제
            yield break;
        }

        // 리졸빙 결과 확인
        ResolveCloudAnchorResult result = promise.Result;

        if (result.CloudAnchorState == CloudAnchorState.Success)
        {
            Debug.Log($"클라우드 앵커 리졸빙 성공: ID = {strCloudAnchorId}");

            // 리졸빙된 앵커에서 필요한 작업 수행 (예: 오브젝트 생성)
            var resolvedAnchor = result.Anchor;
            if (resolvedAnchor != null)
            {
                anchorGameObject = Instantiate(anchorPrefab, resolvedAnchor.transform);
                Debug.Log("증강 오브젝트 생성 완료");
            }
            else
            {
                Debug.LogError("리졸빙된 앵커가 null입니다.");
            }
        }
        else
        {
            Debug.LogError($"클라우드 앵커 리졸빙 실패: {result.CloudAnchorState}");
            
        }
        isResolving = false; // 작업 종료 플래그 해제
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
            Debug.Log("Resolving 시작");
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

        // 상태 초기화
        Debug.Log("Reset 완료");
        mode = Mode.READY;
    }
}