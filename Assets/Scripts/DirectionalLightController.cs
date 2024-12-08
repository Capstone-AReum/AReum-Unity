using UnityEngine;

public class DirectionalLightController : MonoBehaviour
{
    public Light directionalLight; // Directional Light를 드래그하여 연결
    public Camera arCamera;        // AR 카메라를 드래그하여 연결
    private float offsetY = 2.0f;   // 카메라보다 위로 얼마나 높이 위치시킬지
    private float offsetZ = 2.0f;   // 핸드폰 방향으로 얼마나 멀리 배치할지

    void Update()
    {
        if (directionalLight != null && arCamera != null)
        {
            // 카메라 위치 가져오기
            Vector3 cameraPosition = arCamera.transform.position;

            // 카메라보다 위쪽으로 오프셋 적용 (y 축)
            Vector3 upOffset = new Vector3(0, offsetY, 0);

            // 핸드폰 후면 카메라 반대 방향으로 오프셋 적용 (z 축)
            Vector3 backOffset = arCamera.transform.forward * offsetZ;

            // 빛의 최종 위치 계산
            Vector3 lightPosition = cameraPosition + upOffset + backOffset;

            // Directional Light의 위치 설정
            directionalLight.transform.position = lightPosition;

            // Directional Light의 방향 설정 (카메라 방향으로 비추도록 설정)
            directionalLight.transform.rotation = Quaternion.LookRotation(arCamera.transform.forward);
        }
    }
}