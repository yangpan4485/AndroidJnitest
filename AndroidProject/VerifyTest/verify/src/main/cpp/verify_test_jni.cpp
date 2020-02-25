#include "verify_test_jni.h"

#include <android/log.h>
#include <pthread.h>
#include <stdlib.h>
#include <future>
#include <iostream>

#include "jni_helper.h"
#include "include/verify/verify_test.h"

#define TAG "verify-class-jni"  // 这个是自定义的LOG的标识
#define LOGD(...) \
    __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)  // 定义LOGD类型

JNIEXPORT jint JNICALL Java_com_example_verify_VerifyTest_getRandValue
  (JNIEnv *env, jobject obj){
  uint32_t val = GetRandValue();
  return val;
}


JNIEXPORT jstring JNICALL Java_com_example_verify_VerifyTest_getStringValue
  (JNIEnv *env, jobject obj){
  std::string str = GetStringValue();
  return env->NewStringUTF(str.c_str());
}

