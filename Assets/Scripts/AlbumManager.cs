using System.Collections;
using System.Collections.Generic;
using Newtonsoft.Json;
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

    IEnumerator LoadAlbum(string url){
        UnityWebRequest request = UnityWebRequest.Get(url);
        yield return request.SendWebRequest();  // 응답이 올 때까지 대기

        if(request.result == UnityWebRequest.Result.Success){
            string jsonResponse = request.downloadHandler.text;
            List<PhotoItem> photoItems = JsonConvert.DeserializeObject<List<PhotoItem>>(jsonResponse);

            totalPhotosToLoad = photoItems.Count; // 로드해야 할 이미지 수 설정

            foreach (var photo in photoItems)
            {
                //Debug.Log($"ID: {photo.id}, URL: {photo.url}, Created At: {photo.created_at}");
                StartCoroutine(LoadImage(photo));
            }
        }
        else
        {
            Debug.LogError($"Failed to fetch JSON: {request.error}");
            ShowLoading(false); // JSON 로드 실패 시 로딩 패널 숨김
        }
    }

    IEnumerator LoadImage(PhotoItem photo)
    {
        UnityWebRequest request = UnityWebRequestTexture.GetTexture(photo.url);
        yield return request.SendWebRequest();

        if (request.result == UnityWebRequest.Result.Success)
        {
            Texture2D tex = ((DownloadHandlerTexture)request.downloadHandler).texture;

            // ID와 Texture2D를 매핑
            photoTextures[photo.id] = tex;

            // 화면에 이미지 표시
            RawImage newImage = Instantiate(imgPrefab, imageContainer);
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

    // foreach를 내부에 포함함
    /*void DisplayAlbum(List<PhotoItem> photoItems)
    {
        // 날짜 추가
        Dictionary<string, List<PhotoItem>> dateToImagesMap = new Dictionary<string, List<PhotoItem>>();

        foreach (PhotoItem photoItem in photoItems)
        {
            string date = photoItem.created_at;
            if(!dateToImagesMap.ContainsKey(date)){
                dateToImagesMap[date] = new List<PhotoItem>();
            }
            dateToImagesMap[date].Add(photoItem);
        }
    }*/

}
