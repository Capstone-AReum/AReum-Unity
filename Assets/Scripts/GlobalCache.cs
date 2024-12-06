using System.Collections.Generic;
using UnityEngine;

public static class GlobalCache
{
    public static Dictionary<int, Texture2D> PhotoTextures = new Dictionary<int, Texture2D>();
    public static List<PhotoItem> CachedPhotoItems = new List<PhotoItem>();
    // 마지막으로 불러온 사진의 가장 최신 날짜나 ID를 저장할 수도 있음. 
    // 여기서는 예시로 최근 로드된 아이템 개수 정도만 관리.
    public static int LastLoadedCount = 0;
}
