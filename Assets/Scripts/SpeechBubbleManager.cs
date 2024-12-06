using UnityEngine;
using UnityEngine.UI;
using TMPro;

public class SpeechBubbleManager : MonoBehaviour
{
    [SerializeField] private Canvas uiCanvas; // 말풍선 UI가 배치될 캔버스
    [SerializeField] private Camera arCamera; // AR 카메라
    [SerializeField] private GameObject speechBubblePrefab; // 말풍선 프리팹

    private GameObject speechBubbleInstance; // 말풍선 인스턴스
    private GameObject targetObject; // 대상 3D 오브젝트
    private RectTransform speechBubbleRect;

    public void CreateSpeechBubble(GameObject target, string message)
    {
        if (speechBubblePrefab == null || uiCanvas == null || arCamera == null)
        {
            Debug.LogError("SpeechBubbleManager: 필요한 요소가 설정되지 않았습니다.");
            return;
        }

        // 기존 말풍선 삭제
        if (speechBubbleInstance != null)
        {
            Destroy(speechBubbleInstance);
        }

        // 말풍선 생성
        speechBubbleInstance = Instantiate(speechBubblePrefab, uiCanvas.transform);
        speechBubbleRect = speechBubbleInstance.GetComponent<RectTransform>();
        targetObject = target; // 타겟 3D 오브젝트 설정

        // 텍스트 설정
        var bubbleText = speechBubbleInstance.GetComponentInChildren<TextMeshProUGUI>();
        if (bubbleText != null)
        {
            bubbleText.text = message;
        }
    }

    private void Update()
    {
        if (speechBubbleInstance != null && targetObject != null)
        {
            UpdateSpeechBubblePosition();
        }
    }

    private void UpdateSpeechBubblePosition()
    {
        // 3D 오브젝트의 월드 좌표를 화면 좌표로 변환
        Vector3 screenPosition = arCamera.WorldToScreenPoint(targetObject.transform.position);

        // 화면 좌표를 UI 캔버스의 로컬 좌표로 변환
        RectTransform canvasRect = uiCanvas.GetComponent<RectTransform>();
        Vector2 uiPosition;
        if (RectTransformUtility.ScreenPointToLocalPointInRectangle(canvasRect, screenPosition, arCamera, out uiPosition))
        {
            // 말풍선 위치 업데이트
            speechBubbleRect.anchoredPosition = uiPosition + new Vector2(0, 50); // 오브젝트 위로 약간 올림
        }

        // 화면 밖으로 나가거나 AR 카메라에서 보이지 않으면 숨기기
        if (screenPosition.z < 0)
        {
            speechBubbleInstance.SetActive(false);
        }
        else
        {
            speechBubbleInstance.SetActive(true);
        }
    }
}
