using System.Collections;
using System.Collections.Generic;
using Newtonsoft.Json;
using TMPro;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;

public class StatPlaceManager : MonoBehaviour
{
    private string apiUrl = "http://ec2-43-200-16-231.ap-northeast-2.compute.amazonaws.com/stats/locations";

    public RectTransform panelContainer;          // 그래프를 표시할 전체 부모 패널 (Panel)
    public List<GameObject> barPrefabs;           // 막대로 사용할 6개의 색상이 다른 Prefab 목록 (Prefab 6개)
    public float totalWidth = 800f;
    private float barWidth = 100f;                // 막대의 폭
    private float graphHeight = 1300f;            // 그래프의 최대 높이

    void Start()
    {
        StartCoroutine(SendStatPlaceRequest());
    }

    IEnumerator SendStatPlaceRequest()
    {
        UnityWebRequest request = UnityWebRequest.Get(apiUrl);
        yield return request.SendWebRequest();

        if (request.result == UnityWebRequest.Result.Success)
        {
            string json = request.downloadHandler.text;
            List<StatPlaceItem> items = JsonConvert.DeserializeObject<List<StatPlaceItem>>(json);

            if (items.Count != 6)
            {
                Debug.LogError("API 응답의 배열 원소 갯수가 6개가 아닙니다.");
                yield break;
            }

            DrawBarChart(items);
        }
        else
        {
            Debug.LogError("API 호출 실패: " + request.error);
        }
    }

    void DrawBarChart(List<StatPlaceItem> items)
    {
        // 최대 count 값을 구합니다.
        float maxCount = 0;
        foreach (var item in items)
        {
            if (item.count > maxCount) maxCount = item.count;
        }

        // "기타" 항목을 마지막으로 이동
        List<StatPlaceItem> sortedItems = new List<StatPlaceItem>();
        StatPlaceItem 기타Item = null;

        foreach (var item in items)
        {
            if (string.IsNullOrEmpty(item.location))
            {
                기타Item = item; // "기타"로 처리할 항목 저장
            }
            else
            {
                sortedItems.Add(item); // 나머지 항목 추가
            }
        }

        // "기타"를 리스트 맨 뒤에 추가
        if (기타Item != null)
        {
            sortedItems.Add(기타Item);
        }

        // 막대 그래프 생성
        for (int i = 0; i < sortedItems.Count; i++)
        {
            StatPlaceItem statPlaceItem = sortedItems[i];

            // 해당 색상의 Prefab 선택
            GameObject barPrefab = barPrefabs[i % barPrefabs.Count];

            // 막대 생성
            GameObject graphContainer = Instantiate(barPrefab, panelContainer);
            RectTransform rectTransform = graphContainer.GetComponent<RectTransform>();

            RawImage barImage = graphContainer.transform.Find("BarImage").GetComponent<RawImage>();
            RectTransform barRectTransform = barImage.GetComponent<RectTransform>();

            // 막대 높이 계산 및 적용
            float normalizedHeight = (statPlaceItem.count / maxCount) * graphHeight;
            barRectTransform.sizeDelta = new Vector2(barWidth, normalizedHeight);

            // 라벨 설정 (장소 및 Count)
            TextMeshProUGUI placeLabel = graphContainer.transform.Find("PlaceLabel").GetComponent<TextMeshProUGUI>();
            if (string.IsNullOrEmpty(statPlaceItem.location))
            {
                placeLabel.text = "기타";
            }
            else
            {
                placeLabel.text = statPlaceItem.location;
            }

            TextMeshProUGUI countLabel = graphContainer.transform.Find("CountLabel").GetComponent<TextMeshProUGUI>();
            countLabel.text = $"{statPlaceItem.count}";
        }
    }
}