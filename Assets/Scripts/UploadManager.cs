using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class UploadManager : MonoBehaviour
{
    public TMP_InputField inputTitle;
    public GameObject target;
    public GameObject targetSceneManager;

    private string title;

    public void OnClickUploadBtn()
    {
        title = inputTitle.text;
        StartCoroutine(UploadAndSwitchScene(title));
    }

    IEnumerator UploadAndSwitchScene(string title)
    {
        yield return StartCoroutine(target.GetComponent<LoadGallery>().SendImagesToServer(title));
        targetSceneManager.GetComponent<ARSceneManager>().GotoSceneSingle("Upload2");
    }

}
