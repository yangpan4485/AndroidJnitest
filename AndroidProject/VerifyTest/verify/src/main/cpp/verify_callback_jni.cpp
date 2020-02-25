#include "verify_callback_jni.h"

#include <android/log.h>
#include <pthread.h>
#include <stdlib.h>
#include <future>
#include <iostream>

#include "jni_helper.h"
#include "verify_callback.h"

#define TAG "verify-callback-jni"  // 这个是自定义的LOG的标识
#define LOGD(...) \
    __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)  // 定义LOGD类型


jobject verify_obj;

JNIEXPORT void JNICALL Java_com_example_verify_VerifyCallback_start
  (JNIEnv *env, jobject obj){
    Start();
}


JNIEXPORT void JNICALL Java_com_example_verify_VerifyCallback_stop
  (JNIEnv *env, jobject obj){
    Stop();
}

void HandlerCallback(int val){
    auto jni_env = GetJNIEnv();
    auto verify_id = GetVerifyFields().verify_callback.onTransmitter;
    jni_env->CallVoidMethod(verify_obj, verify_id, val);
    DetachCurrentThread();

}

JNIEXPORT void JNICALL Java_com_example_verify_VerifyCallback_startListenTransmitter
  (JNIEnv *env, jobject obj){
    jobject mobj = env->GetObjectField(
            obj, GetVerifyFields().native_object.verify_instance);
    verify_obj = env->NewGlobalRef(mobj);

    LOGD("###Start");

        RegisteCallback([](int val) {
            LOGD("###kCallback");
            HandlerCallback(val);
         });
  }