#include <jni.h>
#include <string>
#include <android/log.h>

#define LOG_TAG "FBNeoNative"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

// Bitmask state for controller inputs
static uint32_t current_button_state = 0;

extern "C" {

JNIEXPORT jboolean JNICALL
Java_com_example_fbneo_MainActivity_nativeInit(JNIEnv *env, jobject thiz, jstring rom_path) {
    const char *path = env->GetStringUTFChars(rom_path, 0);
    LOGI("Initializing FBNeo core with ROM: %s", path);
    
    // TODO: Initialize FBNeo driver, allocate rendering surface buffers, and setup audio streams
    
    env->ReleaseStringUTFChars(rom_path, path);
    return JNI_TRUE;
}

JNIEXPORT void JNICALL
Java_com_example_fbneo_MainActivity_nativeRunFrame(JNIEnv *env, jobject thiz) {
    // 60 FPS Emulation Loop Tick:
    // 1. Feed current_button_state into the FBNeo input drivers
    // 2. Execute one frame tick of the active arcade game driver
    // 3. Trigger active Lua script hooks (e.g., executing frame callbacks for training scripts)
}

JNIEXPORT void JNICALL
Java_com_example_fbneo_MainActivity_nativeSetButtonState(JNIEnv *env, jobject thiz, jint button_id, jboolean pressed) {
    /* 
     * Arcade 6-Button Mapping Reference:
     * 0: LP (Light Punch)
     * 1: MP (Medium Punch)
     * 2: HP (Heavy Punch)
     * 3: LK (Light Kick)
     * 4: MK (Medium Kick)
     * 5: HK (Heavy Kick)
     */
    if (pressed) {
        current_button_state |= (1 << button_id);
    } else {
        current_button_state &= ~(1 << button_id);
    }
    LOGI("Button ID %d state -> %s", button_id, pressed ? "PRESSED" : "RELEASED");
}

JNIEXPORT jboolean JNICALL
Java_com_example_fbneo_MainActivity_nativeLoadLuaScript(JNIEnv *env, jobject thiz, jstring script_path) {
    const char *path = env->GetStringUTFChars(script_path, 0);
    LOGI("Loading Lua script / training mod: %s", path);
    
    // TODO: Initialize Lua state (e.g., LuaJIT) and load/execute the target .lua file
    
    env->ReleaseStringUTFChars(script_path, path);
    return JNI_TRUE;
}

} // extern "C"
