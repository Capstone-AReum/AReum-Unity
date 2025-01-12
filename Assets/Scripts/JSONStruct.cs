using System;
using System.Collections.Generic;

[Serializable]
public class PhotoItem
{
    public int id;
    public string url;
    public string created_at;
}

[Serializable]
public class PhotoItemDetail
{
    public int id;
    public string url;
    public string created_at;
    public string title;
}

[Serializable]
public class ApiResponse
{
    public int id;
    public string title;
    public string location;
    public string created_at;
    public List<PhotoItem> items;
}

[Serializable]
public class StatDateItem
{
    public string date;
    public int count;
}

[Serializable]
public class ThumbnailsItem
{
    public int id;
    public string file_url;
}

[System.Serializable]
public class StatPlaceItem
{
    public string location;
    public float count;
}