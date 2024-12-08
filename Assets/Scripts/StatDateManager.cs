using System.Collections;
using System.Collections.Generic;
using Newtonsoft.Json;
using TMPro;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;

public class StatDateManager : MonoBehaviour
{   
    private string statDateUrl = "http://ec2-43-200-16-231.ap-northeast-2.compute.amazonaws.com/stats/albums";

    public RectTransform panelContainer;  // 그래프를 표시할 전체 부모 패널 (Panel)
    public GameObject graphContainerPrefab;  // 그래프 컨테이너 프리팹
    public float totalWidth = 800f;
    private float barWidth;  // 막대의 폭
    private float graphHeight = 1300f;  // 그래프의 최대 높이

    void Start()
    {
        StartCoroutine(SendStatDateRequest());
    }

    IEnumerator SendStatDateRequest()
    {
        UnityWebRequest request = UnityWebRequest.Get(statDateUrl);

        yield return request.SendWebRequest();  // 응답이 올 때까지 대기함

        if (request.result == UnityWebRequest.Result.Success)
        {
            string jsonResponse = request.downloadHandler.text;
            List<StatDateItem> statDateItems = JsonConvert.DeserializeObject<List<StatDateItem>>(jsonResponse);

            DisplayGraph(statDateItems);
        }
        else
        {
            Debug.LogError("API 호출 실패: " + request.error);
        }
    }

    void DisplayGraph(List<StatDateItem> statDateItems)
    {
        // 최대 count 값을 구합니다.
        float maxCount = 0;
        foreach (var item in statDateItems)
        {
            if (item.count > maxCount) maxCount = item.count;
        }

        // 패널 높이를 가져옵니다.
        float panelHeight = graphHeight;

        // 막대 폭 설정
        barWidth = totalWidth / statDateItems.Count;

        foreach (StatDateItem statDateItem in statDateItems)
        {
            GameObject graphContainer = Instantiate(graphContainerPrefab, panelContainer);
            RectTransform rectTransform = graphContainer.GetComponent<RectTransform>();

            RawImage barImage = graphContainer.transform.Find("BarImage").GetComponent<RawImage>();
            RectTransform barRectTransform = barImage.GetComponent<RectTransform>();

            // 최대값 대비 현재 값의 비율을 이용해 막대 높이를 결정
            float normalizedHeight = (statDateItem.count / maxCount) * panelHeight;
            barRectTransform.sizeDelta = new Vector2(barWidth, normalizedHeight);

            TextMeshProUGUI dateText = graphContainer.transform.Find("DateLabel").GetComponent<TextMeshProUGUI>();
            dateText.text = statDateItem.date;

            TextMeshProUGUI countText = graphContainer.transform.Find("CountLabel").GetComponent<TextMeshProUGUI>();
            countText.text = $"{statDateItem.count}";
        }
    }
}