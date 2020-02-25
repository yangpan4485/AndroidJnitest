//
// Created by yangpan4485 on 2020-02-24.
//

#ifndef VERIFYTEST_JNI_HELPER_H
#define VERIFYTEST_JNI_HELPER_H

#include <jni.h>
#include <string>

struct VerifyFields {
    struct {
        jfieldID verify_instance;
    } native_object;

    struct {
        jmethodID onTransmitter;
    }verify_callback;
};

/// 获取缓存的 Fields
VerifyFields &GetVerifyFields();

/// 获取当前线程的 Env
JNIEnv *GetJNIEnv();

void DetachCurrentThread();

/// 把 jstring 转换为 std::string
std::string JstringToString(JNIEnv* env,jstring val);

#endif //VERIFYTEST_JNI_HELPER_H
