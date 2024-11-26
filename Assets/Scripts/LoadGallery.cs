using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System.IO;

public class LoadGallery : MonoBehaviour
{
    public RawImage imgPrefab;
    public Transform imageContainer;

    public void Start(){
        Debug.Log(Application.persistentDataPath);
    }

    public void OnClickImageLoad(){
        NativeGallery.GetImagesFromGallery((files)=>{
            if (files == null || files.Length == 0)
            {
                return;
            }

            foreach (string file in files)
            {
                FileInfo selected = new FileInfo(file);

                // 용량 제한 (50MB)
                if (selected.Length > 50000000)
                {
                    continue; // 다음 파일로 넘어감
                }

                // 불러오기
                if (!string.IsNullOrEmpty(file))
                {
                    // 코루틴으로 이미지 로드
                    StartCoroutine(LoadImage(file));
                }
            }
        });
    }

    IEnumerator LoadImage(string path) //코루틴
    {
        yield return null;

        byte[] fileData = File.ReadAllBytes(path);
        string filename = Path.GetFileName(path).Split('.')[0]; //확장자명 제외하기 위함
        string savePath = Application.persistentDataPath + "/Image";

        if(!Directory.Exists(savePath)){
            Directory.CreateDirectory(savePath);
        }

        File.WriteAllBytes(savePath + filename + ".png", fileData);
    
        var temp = File.ReadAllBytes(savePath + filename + ".png");

        Texture2D tex = new Texture2D(0, 0);
        tex.LoadImage(temp);

        // 새로운 RawImage 생성하여 부모 컨테이너에 추가
        RawImage newImage = Instantiate(imgPrefab, imageContainer);
        newImage.texture = tex;
    }
}
