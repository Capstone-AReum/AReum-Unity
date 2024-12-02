using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class DisplayGallery : MonoBehaviour
{
    public RawImage imgPrefab;
    public Transform imageContainer;

    void Start()
    {
        // ImageManager에서 업로드된 이미지 리스트 가져오기
        List<Texture2D> uploadedImages = ImageManager.Instance.uploadedImages;
        
        // 이미지 리스트를 반복하며 화면에 표시
        foreach (Texture2D tex in uploadedImages)
        {
            RawImage newImage = Instantiate(imgPrefab, imageContainer);
            newImage.texture = tex;
        }
    }
}
