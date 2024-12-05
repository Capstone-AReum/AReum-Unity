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

    public void OnClickUploadBtn()
    {
        title = inputTitle.text;
        ShowLoading(true);
        StartCoroutine(UploadAndSwitchScene(title));
    }

    IEnumerator UploadAndSwitchScene(string title)
    {
        yield return StartCoroutine(target.GetComponent<LoadGallery>().SendImagesToServer(title));
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
