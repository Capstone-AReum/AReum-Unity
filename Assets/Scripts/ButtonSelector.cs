using UnityEngine;
using UnityEngine.UI;

public class ButtonSelector : MonoBehaviour
{
    public Button[] buttons;

    private Color normalColor = Color.white;
    private Color selectedColor = new Color(0.87f, 0.89f, 0.71f);
    private Button selectedButton;
    
    void Start()
    {
        SetAllButtonsColor(normalColor);
    }

    // 버튼을 클릭하면 이 메서드를 호출
    public void OnSelectButton(Button clickedButton)
    {
        SetAllButtonsColor(normalColor);

        // 선택한 버튼만 초록색으로 변경
        SetButtonColor(clickedButton, selectedColor);
        selectedButton = clickedButton;
    }

    private void SetAllButtonsColor(Color color)
    {
        foreach (var btn in buttons)
        {
            SetButtonColor(btn, color);
        }
    }

    private void SetButtonColor(Button btn, Color color)
    {
        Image img = btn.GetComponent<Image>();
        if (img != null)
        {
            img.color = color;
        }
    }
}