#include <jni.h>
#include <string>
#include <android/log.h>
#define LOG_TAG "FBNeoNative"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
static uint32_t current_button_state = 0;
extern "C" {
JNIEXPORT jboolean JNICALL
Java_com_example_fbneo_MainActivity_nativeInit(JNIEnv *env, jobject thiz, jstring rom_path) {
    const char *path = env->GetStringUTFChars(rom_path, 0);
    LOGI("Initializing FBNeo core with ROM: %s", path);
    env->ReleaseStringUTFChars(rom_path, path);
    return JNI_TRUE;
}
JNIEXPORT void JNICALL
Java_com_example_fbneo_MainActivity_nativeRunFrame(JNIEnv *env, jobject thiz) {}
JNIEXPORT void JNICALL
Java_com_example_fbneo_MainActivity_nativeSetButtonState(JNIEnv *env, jobject thiz, jint button_id, jboolean pressed) {
    if (pressed) { current_button_state |= (1 << button_id); } 
    else { current_button_state &= ~(1 << button_id); }
}
JNIEXPORT jboolean JNICALL
Java_com_example_fbneo_MainActivity_nativeLoadLuaScript(JNIEnv *env, jobject thiz, jstring script_path) {
    const char *path = env->GetStringUTFChars(script_path, 0);
    LOGI("Loading Lua script: %s", path);
    env->ReleaseStringUTFChars(script_path, path);
    return JNI_TRUE;
}
}
