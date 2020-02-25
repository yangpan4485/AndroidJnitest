#include "verify_class_jni.h"

#include <android/log.h>
#include <pthread.h>
#include <stdlib.h>
#include <future>
#include <iostream>

#include "jni_helper.h"
#include "include/verify/verify_class.h"

#define TAG "verify-class-jni"  // 这个是自定义的LOG的标识
#define LOGD(...) \
    __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)  // 定义LOGD类型


JNIEXPORT jlong JNICALL Java_com_example_verify_VerifyClass_createObject
  (JNIEnv *env, jobject obj){
  VerifyClass* verify_clz = new VerifyClass();
  return (jlong)verify_clz;
}

JNIEXPORT void JNICALL Java_com_example_verify_VerifyClass_setValue
  (JNIEnv *env, jobject obj, jlong verify, jint key, jstring value){
  VerifyClass* verify_clz = (VerifyClass*)verify;
  int i_key = key;
  std::string str_value = JstringToString(env,value);
  verify_clz->SetValue(key,str_value);
}

JNIEXPORT jstring JNICALL Java_com_example_verify_VerifyClass_getValue
  (JNIEnv *env, jobject obj, jlong verify, jint key){
  int i_key = key;
  VerifyClass* verify_clz = (VerifyClass*)verify;
  std::string str_value = verify_clz->GetValue(i_key);
  return env->NewStringUTF(str_value.c_str());
}

