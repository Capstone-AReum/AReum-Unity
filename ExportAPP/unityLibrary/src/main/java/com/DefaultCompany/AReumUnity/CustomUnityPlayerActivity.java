package com.DefaultCompany.AReumUnity;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import com.unity3d.player.UnityPlayerActivity;
import com.unity3d.player.UnityPlayer;

public class CustomUnityPlayerActivity extends UnityPlayerActivity {
    private static final int PICK_FILE_REQUEST = 1000;

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if (requestCode == PICK_FILE_REQUEST && resultCode == Activity.RESULT_OK) {
            if (data != null && data.getData() != null) {
                String filePath = data.getData().getPath();

                // Unity에 파일 경로 전달
                UnityPlayer.UnitySendMessage("AndroidFilePicker", "OnFileSelected", filePath);
            }
        }
    }
}
