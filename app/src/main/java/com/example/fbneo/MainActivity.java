package com.example.fbneo;

import android.os.Bundle;
import android.view.MotionEvent;
import android.widget.Button;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("fbneo_native");
    }

    public native boolean nativeInit(String romPath);
    public native void nativeRunFrame();
    public native void nativeSetButtonState(int buttonId, boolean pressed);
    public native boolean nativeLoadLuaScript(String scriptPath);

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        String sampleRom = "/sdcard/Download/sfiii3nr1.zip";
        nativeInit(sampleRom);

        String sampleScript = "/sdcard/Download/3rd_training.lua";
        nativeLoadLuaScript(sampleScript);
    }

    // Call this from your touch screen buttons layout
    // buttonId: 0=LP, 1=MP, 2=HP, 3=LK, 4=MK, 5=HK
    public void handleArcadeButtonTouch(int buttonId, MotionEvent event) {
        if (event.getAction() == MotionEvent.ACTION_DOWN) {
            nativeSetButtonState(buttonId, true);
        } else if (event.getAction() == MotionEvent.ACTION_UP || event.getAction() == MotionEvent.ACTION_CANCEL) {
            nativeSetButtonState(buttonId, false);
        }
    }
}
