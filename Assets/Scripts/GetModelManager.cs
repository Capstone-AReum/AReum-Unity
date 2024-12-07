using System;
using System.Collections;
using System.Collections.Generic;
using Newtonsoft.Json;
using Siccity.GLTFUtility;
using TMPro;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class GetModelManager : MonoBehaviour
{
    public GameObject popupPanel;
    public TextMeshProUGUI popupText;    // 팝업 내부 TextMeshPro
    public Button okButton;         // 팝업의 확인 버튼
    
    private string postThumbnailUrl = "http://ec2-43-200-16-231.ap-northeast-2.compute.amazonaws.com/albums/thumbnails";
    public static string glbUrl; // GLB 파일 URL을 저장

    void Start()
    {
        popupPanel.SetActive(false);

        Debug.Log("SF3D API 호출 시작");
        //glbUrl = "https://cap-areum.s3.ap-northeast-2.amazonaws.com/models/o_yHzLt5ATvVzbvXDG3yNw.glb";
        //SceneManager.LoadScene("Upload3");
        StartCoroutine(SendModelRequest());
    }

    IEnumerator SendModelRequest()
    {
        string queryParam = "?source_id=" + DisplayGallery.selectedPhotoId;
        string url = postThumbnailUrl + queryParam;

        UnityWebRequest request = UnityWebRequest.Post(url, "");

        yield return request.SendWebRequest(); // 응답 대기

        if (request.result == UnityWebRequest.Result.Success)
        {
            Debug.Log("API 요청 성공!");
            
            string jsonResponse = request.downloadHandler.text;
            ThumbnailsItem thumbnailsItem = JsonConvert.DeserializeObject<ThumbnailsItem>(jsonResponse);
            glbUrl = thumbnailsItem.file_url; // GLB URL 저장
            
            Debug.Log("GLB 파일 URL: " + glbUrl);

            // "Upload3" 씬으로 전환
            SceneManager.LoadScene("Upload3");
        }
        else
        {
            Debug.LogError("API 요청 실패: " + request.error);

            popupPanel.SetActive(true);
            popupText.text = $"3D 모델 생성에 실패했습니다.\n{request.error}";
            okButton.gameObject.SetActive(true);
        }
    }
}