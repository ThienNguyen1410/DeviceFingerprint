//Java
#include <jni.h>
//C++
#include <iostream>
#include <fstream>
#include <memory>
//Android
#include <android/log.h>
#include <jni.h>
#include "HardwareInfo.h"
#include "SoftwareInfo.h"
#include "HandleException.h"

extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getModel(JNIEnv *env, jobject thiz) {
    return HardwareInfo::getModel(env);
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getBrand(JNIEnv *env, jobject thiz) {
    return HardwareInfo::getDevice(env);
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_thien_deviceinfo_MainActivity_getSdk(JNIEnv *env, jobject thiz) {
    return SoftwareInfo::getSDK(env);

}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getSecurityPatch(JNIEnv *env, jobject thiz) {
    return SoftwareInfo::getSecurityPatch(env);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getAndroidVersion(JNIEnv *env, jobject thiz) {
    return SoftwareInfo::getAndroidVersion(env);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getBaseOs(JNIEnv *env, jobject thiz) {
    return SoftwareInfo::getBaseOs(env);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getBuildNumber(JNIEnv *env, jobject thiz) {
    return HardwareInfo::getBuildNumber(env);
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_testmac(JNIEnv *env, jobject thiz) {

}

