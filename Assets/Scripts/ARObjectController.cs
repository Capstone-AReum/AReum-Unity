using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UIElements;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;

public class ARObjectController : MonoBehaviour
{
    private ARRaycastManager aRRaycastManager;
    private List<ARRaycastHit> hits = new List<ARRaycastHit>();

    private GameObject arObject;

    private float scale = 1.0f;
    private float angle = 0.0f;

    private void Awake() {
        aRRaycastManager = GetComponent<ARRaycastManager>();
    }

    public void UpdateScale(float sliderValue){
        scale = sliderValue;

        if(arObject){
            // localScale 값은 vector3이므로 바로 float 할당 불가능 -> [1,1,1] vector에 scale 곱해서 전체 스케일링
            arObject.transform.localScale = Vector3.one * scale;
        }
    }

    public void UpdateRotation(float sliderValue)
    {
        angle = sliderValue;

        if (arObject)
        {
            // Vector3.up == [0,1,0] == y축
            //arObject.transform.localRotation = Quaternion.AngleAxis(angle, Vector3.up); // y축을 고정해놓고 좌우로 회전시킴
            //OR
            arObject.transform.localRotation = Quaternion.Euler(new Vector3(0, angle, 0));  // min=0, max=360으로 해야함
        }
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.touchCount == 0){
            return;
        }

        Touch touch = Input.GetTouch(0);
        Vector2 touchPosition = touch.position;

        if(isPointOverUIObject(touchPosition)){
            return ;
        }

        // 처음 터치된 부분이 plane이라면 거기에 ray를 쏘고 탐지된 객체를 hits에 저장
        if (aRRaycastManager.Raycast(touchPosition, hits, TrackableType.PlaneWithinPolygon)){
            var hitPose = hits[0].pose; // 첫번째로 충돌이 일어난 위치

            if(!arObject){
                arObject = Instantiate(aRRaycastManager.raycastPrefab, hitPose.position, hitPose.rotation);    // 에디터에서 raycastPrefab에 등록된 프리팹을 인스턴스화하여 배치  

                arObject.transform.localScale = Vector3.one * scale;
                arObject.transform.localRotation = Quaternion.Euler(new Vector3(0, angle, 0));
            }
            else{  // 한 번 이상 터치가 일어났으면 새로 인스턴스 생성하지 않고, 위치만 이동
                arObject.transform.position = hitPose.position;
                arObject.transform.rotation = hitPose.rotation;
            }
        }
    }

    // UI 터치는 AR 상의 터치로 인식되지 않게 하기 위한 함수
    // ray를 먼저 쏴보고 부딪힌 뭔가가 있으면 RaycastManager을 쏘지 않음
    bool isPointOverUIObject(Vector2 pos){
        PointerEventData eventDataCurPosition = new PointerEventData(EventSystem.current);
        eventDataCurPosition.position = pos;
        List<RaycastResult> results = new List<RaycastResult>();
        EventSystem.current.RaycastAll(eventDataCurPosition, results);
        return results.Count > 0;
    }
}
