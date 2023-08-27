#include <jni.h>
#include <string>
#include "jiami/md5.h"
#include "android/log.h"


#define TAG "XIGUA(so)"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__);
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO , TAG, __VA_ARGS__);
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__);



extern "C" JNIEXPORT jstring JNICALL
Java_com_example_hookdemo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


extern "C" JNIEXPORT jstring JNICALL
Java_com_example_hookdemo_MainActivity_MD5(JNIEnv* env,jobject obj,jstring s1){
    MD5_CTX context;
    MD5Init(&context);

    const char *javaString = env->GetStringUTFChars(s1, NULL);
    MD5Update(&context, (unsigned char *) javaString, strlen(javaString));

    unsigned char result[16];
    MD5Final(&context, result);

    char finalResult[33] = {0};
    for(int i = 0; i < 16; i++){
        char temp[3] = {0};  // Two characters for hex digit + null terminator
        sprintf(temp, "%.2x", result[i]);
        strcat(finalResult, temp);
    }
    return env->NewStringUTF(finalResult);
}