using System.Collections.Generic;
using UnityEngine;

public class SpeechBubbleManager : MonoBehaviour
{
    public static SpeechBubbleManager Instance;

    public Dictionary<GameObject, GameObject> SpeechBubbleMap = new Dictionary<GameObject, GameObject>();

    private void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
            DontDestroyOnLoad(gameObject); // 씬 전환 시 유지
        }
        else
        {
            Destroy(gameObject); // 중복 방지
        }
    }

    public void AddSpeechBubble(GameObject target, GameObject bubble)
    {
        if (SpeechBubbleMap.ContainsKey(target))
        {
            Destroy(SpeechBubbleMap[target]);
        }
        SpeechBubbleMap[target] = bubble;
    }

    public void RemoveSpeechBubble(GameObject target)
    {
        if (SpeechBubbleMap.ContainsKey(target))
        {
            Destroy(SpeechBubbleMap[target]);
            SpeechBubbleMap.Remove(target);
        }
    }

    public void ClearAllSpeechBubbles()
    {
        foreach (var bubble in SpeechBubbleMap.Values)
        {
            Destroy(bubble);
        }
        SpeechBubbleMap.Clear();
    }
}
