using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System.IO;
using TMPro;
using UnityEngine.Networking;
using MetadataExtractor;
using MetadataExtractor.Formats.Exif;

public class LoadGallery : MonoBehaviour
{
    public RawImage imgPrefab;
    public Transform imageContainer;
    public int maxFiles = 9;
    public TextMeshProUGUI warningText;  // 경고 메시지를 표시할 TextMeshPro 오브젝트
    private HashSet<string> loadedImages = new HashSet<string>(); // 업로드된 이미지 경로를 저장하는 HashSet

    public RawImage cameraIcon; // 카메라 아이콘
    public TextMeshProUGUI descriptionText; // 설명 텍스트
    public GridLayoutGroup gridLayout; // Grid Layout Group 컴포넌트

    private string uploadAlbumUrl = "http://ec2-43-200-16-231.ap-northeast-2.compute.amazonaws.com/albums/upload";

    public void Start()
    {
        // 이전에 업로드된 이미지가 있다면 Grid Layout 활성화, 없다면 비활성화
        /*if (ImageManager.Instance.uploadedImages.Count > 0)
        {
            if (gridLayout != null) gridLayout.enabled = true;
            if (cameraIcon != null) cameraIcon.gameObject.SetActive(false);
            if (descriptionText != null) descriptionText.gameObject.SetActive(false);
            DisplayUploadedImages();
        }
        else
        {
            // 초기 설정: 경고 메시지 숨김, Grid Layout 비활성화, 아이콘과 설명 텍스트 표시
            if (warningText != null) warningText.text = "";
            if (gridLayout != null) gridLayout.enabled = false;
            if (cameraIcon != null) cameraIcon.gameObject.SetActive(true);
            if (descriptionText != null) descriptionText.gameObject.SetActive(true);
        }*/
        if (warningText != null) warningText.text = "";
        if (gridLayout != null) gridLayout.enabled = false;
        if (cameraIcon != null) cameraIcon.gameObject.SetActive(true);
        if (descriptionText != null) descriptionText.gameObject.SetActive(true);
    }

    public void OnClickImageLoad()
    {
        // 사용자가 버튼을 클릭하면 Grid Layout 활성화, 카메라 아이콘과 설명 텍스트 비활성화
        gridLayout.enabled = true;
        cameraIcon.gameObject.SetActive(false);
        descriptionText.gameObject.SetActive(false);

        NativeGallery.GetImagesFromGallery((files) =>
        {
            if (files == null || files.Length == 0)
            {
                return;
            }

            // 선택된 파일의 개수가 최대 개수를 초과하는 경우
            if (files.Length > maxFiles)
            {
                ShowWarningMessage($"한 번에 최대 {maxFiles}개의 파일만 업로드할 수 있습니다. 초과된 파일은 무시됩니다.");
            }

            if (imageContainer.childCount >= maxFiles)
            {
                ShowWarningMessage($"최대 {maxFiles}개의 파일만 업로드할 수 있습니다.");
                return; // 추가 업로드 불가
            }

            int availableSlots = maxFiles - imageContainer.childCount;
            int filesToLoad = Mathf.Min(files.Length, availableSlots); // 최대 개수를 초과하지 않도록 설정

            for (int i = 0; i < filesToLoad; i++)
            {
                string file = files[i];

                // 중복된 파일은 무시
                if (loadedImages.Contains(file))
                {
                    continue;
                }

                FileInfo selected = new FileInfo(file);

                // 용량 제한 (50MB)
                if (selected.Length > 50000000)
                {
                    continue; // 다음 파일로 넘어감
                }

                // 불러오기
                if (!string.IsNullOrEmpty(file))
                {
                    loadedImages.Add(file); // 파일 경로를 HashSet에 추가하여 중복 방지
                    StartCoroutine(LoadImage(file));
                }
            }
        });
    }

    IEnumerator LoadImage(string path) //코루틴
    {
        yield return null;

        byte[] fileData = File.ReadAllBytes(path);
        string filename = Path.GetFileName(path).Split('.')[0]; //확장자명 제외하기 위함
        string savePath = Application.persistentDataPath + "/Image";

        if (!System.IO.Directory.Exists(savePath))
        {
            System.IO.Directory.CreateDirectory(savePath);
        }

        File.WriteAllBytes(savePath + filename + ".png", fileData);

        var temp = File.ReadAllBytes(savePath + filename + ".png");

        Texture2D tex = new Texture2D(0, 0);
        tex.LoadImage(temp);

        // EXIF 데이터에서 회전 정보 읽기
        int rotation = GetImageRotation(path);
        if (rotation != 0)
        {
            tex = RotateTexture(tex, rotation);
        }

        // 최대 길이 1080픽셀로 리사이즈
        tex = ResizeTextureIfNecessary(tex, 1080);

        // 새로운 RawImage 생성하여 부모 컨테이너에 추가
        RawImage newImage = Instantiate(imgPrefab, imageContainer);
        newImage.texture = tex;

        // 싱글톤 클래스에 이미지 추가
        ImageManager.Instance.uploadedImages.Add(tex);
    }

    int GetImageRotation(string path)
    {
        try
        {
            var directories = ImageMetadataReader.ReadMetadata(path);
            foreach (var directory in directories)
            {
                if (directory is ExifIfd0Directory exifDirectory && exifDirectory.TryGetInt32(ExifDirectoryBase.TagOrientation, out int orientation))
                {
                    switch (orientation)
                    {
                        case 1:
                            return 0; // 회전 없음
                        case 3:
                            return 180; // 뒤집힌 경우
                        case 6:
                            return -90; // 반시계 방향 90도 회전
                        case 8:
                            return 90; // 시계 방향 90도 회전
                    }
                }
            }
        }
        catch
        {
            Debug.LogWarning("EXIF 정보를 읽는 동안 오류 발생");
        }
        return 0; // 회전 필요 없음
    }

    Texture2D RotateTexture(Texture2D originalTexture, int angle)
    {
        Texture2D rotatedTexture = new Texture2D(originalTexture.height, originalTexture.width);
        Color32[] originalPixels = originalTexture.GetPixels32();
        Color32[] rotatedPixels = new Color32[originalPixels.Length];

        int w = originalTexture.width;
        int h = originalTexture.height;

        for (int x = 0; x < w; x++)
        {
            for (int y = 0; y < h; y++)
            {
                if (angle == 90)
                {
                    rotatedPixels[x * h + (h - y - 1)] = originalPixels[y * w + x];
                }
                else if (angle == -90)
                {
                    rotatedPixels[(w - x - 1) * h + y] = originalPixels[y * w + x];
                }
                else if (angle == 180)
                {
                    rotatedPixels[(w - x - 1) * h + (h - y - 1)] = originalPixels[y * w + x];
                }
            }
        }

        rotatedTexture.SetPixels32(rotatedPixels);
        rotatedTexture.Apply();
        return rotatedTexture;
    }

    // 이미지 validation (긴 변이 1080pixel을 넘지 않도록)
    Texture2D ResizeTextureIfNecessary(Texture2D originalTexture, int maxLength)
    {
        int originalWidth = originalTexture.width;
        int originalHeight = originalTexture.height;

        // 현재 해상도가 제한을 초과하지 않으면 리사이즈하지 않음
        if (originalWidth <= maxLength && originalHeight <= maxLength)
        {
            return originalTexture;
        }

        // 가장 긴 변 기준으로 비율 계산
        float resizeRatio = 1.0f;
        if (originalWidth > originalHeight)
        {
            resizeRatio = (float)maxLength / originalWidth; // 가로가 더 긴 경우
        }
        else
        {
            resizeRatio = (float)maxLength / originalHeight; // 세로가 더 긴 경우
        }

        int newWidth = Mathf.RoundToInt(originalWidth * resizeRatio);
        int newHeight = Mathf.RoundToInt(originalHeight * resizeRatio);

        // 새로운 텍스처 생성
        Texture2D resizedTexture = new Texture2D(newWidth, newHeight, originalTexture.format, false);

        // 리사이즈된 텍스처에 픽셀 데이터를 복사
        Color[] originalPixels = originalTexture.GetPixels();
        Color[] resizedPixels = new Color[newWidth * newHeight];

        float xRatio = (float)originalWidth / newWidth;
        float yRatio = (float)originalHeight / newHeight;

        for (int y = 0; y < newHeight; y++)
        {
            for (int x = 0; x < newWidth; x++)
            {
                int srcX = Mathf.FloorToInt(x * xRatio);
                int srcY = Mathf.FloorToInt(y * yRatio);
                resizedPixels[y * newWidth + x] = originalPixels[srcY * originalWidth + srcX];
            }
        }

        resizedTexture.SetPixels(resizedPixels);
        resizedTexture.Apply();

        return resizedTexture;
    }

    // 이전에 업로드된 이미지를 화면에 표시
    /*void DisplayUploadedImages()
    {
        foreach (Texture2D tex in ImageManager.Instance.uploadedImages)
        {
            RawImage newImage = Instantiate(imgPrefab, imageContainer);
            newImage.texture = tex;
        }
    }*/

    // 경고 메시지를 TextMeshPro를 통해 화면에 표시
    void ShowWarningMessage(string message)
    {
        warningText.text = message;
        StartCoroutine(HideWarningMessageAfterDelay(5f)); // 3초 후 경고 메시지를 숨김
    }

    // 일정 시간 후 경고 메시지 숨기기
    IEnumerator HideWarningMessageAfterDelay(float delay)
    {
        yield return new WaitForSeconds(delay);
        warningText.text = ""; // 경고 메시지 숨김
    }

    // 폼 데이터로 이미지 전송
    public IEnumerator SendImagesToServer(string title, string place)
    {
        if (ImageManager.Instance.uploadedImages.Count == 0)
        {
            Debug.LogWarning("전송할 이미지가 없습니다.");
            yield break;
        }
        yield return StartCoroutine(UploadImages(title, place)); // UploadImages 코루틴 완료까지 대기
    }

    IEnumerator UploadImages(string title, string place)
    {
        // 폼 데이터 생성
        WWWForm form = new WWWForm();

        // 업로드된 이미지를 폼 데이터에 추가
        foreach (Texture2D image in ImageManager.Instance.uploadedImages)
        {
            byte[] imageBytes = image.EncodeToPNG();
            form.AddBinaryData("files", imageBytes, "image.png", "image/png");
        }

        // 서버 요청 생성
        string queryParam = "?title=" + UnityWebRequest.EscapeURL(title) + "&location=" + UnityWebRequest.EscapeURL(place);
        string url = uploadAlbumUrl + queryParam;
        UnityWebRequest request = UnityWebRequest.Post(url, form);
        //request.SetRequestHeader("accept", "application/json");

        Debug.Log($"Sending request to: {url}");

        // 요청 전송
        yield return request.SendWebRequest();

        if (request.result == UnityWebRequest.Result.Success)
        {
            Debug.Log("이미지가 성공적으로 업로드되었습니다.");

            // JSON 응답 텍스트 가져오기
            string jsonResponse = request.downloadHandler.text;
            Debug.Log("Response JSON: " + jsonResponse);

            // JSON 파싱
            ApiResponse response = JsonUtility.FromJson<ApiResponse>(jsonResponse);
            //Debug.Log($"Title: {response.title}, First Photo URL: {response.items[0].url}");
            Debug.Log(response.items);
            ImageManager.Instance.uploadedPhotos = response.items;

            // 앨범 다시 로딩되도록 캐시 초기화
            GlobalCache.CachedPhotoItems = new List<PhotoItem>();
            GlobalCache.PhotoTextures = new Dictionary<int, Texture2D>();
        }
        else
        {
            Debug.LogError("이미지 업로드 실패: " + request.error);
        }
    }
}