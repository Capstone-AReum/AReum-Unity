using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System.IO;
using TMPro;
using UnityEngine.Networking;

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

        if (!Directory.Exists(savePath))
        {
            Directory.CreateDirectory(savePath);
        }

        File.WriteAllBytes(savePath + filename + ".png", fileData);

        var temp = File.ReadAllBytes(savePath + filename + ".png");

        Texture2D tex = new Texture2D(0, 0);
        tex.LoadImage(temp);

        // 새로운 RawImage 생성하여 부모 컨테이너에 추가
        RawImage newImage = Instantiate(imgPrefab, imageContainer);
        newImage.texture = tex;

        // 싱글톤 클래스에 이미지 추가
        ImageManager.Instance.uploadedImages.Add(tex);
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
    public IEnumerator SendImagesToServer(string title)
    {
        if (ImageManager.Instance.uploadedImages.Count == 0)
        {
            Debug.LogWarning("전송할 이미지가 없습니다.");
            yield break;
        }
        yield return StartCoroutine(UploadImages(title)); // UploadImages 코루틴 완료까지 대기
    }

    IEnumerator UploadImages(string title)
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
        string queryParam = "?title=" + UnityWebRequest.EscapeURL(title);
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
        }
        else
        {
            Debug.LogError("이미지 업로드 실패: " + request.error);
        }
    }
}