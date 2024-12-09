using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class UploadManager : MonoBehaviour
{
    public TMP_InputField inputTitle;
    public GameObject target;
    public GameObject targetSceneManager;
    public GameObject loadingPanel;

    private string title;
    private string place;

    void Start()
    {
        title = "";
        place = "";
    }
    public void OnSelectPlaceButton(string buttonText)
    {
        place = buttonText;
    }

    public void OnClickUploadBtn()
    {
        title = inputTitle.text;
        if (title == "")
        {
            title = "...";
        }

        if (place == "")
        {
            place = "기타";
        }
        ShowLoading(true);
        Debug.Log($"=>{title}, {place}");
        StartCoroutine(UploadAndSwitchScene(title, place));
    }

    IEnumerator UploadAndSwitchScene(string title, string place)
    {
        yield return StartCoroutine(target.GetComponent<LoadGallery>().SendImagesToServer(title, place));
        ShowLoading(false);
        targetSceneManager.GetComponent<ARSceneManager>().GotoSceneSingle("Upload2");
    }

    void ShowLoading(bool isLoading)
    {
        if (loadingPanel != null)
        {
            loadingPanel.SetActive(isLoading);
        }
    }
}
