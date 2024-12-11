using UnityEngine;

public class DirectionalLightController : MonoBehaviour
{
    public Light directionalLight; // Directional Light를 드래그하여 연결
    public Camera arCamera;        // AR 카메라를 드래그하여 연결

    void Update()
    {
        if (directionalLight != null && arCamera != null)
        {
            // Directional Light의 방향 설정 (카메라 방향으로 비추도록 설정)
            directionalLight.transform.rotation = Quaternion.LookRotation(arCamera.transform.forward);
        }
    }
}