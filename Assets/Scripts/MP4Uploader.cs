using System.IO;
using UnityEngine;
using UnityEngine.Networking;

public class MP4Uploader : MonoBehaviour
{
  public void PickMP4File()
  {
    // NativeGallery를 사용하여 MP4 파일 선택
    NativeGallery.Permission permission = NativeGallery.GetVideoFromGallery(
        (path) =>
        {
          if (!string.IsNullOrEmpty(path) && File.Exists(path))
          {
            Debug.Log("Selected MP4 Path: " + path);

            // 선택된 파일을 서버로 업로드
            StartCoroutine(UploadMP4File(path));
          }
          else
          {
            Debug.LogWarning("No MP4 file selected or invalid path.");
          }
        },
        "Select an MP4 file",
        "video/mp4" // MP4 MIME 타입
    );

    if (permission == NativeGallery.Permission.Denied)
    {
      Debug.LogError("Permission denied to access gallery.");
    }
  }

  private System.Collections.IEnumerator UploadMP4File(string filePath)
  {
    // 서버 URL
    string url = "http://ec2-43-200-16-231.ap-northeast-2.compute.amazonaws.com/albums/voice";
    string paramUrl = "?thumbnail_id=" + GetModelManager.thumbnailId;

    string patchUrl = url + paramUrl;

    // HTTP 요청 생성
    UnityWebRequest request = UnityWebRequest.Post(patchUrl, new WWWForm());
    request.method = "PATCH";

    // MP4 파일 읽기
    byte[] fileData = File.ReadAllBytes(filePath);
    string fileName = Path.GetFileName(filePath);

    // multipart/form-data 요청 구성
    WWWForm form = new WWWForm();
    form.AddBinaryData("file", fileData, fileName, "video/mp4");

    // Form 데이터를 요청 본문에 추가
    request.uploadHandler = new UploadHandlerRaw(form.data);
    request.SetRequestHeader("Content-Type", form.headers["Content-Type"]);

    // 다운로드 핸들러 추가 (응답 처리)
    request.downloadHandler = new DownloadHandlerBuffer();

    // 요청 전송
    yield return request.SendWebRequest();

    // 결과 처리
    if (request.result == UnityWebRequest.Result.Success)
    {
      Debug.Log("MP4 uploaded successfully via PATCH: " + request.downloadHandler.text);
    }
    else
    {
      Debug.LogError("MP4 upload failed via PATCH: " + request.error);
      Debug.LogError("Response: " + request.downloadHandler.text);
    }
  }
}
