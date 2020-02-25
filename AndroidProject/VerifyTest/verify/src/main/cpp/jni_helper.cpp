#include "jni_helper.h"

#include <stdexcept>

#include <jni.h>
#include <pthread.h>
#include <sys/types.h>
#include <string>
#include <iostream>

#include <android/log.h>

#define TAG    "verify-jni" // 这个是自定义的LOG的标识
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__) // 定义LOGD类型

JavaVM *myVm = nullptr;

/// 获取缓存的 Fields
VerifyFields &GetVerifyFields(){
    static VerifyFields fields;
    return fields;
}

/// 获取当前线程的 Env
JNIEnv *GetJNIEnv(){
    JNIEnv *env = NULL;
    if ((myVm)->GetEnv((void **)&env, JNI_VERSION_1_6) != JNI_OK) {
        int status = (myVm)->AttachCurrentThread(&env, 0);
        if (status < 0) {
            LOGD("###failed to attach current thread");
            return NULL;
        }
    }
    return env;
}

void DetachCurrentThread(){
    myVm->DetachCurrentThread();
}

/// 把 jstring 转换为 std::string
std::string JstringToString(JNIEnv* env,jstring val){
    jboolean isCopy;
    const char* char_val = env->GetStringUTFChars(val, &isCopy);
    std::string str_val(char_val);
    if (isCopy == JNI_TRUE){
        env->ReleaseStringUTFChars(val, char_val);
    }
    return str_val;
}

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    myVm = vm;

    if (myVm) {
        LOGD("###m_vm init success");
    } else {
        LOGD("###m_vm init failed");
    }

    JNIEnv *env = NULL;
    if ((vm)->GetEnv((void **)&env, JNI_VERSION_1_4) != JNI_OK) { return -1; }

    VerifyFields &fields = GetVerifyFields();
    // com.example.verify;
    jclass clazz = env->FindClass("com/example/verify/VerifyCallback");
    fields.native_object.verify_instance = env->GetFieldID(
            clazz, "mTransmitterVerifyListener",
            "Lcom/example/verify/TransmitterVerifyListener;");

    clazz = env->FindClass("com/example/verify/TransmitterVerifyListener");
    fields.verify_callback.onTransmitter = env->GetMethodID(clazz,"onTransmitterVerifyValue","(I)V");

    LOGD("###m_vm init finish");
    return JNI_VERSION_1_6;
}

#undef GET_CLASS
#undef GET_ID

void JNI_OnUnload(JavaVM *vm, void *reserved) {
    JNIEnv *env = NULL;
    if ((vm)->GetEnv((void **)&env, JNI_VERSION_1_6) != JNI_OK) {
        LOGD("###get env error");
    }
    myVm = nullptr;
}
