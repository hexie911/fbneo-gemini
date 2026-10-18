package com.example.fbneo;
import android.os.Bundle;
import android.view.MotionEvent;
import androidx.appcompat.app.AppCompatActivity;
public class MainActivity extends AppCompatActivity {
    static { System.loadLibrary("fbneo_native"); }
    public native boolean nativeInit(String romPath);
    public native void nativeRunFrame();
    public native void nativeSetButtonState(int buttonId, boolean pressed);
    public native boolean nativeLoadLuaScript(String scriptPath);
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        nativeInit("/sdcard/Download/sfiii3nr1.zip");
        nativeLoadLuaScript("/sdcard/Download/3rd_training.lua");
    }
    public void handleArcadeButtonTouch(int buttonId, MotionEvent event) {
        if (event.getAction() == MotionEvent.ACTION_DOWN) {
            nativeSetButtonState(buttonId, true);
        } else if (event.getAction() == MotionEvent.ACTION_UP || event.getAction() == MotionEvent.ACTION_CANCEL) {
            nativeSetButtonState(buttonId, false);
        }
    }
}
