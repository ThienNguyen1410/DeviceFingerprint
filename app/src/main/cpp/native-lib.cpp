//Java
#include <jni.h>
//C++
#include <iostream>
#include <fstream>
#include <memory>
//Android
#include <android/log.h>
#include <jni.h>
#include "hardware/HardwareInfo.h"
#include "network/NetworkInfo.h"
#include "software/SoftwareInfo.h"
#include "HandleException.h"

extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getModel(JNIEnv *env, jobject thiz) {
    return HardwareInfo::getModel(env);
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getDevice(JNIEnv *env, jobject thiz) {
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
//extern "C"
//JNIEXPORT jstring JNICALL
//Java_com_thien_deviceinfo_MainActivity_getMac(JNIEnv *env, jobject thiz) {
//	jobject wifi_manager = NetworkInfo::getWifiManagerObj(env,thiz);
//	jobject wifi_info = NetworkInfo::getWifiInfoObj(env,wifi_manager);
//	jstring mac = NetworkInfo::getMacAddress(env,wifi_info);
//	return mac;
//}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getID(JNIEnv *env, jobject thiz) {
    return HardwareInfo::getID(env);
}extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getBootloader(JNIEnv *env, jobject thiz) {
    return HardwareInfo::getBootloader(env);
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getBrand(JNIEnv *env, jobject thiz) {
    return HardwareInfo::getBrand(env);
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getFP(JNIEnv *env, jobject thiz) {
    return HardwareInfo::getFingerPrint(env);
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getHardware(JNIEnv *env, jobject thiz) {
    return HardwareInfo::getHardWare(env);

}extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getHost(JNIEnv *env, jobject thiz) {
    return HardwareInfo::getHost(env);

}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getManufacture(JNIEnv *env, jobject thiz) {
    return HardwareInfo::getManufacture(env);
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getProduct(JNIEnv *env, jobject thiz) {
    return HardwareInfo::getProduct(env);
}

//extern "C"
//JNIEXPORT jboolean JNICALL
//Java_com_thien_deviceinfo_MainActivity_testCheckPerm(JNIEnv *env, jobject thiz) {
//	jboolean check = NetworkInfo::checkPermission(env,"READ_EXTERNAL_STORAGE",thiz);
//	return check;
//}