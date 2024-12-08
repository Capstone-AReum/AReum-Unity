using System.Collections;
using System.Collections.Generic;
using Google.XR.ARCoreExtensions;
using TMPro;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using UnityEngine.XR.ARFoundation;

// Reset 시 사용
public class CloudAnchorManager4 : MonoBehaviour
{
    // 상태 변수
    public enum Mode { READY, HOST, HOST_PENDING, RESOLVE, RESOLVE_PENDING };

    // 버튼
    public Button resetButton;
    public GameObject popupPanel;           // 팝업
    public TextMeshProUGUI popupText;       // 팝업 내부 TextMeshPro
    public Button okButton;                 // 팝업의 확인 버튼
    public Button cancelButton;             // 팝업의 취소 버튼
    public GameObject buttonPanel;          // 확인, 취소 버튼이 담긴 패널
    public Button closeButton;              // 팝업의 닫기 버튼
    public GameObject laterButtonPanel;     // 닫기 버튼이 담긴 패널

    // 상태변수
    public Mode mode = Mode.READY;

    // 저장 객체 변수 (삭제용)
    private GameObject anchorGameObject;

    // 로컬 앵커 저장 변수
    private ARAnchor localAnchor;

    // 클라우드 앵커 변수
    private ARCloudAnchor cloudAnchor;

    // Cloud Anchor 데이터 관리용
    private Dictionary<string, AnchorData> anchorDataMap = new Dictionary<string, AnchorData>();

    void Start()
    {
        buttonPanel.SetActive(false);
        laterButtonPanel.SetActive(false);
        popupPanel.SetActive(false);

        resetButton.onClick.AddListener(ShowPopUpPanel);
        okButton.onClick.AddListener(OnResetClick);
        cancelButton.onClick.AddListener(OnCancelClick);
        closeButton.onClick.AddListener(OnCloseClick);

        // AnchorData 로드
        LoadAnchorData();
    }

    void Update()
    {

    }

    private void LoadAnchorData()
    {
        if (PlayerPrefs.HasKey("AnchorDataMap"))
        {
            string json = PlayerPrefs.GetString("AnchorDataMap");

            // SerializableDictionary 역직렬화
            SerializableDictionary<string, AnchorData> serializableData = JsonUtility.FromJson<SerializableDictionary<string, AnchorData>>(json);

            // 일반 Dictionary로 변환
            anchorDataMap = serializableData.ToDictionary();
            Debug.Log("AnchorData 로드 완료");
        }
        else
        {
            anchorDataMap = new Dictionary<string, AnchorData>();
            Debug.Log("저장된 AnchorData가 없습니다.");
        }
    }

    public void ShowPopUpPanel()
    {
        popupPanel.SetActive(true);
        buttonPanel.SetActive(true);
        laterButtonPanel.SetActive(false);
    }

    public void OnResetClick()
    {
        // 1. 모든 GLB 오브젝트와 로컬 앵커 삭제
        if (anchorGameObject != null)
        {
            Destroy(anchorGameObject);
            anchorGameObject = null;
        }

        if (localAnchor != null)
        {
            Destroy(localAnchor.gameObject);
            localAnchor = null;
        }

        // 2. 클라우드 앵커 삭제
        if (cloudAnchor != null)
        {
            Destroy(cloudAnchor.gameObject);
            cloudAnchor = null;
        }

        // 3. AnchorDataMap 초기화 및 PlayerPrefs 삭제
        anchorDataMap.Clear();
        PlayerPrefs.DeleteKey("AnchorDataMap");
        PlayerPrefs.Save();

        // 4. 모든 말풍선 삭제
        SpeechBubbleManager.Instance.ClearAllSpeechBubbles();

        // 5. 상태 초기화
        Debug.Log("Reset 완료: 모든 오브젝트 및 앵커 삭제");
        popupText.text = "모든 클라우드 앵커가 삭제되었습니다.";
        mode = Mode.READY;

        buttonPanel.SetActive(false);
        laterButtonPanel.SetActive(true);
    }

    public void OnCancelClick()
    {
        buttonPanel.SetActive(true);
        popupPanel.SetActive(false);
    }

    public void OnCloseClick()
    {   
        laterButtonPanel.SetActive(true);
        popupPanel.SetActive(false);
    }
}
