using System.Collections;
using System.Collections.Generic;
using Newtonsoft.Json;
using TMPro;
using UnityEditor;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class AlbumManager : MonoBehaviour
{
    public RawImage imgPrefab;
    public Transform imageContainer;
    public GameObject loadingPanel;
    public GameObject dateGroupPrefab; // 날짜 그룹을 위한 프리팹

    private string getAlbumUrl = "http://ec2-43-200-16-231.ap-northeast-2.compute.amazonaws.com/albums/all";
    private Dictionary<int, Texture2D> photoTextures = new Dictionary<int, Texture2D>(); // ID와 Texture2D 매핑
    private int totalPhotosToLoad = 0; // 로드해야 할 이미지 수
    private int photosLoaded = 0; // 로드 완료된 이미지 수

    public static int selectedPhotoId; // 선택된 사진의 ID를 저장하는 정적 변수

    void Start()
    {
        ShowLoading(true);

        string skip = "0";
        string limit = "50";

        string queryParam = "?skip=" + skip + "&limit=" + limit;
        string url = getAlbumUrl + queryParam;

        StartCoroutine(LoadAlbum(url));
    }

    IEnumerator LoadAlbum(string url)
    {
        UnityWebRequest request = UnityWebRequest.Get(url);
        yield return request.SendWebRequest();  // 응답이 올 때까지 대기

        if (request.result == UnityWebRequest.Result.Success)
        {
            string jsonResponse = request.downloadHandler.text;
            List<PhotoItem> photoItems = JsonConvert.DeserializeObject<List<PhotoItem>>(jsonResponse);

            totalPhotosToLoad = photoItems.Count; // 로드해야 할 이미지 수 설정

            // 날짜별로 이미지 분류
            Dictionary<string, List<PhotoItem>> dateToImagesMap = new Dictionary<string, List<PhotoItem>>();
            foreach (PhotoItem photoItem in photoItems)
            {
                string date = photoItem.created_at.Split('T')[0]; // 날짜 부분만 추출 (YYYY-MM-DD)
                if (!dateToImagesMap.ContainsKey(date))
                {
                    dateToImagesMap[date] = new List<PhotoItem>();
                }
                dateToImagesMap[date].Add(photoItem);
            }

            // 날짜별로 이미지 표시
            foreach (var entry in dateToImagesMap)
            {
                // 날짜 그룹 생성
                GameObject dateGroup = Instantiate(dateGroupPrefab, imageContainer);
                dateGroup.transform.SetParent(imageContainer, false);

                // 날짜 레이블 설정
                TextMeshProUGUI dateText = dateGroup.GetComponentInChildren<TextMeshProUGUI>();
                dateText.text = entry.Key;
                dateText.fontSize = 40;

                Transform gridContainer = dateGroup.transform.Find("GridContainer");
                if (gridContainer == null)
                {
                    Debug.LogError("GridContainer not found in dateGroupPrefab");
                    continue;
                }

                // 해당 날짜의 이미지들 로드
                foreach (var photo in entry.Value)
                {
                    yield return StartCoroutine(LoadImage(photo, gridContainer));
                }
            }

            // 날짜 그룹이 수직으로 정렬되도록 설정
            VerticalLayoutGroup verticalLayout = imageContainer.GetComponent<VerticalLayoutGroup>();
            if (verticalLayout == null)
            {
                verticalLayout = imageContainer.gameObject.AddComponent<VerticalLayoutGroup>();
            }
            verticalLayout.childControlHeight = true;
            verticalLayout.childControlWidth = true;
            verticalLayout.childForceExpandHeight = false;
            verticalLayout.childForceExpandWidth = true;
            verticalLayout.spacing = 80;
        }
        else
        {
            Debug.LogError($"Failed to fetch JSON: {request.error}");
            ShowLoading(false); // JSON 로드 실패 시 로딩 패널 숨김
        }
    }

    IEnumerator LoadImage(PhotoItem photo, Transform parent)
    {
        UnityWebRequest request = UnityWebRequestTexture.GetTexture(photo.url);
        yield return request.SendWebRequest();

        if (request.result == UnityWebRequest.Result.Success)
        {
            Texture2D tex = ((DownloadHandlerTexture)request.downloadHandler).texture;

            // ID와 Texture2D를 매핑
            photoTextures[photo.id] = tex;

            // 화면에 이미지 표시
            RawImage newImage = Instantiate(imgPrefab, parent);
            newImage.texture = tex;

            // 클릭 이벤트 추가
            Button button = newImage.GetComponent<Button>();
            if (button == null)
            {
                Debug.LogError("Button component not found on imgPrefab");
                yield break;
            }

            // 버튼 클릭 시 AlbumDetail Scene으로 이동하고 사진 ID 전달
            button.onClick.AddListener(() => OnPhotoSelected(photo.id));

            // 이미지 로드 완료 카운트 증가
            photosLoaded++;
            CheckLoadingComplete();
        }
        else
        {
            Debug.LogError($"Failed to load image from {photo.url}: {request.error}");
            photosLoaded++; // 실패한 경우에도 카운트 증가
            CheckLoadingComplete();
        }
    }

    void OnPhotoSelected(int photoId)
    {
        // 선택된 사진의 ID 저장
        selectedPhotoId = photoId;

        // AlbumDetail Scene으로 이동
        SceneManager.LoadScene("AlbumDetail");
    }

    void CheckLoadingComplete()
    {
        // 모든 이미지가 로드 완료된 경우
        if (photosLoaded >= totalPhotosToLoad)
        {
            ShowLoading(false); // 로딩 패널 숨김
        }
    }

    void ShowLoading(bool isLoading)
    {
        if (loadingPanel != null)
        {
            loadingPanel.SetActive(isLoading);
        }
    }
}