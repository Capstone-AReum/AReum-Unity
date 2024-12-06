using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;
using TMPro;
using Newtonsoft.Json;

public class AlbumPageManager : MonoBehaviour
{
    /*[System.Serializable]
    public class AlbumResponse
    {
        public List<ImageData> images;
        public int total_count;
        public int page;
        public int per_page;
    }

    [System.Serializable]
    public class ImageData
    {
        public int id;
        public string url;
        public string created_at;
    }

    public string albumUrl = "YOUR_API_URL_HERE"; // API URL
    public GameObject imagePrefab; // 이미지 프리팹 (RawImage 포함)
    public Transform contentContainer; // 스크롤 뷰의 콘텐츠 컨테이너
    public TextMeshProUGUI warningText; // 경고 메시지 (필요시)

    void Start()
    {
        StartCoroutine(GetAlbumData());
    }

    IEnumerator GetAlbumData()
    {
        UnityWebRequest request = UnityWebRequest.Get(albumUrl);

        yield return request.SendWebRequest();

        if (request.result == UnityWebRequest.Result.ConnectionError || request.result == UnityWebRequest.Result.ProtocolError)
        {
            Debug.LogError("API 요청 실패: " + request.error);
            if (warningText != null)
            {
                warningText.text = "앨범 데이터를 가져오는 데 실패했습니다.";
            }
        }
        else
        {
            string jsonResult = request.downloadHandler.text;

            // JSON 데이터를 파싱
            AlbumResponse albumResponse = JsonConvert.DeserializeObject<AlbumResponse>(jsonResult);
            DisplayAlbum(albumResponse);
        }
    }

    void DisplayAlbum(AlbumResponse albumResponse)
    {
        // 날짜별로 이미지를 분류하기 위해 Dictionary 사용
        Dictionary<string, List<ImageData>> dateToImagesMap = new Dictionary<string, List<ImageData>>();

        foreach (ImageData imageData in albumResponse.images)
        {
            string date = imageData.created_at.Split('T')[0]; // 날짜 부분만 추출 (YYYY-MM-DD)
            if (!dateToImagesMap.ContainsKey(date))
            {
                dateToImagesMap[date] = new List<ImageData>();
            }
            dateToImagesMap[date].Add(imageData);
        }

        // 날짜별로 이미지 그룹 생성
        foreach (var entry in dateToImagesMap)
        {
            string date = entry.Key;
            List<ImageData> images = entry.Value;

            // 날짜 레이블 생성
            GameObject dateLabel = new GameObject("DateLabel", typeof(RectTransform), typeof(TextMeshProUGUI));
            dateLabel.transform.SetParent(contentContainer, false);
            TextMeshProUGUI dateText = dateLabel.GetComponent<TextMeshProUGUI>();
            dateText.text = date;
            dateText.fontSize = 24;
            dateText.alignment = TextAlignmentOptions.Center;

            // Grid Layout Group을 가지는 새로운 이미지 그룹 컨테이너 생성
            GameObject gridContainer = new GameObject("GridContainer", typeof(RectTransform), typeof(GridLayoutGroup));
            gridContainer.transform.SetParent(contentContainer, false);
            GridLayoutGroup gridLayoutGroup = gridContainer.GetComponent<GridLayoutGroup>();

            // Grid Layout 설정
            gridLayoutGroup.cellSize = new Vector2(150, 150); // 각 이미지 셀의 크기
            gridLayoutGroup.spacing = new Vector2(10, 10); // 셀 간격
            gridLayoutGroup.constraint = GridLayoutGroup.Constraint.Flexible;
            gridLayoutGroup.startAxis = GridLayoutGroup.Axis.Horizontal;

            // 이미지 추가
            foreach (ImageData imageData in images)
            {
                StartCoroutine(LoadImage(imageData.url, gridContainer.transform));
            }
        }
    }

    IEnumerator LoadImage(string url, Transform parent)
    {
        UnityWebRequest request = UnityWebRequestTexture.GetTexture(url);

        yield return request.SendWebRequest();

        if (request.result == UnityWebRequest.Result.ConnectionError || request.result == UnityWebRequest.Result.ProtocolError)
        {
            Debug.LogError("이미지 로드 실패: " + request.error);
        }
        else
        {
            Texture2D texture = ((DownloadHandlerTexture)request.downloadHandler).texture;

            // 이미지 프리팹 생성
            GameObject newImage = Instantiate(imagePrefab, parent);
            RawImage rawImage = newImage.GetComponent<RawImage>();
            rawImage.texture = texture;
        }
    }*/
}
