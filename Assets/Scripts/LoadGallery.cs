using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System.IO;
using TMPro;

public class LoadGallery : MonoBehaviour
{
    public RawImage imgPrefab;
    public Transform imageContainer;
    public int maxFiles = 9;
    public TextMeshProUGUI warningText;  // 경고 메시지를 표시할 TextMeshPro 오브젝트
    private HashSet<string> loadedImages = new HashSet<string>(); // 업로드된 이미지 경로를 저장하는 HashSet

    public void Start()
    {
        warningText.text = "";    // 초기에는 경고 메시지 숨김
        DisplayUploadedImages();    // 이전에 업로드된 이미지를 화면에 표시
    }

    public void OnClickImageLoad()
    {
        /*if (imageContainer.childCount >= maxFiles)
        {
            ShowWarningMessage($"최대 {maxFiles}개의 파일만 업로드할 수 있습니다.");
            return; // 추가 업로드 불가
        }*/

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
    void DisplayUploadedImages()
    {
        foreach (Texture2D tex in ImageManager.Instance.uploadedImages)
        {
            RawImage newImage = Instantiate(imgPrefab, imageContainer);
            newImage.texture = tex;
        }
    }

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
}