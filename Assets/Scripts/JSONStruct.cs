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
public class ApiResponse
{
    public int id;
    public string title;
    public string created_at;
    public List<PhotoItem> items;
}
