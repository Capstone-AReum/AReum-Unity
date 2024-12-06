using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;

public class DisplayGallery : MonoBehaviour
{
    public RawImage imgPrefab;
    public Transform imageContainer;
    public GameObject loadingPanel;
    public static int selectedPhotoId = -1; // 현재 선택된 사진 ID

    public Button nextButton; // 다음 버튼

    private Dictionary<int, Texture2D> photoTextures = new Dictionary<int, Texture2D>(); // ID와 Texture2D 매핑
    private Button selectedButton = null; // 현재 선택된 버튼

    private int totalPhotosToLoad = 0; // 로드해야 할 이미지 수
    private int photosLoaded = 0; // 로드 완료된 이미지 수

    void Start()
    {
        ShowLoading(true);

        if (nextButton != null)
        {
            nextButton.interactable = false;
        }

        // ImageManager에서 업로드된(=API 호출 후 실제로 DB에 업로드 된) 사진 정보 가져오기
        List<PhotoItem> uploadedPhotos = ImageManager.Instance.uploadedPhotos;
        totalPhotosToLoad = uploadedPhotos.Count; // 로드해야 할 이미지 수 설정

        foreach (PhotoItem photo in uploadedPhotos)
        {
            StartCoroutine(LoadImage(photo));
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
            button.onClick.AddListener(() => OnPhotoSelected(photo.id, button));

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

    void OnPhotoSelected(int photoId, Button button)
    {
        //Debug.Log($"Selected Photo ID: {photoId}");

        // 이전에 선택된 버튼 초기화
        if (selectedButton != null && selectedButton != button)
        {
            // 이전 버튼의 텍스트 초기화
            TextMeshProUGUI previousText = selectedButton.GetComponentInChildren<TextMeshProUGUI>();
            if (previousText != null)
            {
                previousText.text = ""; // 텍스트 비우기
            }
        }

        // 새로운 버튼 선택
        selectedButton = button;
        selectedPhotoId = photoId;

        // 현재 선택된 버튼에 표시
        TextMeshProUGUI buttonText = button.GetComponentInChildren<TextMeshProUGUI>();
        if (buttonText != null)
        {
            buttonText.text = "V"; // 선택된 버튼에 체크 표시
        }
        else
        {
            Debug.LogError("TextMeshPro component not found in the button prefab!");
        }

        if (nextButton != null && !nextButton.interactable)
        {
            nextButton.interactable = true;
        }

        // API로 선택한 ID를 넘기는 로직 추가 (나중에 모델 만드는 api 호출 예정)
        //StartCoroutine(SendSelectedPhotoId(photoId));
    }

    public void OnNextButtonClicked()
    {
        Debug.Log($"thumbnail API 호출 할 id : {selectedPhotoId}");
        ImageManager.Instance.ResetManager();
    }

    /*IEnumerator SendSelectedPhotoId(int photoId)
    {
        WWWForm form = new WWWForm();
        form.AddField("selected_photo_id", photoId);

        UnityWebRequest request = UnityWebRequest.Post("http://example.com/api/select-photo", form);
        yield return request.SendWebRequest();

        if (request.result == UnityWebRequest.Result.Success)
        {
            Debug.Log("Photo ID sent successfully!");
        }
        else
        {
            Debug.LogError($"Failed to send photo ID: {request.error}");
        }
    }*/

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
