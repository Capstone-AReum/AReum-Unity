using System.Collections.Generic;
using UnityEngine;

public class ImageManager : MonoBehaviour
{
    public static ImageManager Instance { get; private set; }
    public List<Texture2D> uploadedImages = new List<Texture2D>(); // 업로드된 이미지 텍스처 리스트

    private void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
        }
        else
        {
            Instance = this;
            DontDestroyOnLoad(gameObject); // 씬이 변경되어도 삭제되지 않도록 설정
        }
    }
}