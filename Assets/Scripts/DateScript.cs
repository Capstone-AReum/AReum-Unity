using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using TMPro;

public class DateScript : MonoBehaviour
{
    public TMP_Text ScriptTxt;

    // Start is called before the first frame update
    void Start()
    {
        ScriptTxt.text = GetCurrentDate();
    }

    public static string GetCurrentDate(){
        return DateTime.Now.ToString(("MM월 dd일 dddd"));
    }
}
