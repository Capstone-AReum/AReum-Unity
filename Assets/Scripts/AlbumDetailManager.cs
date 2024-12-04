using System.Collections;
using System.Collections.Generic;
using Newtonsoft.Json;
using TMPro;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;

public class AlbumDetailManager : MonoBehaviour
{
    public RawImage photoImage; // 사진을 표시할 RawImage
    public RectTransform panel; // 사진이 표시될 부모 패널의 RectTransform
    public TMP_Text photoTitleText; // 제목 정보를 표시할 텍스트
    public TMP_Text photoDateText; // 날짜 정보를 표시할 텍스트
    
    public GameObject loadingPanel;

    private string getPhotoDetailUrl = "http://ec2-43-200-16-231.ap-northeast-2.compute.amazonaws.com/albums";

    void Start()
    {
        ShowLoading(true);

        int photoId = AlbumManager.selectedPhotoId; // 선택된 사진의 ID 가져오기
        string url = $"{getPhotoDetailUrl}/{photoId}/details";

        StartCoroutine(LoadPhotoDetails(url));
    }

    IEnumerator LoadPhotoDetails(string url)
    {
        UnityWebRequest request = UnityWebRequest.Get(url);
        yield return request.SendWebRequest();

        if (request.result == UnityWebRequest.Result.Success)
        {
            string jsonResponse = request.downloadHandler.text;
            PhotoItemDetail photo = JsonConvert.DeserializeObject<PhotoItemDetail>(jsonResponse);

            // 사진 정보를 UI에 표시
            if (photoTitleText != null)
                photoTitleText.text = $"{photo.title}";
            if (photoDateText != null)
                photoDateText.text = $"{photo.created_at.Split('T')[0]} {photo.created_at.Split('T')[1]}";

            UnityWebRequest imageRequest = UnityWebRequestTexture.GetTexture(photo.url);
            yield return imageRequest.SendWebRequest();

            if (imageRequest.result == UnityWebRequest.Result.Success)
            {
                Texture2D tex = ((DownloadHandlerTexture)imageRequest.downloadHandler).texture;
                AdjustImageSize(photoImage, tex, panel);
                photoImage.texture = tex;
                ShowLoading(false);
            }
            else
            {
                Debug.LogError($"Failed to load image: {imageRequest.error}");
                ShowLoading(false);
            }
        }
        else
        {
            Debug.LogError($"Failed to load photo details: {request.error}");
            ShowLoading(false);
        }
    }

    void AdjustImageSize(RawImage image, Texture2D texture, RectTransform container)
    {
        // 원본 이미지의 비율 계산
        float originalWidth = texture.width;
        float originalHeight = texture.height;
        float aspectRatio = originalWidth / originalHeight;

        // 컨테이너의 크기 가져오기
        float containerWidth = container.rect.width;
        float containerHeight = container.rect.height;

        // 패널의 최대 크기를 넘지 않도록 이미지 크기 조정
        float targetWidth = containerWidth;
        float targetHeight = targetWidth / aspectRatio;

        if (targetHeight > containerHeight)
        {
            targetHeight = containerHeight;
            targetWidth = targetHeight * aspectRatio;
        }

        // 크기를 조정
        image.rectTransform.sizeDelta = new Vector2(targetWidth, targetHeight);
    }

    void ShowLoading(bool isLoading)
    {
        if (loadingPanel != null)
        {
            loadingPanel.SetActive(isLoading);
        }
    }
}