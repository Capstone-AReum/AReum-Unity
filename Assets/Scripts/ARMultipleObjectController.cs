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
            Pose hitPose = hits[0].pose; // 첫번째로 충돌이 일어난 위치
            
            // 새 물체 배치
            GameObject obj = Instantiate(selectedPrefab, hitPose.position, hitPose.rotation);    // 에디터에서 raycastPrefab에 등록된 프리팹을 인스턴스화하여 배치  

            // 위치 저장
            SaveObjectPosition(obj.transform);
        }
    }

    // 물체 위치를 저장
    void SaveObjectPosition(Transform objTransform)
    {
        ObjectData data = new ObjectData
        {
            position = objTransform.position,
            rotation = objTransform.rotation
        };
        savedObjects.objects.Add(data);

        // 저장된 데이터를 JSON으로 변환하여 파일로 저장
        string json = JsonUtility.ToJson(savedObjects);
        File.WriteAllText(Application.persistentDataPath + "/SavedObjects.json", json);
    }

    // 저장된 위치 불러오기
    void LoadObjectPositions()
    {
        string path = Application.persistentDataPath + "/SavedObjects.json";
        if (File.Exists(path))
        {
            string json = File.ReadAllText(path);

            //디버깅용
            Debug.Log($"Loaded JSON Data: {json}");

            savedObjects = JsonUtility.FromJson<ObjectDataList>(json);

            // 저장된 위치에 물체 재배치
            foreach (var data in savedObjects.objects)
            {
                // 디버깅용
                Debug.Log($"Restoring Object at Position: {data.position}, Rotation: {data.rotation}");
                Instantiate(selectedPrefab, data.position, data.rotation);
            }
        }else{ //디버깅용
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
    public Vector3 position;
    public Quaternion rotation;
}

[System.Serializable]
public class ObjectDataList
{
    public List<ObjectData> objects = new List<ObjectData>();
}