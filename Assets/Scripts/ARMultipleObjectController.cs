using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;

public class ARMultipleObjectController : MonoBehaviour
{
    [SerializeField]
    ARRaycastManager aRRaycastManager;

    GameObject selectedPrefab;

    private static List<ARRaycastHit> hits = new List<ARRaycastHit>();

    public void SetSelectedPrefab(GameObject selectedPrefab){
        this.selectedPrefab = selectedPrefab;
    }

    private void Awake(){
        selectedPrefab = aRRaycastManager.raycastPrefab;
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.touchCount == 0)
        {
            return;
        }

        Touch touch = Input.GetTouch(0);
        Vector2 touchPosition = touch.position;


        if (isPointOverUIObject(touchPosition))
        {
            return;
        }

        // 처음 터치된 부분이 plane이라면 거기에 ray를 쏘고 탐지된 객체를 hits에 저장
        if (aRRaycastManager.Raycast(touchPosition, hits, TrackableType.PlaneWithinPolygon))
        {
            Pose hitPose = hits[0].pose; // 첫번째로 충돌이 일어난 위치
            Instantiate(selectedPrefab, hitPose.position, hitPose.rotation);    // 에디터에서 raycastPrefab에 등록된 프리팹을 인스턴스화하여 배치  
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
