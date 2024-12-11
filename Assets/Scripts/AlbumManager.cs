using System.Collections;
using System.Collections.Generic;
using Newtonsoft.Json;
using TMPro;
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

    private int totalPhotosToLoad = 0; // 로드해야 할 이미지 수
    private int photosLoaded = 0; // 로드 완료된 이미지 수

    public static int selectedPhotoId; // 선택된 사진의 ID를 저장하는 정적 변수

    void Start()
    {
        ShowLoading(true);

        // 만약 기존에 캐시된 데이터가 있다면, 바로 UI 구성
        if (GlobalCache.CachedPhotoItems != null && GlobalCache.CachedPhotoItems.Count > 0)
        {
            DisplayPhotos(GlobalCache.CachedPhotoItems);
            ShowLoading(false);
        }
        else
        {
            // 캐시가 없다면 처음 로딩
            StartCoroutine(LoadAlbum());
        }
    }

    IEnumerator LoadAlbum()
    {
        // 필요한 파라미터 세팅 (여기서는 예시로 skip=0&limit=50)
        // 실제로는 GlobalCache에 저장된 개수를 바탕으로 새 데이터만 불러올 수도 있음.
        string skip = "0";
        string limit = "50";
        string url = getAlbumUrl + "?skip=" + skip + "&limit=" + limit;

        UnityWebRequest request = UnityWebRequest.Get(url);
        yield return request.SendWebRequest();  // 응답 대기

        if (request.result == UnityWebRequest.Result.Success)
        {
            List<PhotoItem> photoItems = JsonConvert.DeserializeObject<List<PhotoItem>>(request.downloadHandler.text);

            // 새로운 사진만 추출: 이미 캐시에 있는 id는 제외
            List<PhotoItem> newPhotoItems = new List<PhotoItem>();
            foreach (var item in photoItems)
            {
                if (!GlobalCache.PhotoTextures.ContainsKey(item.id))
                {
                    newPhotoItems.Add(item);
                }
            }

            // 로딩할 새 사진이 있다면 텍스처 로드
            if (newPhotoItems.Count > 0)
            {
                totalPhotosToLoad = newPhotoItems.Count;
                // 날짜별 그룹 생성 및 로드
                yield return StartCoroutine(DisplayPhotosWithLoading(newPhotoItems));

                // 로드 완료한 사진들을 전역 캐시에 추가
                GlobalCache.CachedPhotoItems.AddRange(newPhotoItems);
                GlobalCache.LastLoadedCount = GlobalCache.CachedPhotoItems.Count;
            }
            else
            {
                // 새로운 사진이 없다면 기존 데이터로 바로 디스플레이
                if (GlobalCache.CachedPhotoItems.Count == 0)
                {
                    // 캐시에 아무것도 없는 경우 -> 지금 받아온 전체를 캐시에 추가
                    GlobalCache.CachedPhotoItems.AddRange(photoItems);
                }

                DisplayPhotos(GlobalCache.CachedPhotoItems);
            }

            ShowLoading(false);
        }
        else
        {
            Debug.LogError($"Failed to fetch JSON: {request.error}");
            ShowLoading(false);
        }
    }

    void DisplayPhotos(List<PhotoItem> photoItems)
    {
        // 먼저 기존에 imageContainer에 있는 자식들을 정리하는 것을 고려할 수 있음.
        // (만약 씬 전환 시 매번 새로 로딩한다면 필요 없을 수도 있음.)
        foreach (Transform child in imageContainer)
        {
            Destroy(child.gameObject);
        }

        Dictionary<string, List<PhotoItem>> dateToImagesMap = new Dictionary<string, List<PhotoItem>>();
        foreach (PhotoItem photoItem in photoItems)
        {
            string date = photoItem.created_at.Split('T')[0]; // YYYY-MM-DD
            if (!dateToImagesMap.ContainsKey(date))
            {
                dateToImagesMap[date] = new List<PhotoItem>();
            }
            dateToImagesMap[date].Add(photoItem);
        }

        foreach (var entry in dateToImagesMap)
        {
            GameObject dateGroup = Instantiate(dateGroupPrefab, imageContainer);
            dateGroup.transform.SetParent(imageContainer, false);

            TextMeshProUGUI dateText = dateGroup.GetComponentInChildren<TextMeshProUGUI>();
            dateText.text = entry.Key;
            dateText.fontSize = 40;

            Transform gridContainer = dateGroup.transform.Find("GridContainer");
            if (gridContainer == null)
            {
                Debug.LogError("GridContainer not found in dateGroupPrefab");
                continue;
            }

            foreach (var photo in entry.Value)
            {
                RawImage newImage = Instantiate(imgPrefab, gridContainer);
                if (GlobalCache.PhotoTextures.ContainsKey(photo.id))
                {
                    newImage.texture = GlobalCache.PhotoTextures[photo.id];
                }
                else
                {
                    Debug.LogError("Texture not found in cache for photo id: " + photo.id);
                    continue;
                }

                Button button = newImage.GetComponent<Button>();
                if (button == null)
                {
                    Debug.LogError("Button component not found on imgPrefab");
                    continue;
                }

                button.onClick.AddListener(() => OnPhotoSelected(photo.id));
            }
        }

        // 레이아웃 정리
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

    IEnumerator DisplayPhotosWithLoading(List<PhotoItem> newPhotoItems)
    {
        // 날짜별로 분류
        Dictionary<string, List<PhotoItem>> dateToImagesMap = new Dictionary<string, List<PhotoItem>>();
        foreach (PhotoItem photoItem in newPhotoItems)
        {
            string date = photoItem.created_at.Split('T')[0];
            if (!dateToImagesMap.ContainsKey(date))
            {
                dateToImagesMap[date] = new List<PhotoItem>();
            }
            dateToImagesMap[date].Add(photoItem);
        }

        foreach (var entry in dateToImagesMap)
        {
            GameObject dateGroup = Instantiate(dateGroupPrefab, imageContainer);
            dateGroup.transform.SetParent(imageContainer, false);

            TextMeshProUGUI dateText = dateGroup.GetComponentInChildren<TextMeshProUGUI>();
            dateText.text = entry.Key;
            dateText.fontSize = 40;

            Transform gridContainer = dateGroup.transform.Find("GridContainer");
            if (gridContainer == null)
            {
                Debug.LogError("GridContainer not found in dateGroupPrefab");
                continue;
            }

            // 이 날짜에 해당하는 새로운 사진들에 대해 텍스처 로드
            foreach (var photo in entry.Value)
            {
                yield return StartCoroutine(LoadImage(photo, gridContainer));
            }
        }

        // 레이아웃 정리
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

    IEnumerator LoadImage(PhotoItem photo, Transform parent)
    {
        UnityWebRequest request = UnityWebRequestTexture.GetTexture(photo.url);
        yield return request.SendWebRequest();

        if (request.result == UnityWebRequest.Result.Success)
        {
            Texture2D tex = ((DownloadHandlerTexture)request.downloadHandler).texture;

            // 전역 캐시에 추가
            GlobalCache.PhotoTextures[photo.id] = tex;

            // 화면에 이미지 표시
            RawImage newImage = Instantiate(imgPrefab, parent);
            newImage.texture = tex;

            Button button = newImage.GetComponent<Button>();
            if (button == null)
            {
                Debug.LogError("Button component not found on imgPrefab");
                yield break;
            }

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
