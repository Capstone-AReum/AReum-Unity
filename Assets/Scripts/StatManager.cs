using System.Collections;
using System.Collections.Generic;
using Newtonsoft.Json;
using TMPro;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;

public class StatManager : MonoBehaviour
{
    private string statDateUrl = "http://ec2-43-200-16-231.ap-northeast-2.compute.amazonaws.com/stats/albums";

    public RectTransform panelContainer;  // 그래프를 표시할 전체 부모 패널 (Panel)
    public GameObject graphContainerPrefab;  // 그래프 컨테이너 프리팹
    public float totalWidth = 700f;
    private float barWidth;  // 막대의 폭
    private float graphHeight = 800f;  // 그래프의 최대 높이

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
            Debug.LogError("실패: " + request.error);
        }
    }

    void DisplayGraph(List<StatDateItem> statDateItems)
    {
        barWidth = totalWidth / statDateItems.Count;    // 유동적으로 조정되도록

        foreach (StatDateItem statDateItem in statDateItems)
        {
            // 그래프 컨테이너 생성
            GameObject graphContainer = Instantiate(graphContainerPrefab, panelContainer);
            RectTransform rectTransform = graphContainer.GetComponent<RectTransform>();

            // 막대 그래프 설정 (사각형 이미지)
            RawImage barImage = graphContainer.transform.Find("BarImage").GetComponent<RawImage>();
            RectTransform barRectTransform = barImage.GetComponent<RectTransform>();
            barRectTransform.sizeDelta = new Vector2(barWidth, statDateItem.count * graphHeight / 10);  // 세로축 스케일링

            // 날짜 텍스트 설정 (TextMeshProUGUI)
            TextMeshProUGUI dateText = graphContainer.transform.Find("DateLabel").GetComponent<TextMeshProUGUI>();
            dateText.text = statDateItem.date;
        }
    }
}