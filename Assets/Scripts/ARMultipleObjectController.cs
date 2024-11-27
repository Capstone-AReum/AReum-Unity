using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;
using System.IO;

public class ARMultipleObjectController : MonoBehaviour
{
    [SerializeField]
    ARRaycastManager aRRaycastManager;

    [SerializeField]
    ARAnchorManager aRAnchorManager;

    [SerializeField]
    ARPlaneManager aRPlaneManager;

    GameObject selectedPrefab;

    private static List<ARRaycastHit> hits = new List<ARRaycastHit>();

    // 물체 위치를 저장할 리스트
    private ObjectDataList savedObjects = new ObjectDataList();

    public void SetSelectedPrefab(GameObject selectedPrefab){
        this.selectedPrefab = selectedPrefab;
    }

    private void Awake(){
        selectedPrefab = aRRaycastManager.raycastPrefab;

        // 기존 위치 불러오기
        LoadObjectPositions();
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

        //디버깅용
        /*string filePath = Application.persistentDataPath + "/SavedObjects.json";
        Debug.Log($"Saved JSON Path: {filePath}");*/

        if (isPointOverUIObject(touchPosition))
        {
            return;
        }

        // 처음 터치된 부분이 plane이라면 거기에 ray를 쏘고 탐지된 객체를 hits에 저장
        if (aRRaycastManager.Raycast(touchPosition, hits, TrackableType.PlaneWithinPolygon))
        {
            Debug.Log("Raycast hit detected!");
            Pose hitPose = hits[0].pose; // 첫번째로 충돌이 일어난 위치

            // 감지된 평면 가져오기
            ARPlane plane = aRPlaneManager.GetPlane(hits[0].trackableId);
            if (plane == null)
            {
                Debug.LogWarning("No plane found for the hit.");
                return;
            }

            // 평면에 앵커 추가
            ARAnchor anchor = plane.gameObject.AddComponent<ARAnchor>();
            if (anchor == null)
            {
                Debug.LogError("Failed to create anchor.");
                return;
            }

            // 앵커에 3D 객체 배치
            GameObject obj = Instantiate(selectedPrefab, anchor.transform.position, anchor.transform.rotation, anchor.transform);    // 에디터에서 raycastPrefab에 등록된 프리팹을 인스턴스화하여 배치  

            // 위치 저장
            SaveObjectPosition(anchor);
        }
        else
        {
            Debug.LogWarning("No Raycast hit detected. Unable to create anchor.");
            return;
        }
    }

    // 물체 위치 및 앵커 ID 저장
    void SaveObjectPosition(ARAnchor anchor)
    {
        ObjectData data = new ObjectData
        {
            position = anchor.transform.position,
            rotation = anchor.transform.rotation,
            anchorId = anchor.trackableId.ToString() // 앵커의 고유 ID 저장
        };
        savedObjects.objects.Add(data);

        // 저장된 데이터를 JSON으로 변환하여 파일로 저장
        string json = JsonUtility.ToJson(savedObjects);
        File.WriteAllText(Application.persistentDataPath + "/SavedObjects.json", json);

        Debug.Log($"Anchor saved with ID: {data.anchorId}");
    }

    // 저장된 위치 및 앵커 복원
    void LoadObjectPositions()
    {
        string path = Application.persistentDataPath + "/SavedObjects.json";
        if (File.Exists(path))
        {
            string json = File.ReadAllText(path);

            // 디버깅용
            Debug.Log($"Loaded JSON Data: {json}");

            savedObjects = JsonUtility.FromJson<ObjectDataList>(json);

            // 저장된 위치에 물체 및 앵커 재배치
            foreach (var data in savedObjects.objects)
            {
                Pose anchorPose = new Pose(data.position, data.rotation);

                // 새로 추가된 평면에 앵커 복원
                ARAnchor anchor = new GameObject("RestoredAnchor").AddComponent<ARAnchor>();
                anchor.transform.position = anchorPose.position;
                anchor.transform.rotation = anchorPose.rotation;

                if (anchor != null)
                {
                    Instantiate(selectedPrefab, anchor.transform.position, anchor.transform.rotation, anchor.transform);
                    Debug.Log($"Restored object with Anchor ID: {data.anchorId}");
                }
                else
                {
                    Debug.LogWarning($"Failed to restore anchor at position: {data.position}");
                }
            }
        }
        else
        {
            Debug.LogWarning("No saved objects to load.");
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

[System.Serializable]
public class ObjectData
{
    public Vector3 position;      // 위치
    public Quaternion rotation;  // 회전
    public string anchorId;      // 앵커 고유 ID
}

[System.Serializable]
public class ObjectDataList
{
    public List<ObjectData> objects = new List<ObjectData>();
}