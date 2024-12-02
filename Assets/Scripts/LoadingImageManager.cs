using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class LoadingImageManager : MonoBehaviour
{
    public RawImage curIconImage;
    public RawImage nextIconImage;
    public RawImage curWaterImage;
    public RawImage nextWaterImage;
    public GameObject wateringCan; // 물뿌리개 이미지 오브젝트
    private float duration = 0.5f; // 각 이미지가 표시되는 시간
    private float totalDuration = 8f; // 전체 씬의 지속 시간
    private float elapsedTime = 0f; // 총 경과 시간
    private bool isCurImageActive = true;

    void Start()
    {
        // 처음에는 curImage만 활성화
        curIconImage.gameObject.SetActive(true);
        nextIconImage.gameObject.SetActive(false);
        curWaterImage.gameObject.SetActive(true);
        nextWaterImage.gameObject.SetActive(false);
        StartCoroutine(SwitchImages());
        StartCoroutine(RotateWateringCan());
    }

    IEnumerator SwitchImages()
    {
        while (elapsedTime < totalDuration)
        {
            yield return new WaitForSeconds(duration);
            elapsedTime += duration;

            // 이미지 전환
            isCurImageActive = !isCurImageActive;
            curIconImage.gameObject.SetActive(isCurImageActive);
            nextIconImage.gameObject.SetActive(!isCurImageActive);
            curWaterImage.gameObject.SetActive(isCurImageActive);
            nextWaterImage.gameObject.SetActive(!isCurImageActive);
        }
    }

    IEnumerator RotateWateringCan()
    {
        while (elapsedTime < totalDuration)
        {
            wateringCan.transform.Rotate(0, 0, 10);
            yield return new WaitForSeconds(duration);
            //elapsedTime += duration;

            wateringCan.transform.Rotate(0, 0, -10);
            yield return new WaitForSeconds(duration);
            //elapsedTime += duration;
        }
    }

    void Update()
    {
        // 전체 지속 시간이 지나면 이 씬에서 더 이상 전환하지 않음
        if (elapsedTime >= totalDuration)
        {
            curIconImage.gameObject.SetActive(false);
            nextIconImage.gameObject.SetActive(false);
            curWaterImage.gameObject.SetActive(false);
            nextWaterImage.gameObject.SetActive(false);
        }
    }
}