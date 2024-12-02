using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;

public class HealthCheck : MonoBehaviour
{
    private string healthUrl = "http://ec2-43-200-16-231.ap-northeast-2.compute.amazonaws.com/health";

    // Start is called before the first frame update
    void Start()
    {
        Debug.Log("health check 시작");
        StartCoroutine(SendHealthRequest());
    }

    IEnumerator SendHealthRequest(){
        UnityWebRequest request = UnityWebRequest.Get(healthUrl);

        yield return request.SendWebRequest();  // 응답이 올 때까지 대기함

        if(request.result == UnityWebRequest.Result.Success){
            Debug.Log("건강함:) "+ request.downloadHandler.data);
        }else{
            Debug.LogError("실패: " + request.error);
        }
    }
}
