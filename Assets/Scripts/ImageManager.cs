using System.Collections.Generic;
using UnityEngine;

public class ImageManager : MonoBehaviour
{
    public static ImageManager Instance { get; private set; }

    public List<Texture2D> uploadedImages = new List<Texture2D>();
    public List<PhotoItem> uploadedPhotos = new List<PhotoItem>();

    private void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
        }
        else
        {
            Instance = this;
            DontDestroyOnLoad(gameObject);
        }
    }

    public void ResetManager()
    {
        uploadedImages.Clear();
        uploadedPhotos.Clear();
    }
}
