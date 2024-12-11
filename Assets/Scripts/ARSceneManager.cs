using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class ARSceneManager : MonoBehaviour
{
    private string currentLoadedScene = "";

    public void GotoMainSingle()
    {
        SceneManager.LoadScene("Main", LoadSceneMode.Single);
    }

    public void GotoSceneSingle(string sceneName)
    {
        SceneManager.LoadScene(sceneName, LoadSceneMode.Single);
    }

    public void GotoSceneAdditive(string sceneName)
    {
        SceneManager.LoadScene(sceneName, LoadSceneMode.Additive);
    }

    public void ReturnToPreviousScene()
    {
        if (string.IsNullOrEmpty(currentLoadedScene))
        {
            Debug.LogWarning("추가된 씬이 없습니다.");
            return;
        }

        SceneManager.UnloadSceneAsync(currentLoadedScene);
        currentLoadedScene = ""; // 현재 로드된 씬 정보 초기화
    }

    public void UnLoadScene(string sceneName)
    {
        if (string.IsNullOrEmpty(sceneName))
        {
            Debug.LogWarning("추가된 씬이 없습니다.");
            return;
        }
        SceneManager.UnloadSceneAsync(sceneName);
        Debug.Log("돌아감~");
    }
}
