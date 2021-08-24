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
#include "hardware/Identifiers.h"
#include "software/SoftwareInfo.h"
#include "permission/CheckPermission.h"
#include "HandleException.h"

HardwareInfo hardwareInfo;
Identifiers identifiers;

extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getModel(JNIEnv *env, jobject thiz) {
    return hardwareInfo.getModel(env);

}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getDevice(JNIEnv *env, jobject thiz) {
    return hardwareInfo.getDevice(env);
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
    return hardwareInfo.getBuildNumber(env);
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getMac(JNIEnv *env, jobject thiz) {
    jstring mac;
    if (CheckPermission::hasPermission(env, "ACCESS_FINE_LOCATION", thiz)) {
        jobject wifi_manager = identifiers.getWifiManagerObj(env, thiz);
        jobject wifi_info = identifiers.getWifiInfoObj(env, wifi_manager);
        mac = identifiers.getMacAddress(env, wifi_info);
        return mac;
    }
    return env->NewStringUTF("");
}



extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getID(JNIEnv *env, jobject thiz) {
    return hardwareInfo.getID(env);
}extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getBootloader(JNIEnv *env, jobject thiz) {
    return hardwareInfo.getBootloader(env);
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getBrand(JNIEnv *env, jobject thiz) {
    return hardwareInfo.getBrand(env);
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getFP(JNIEnv *env, jobject thiz) {
    return hardwareInfo.getFingerPrint(env);
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getHardware(JNIEnv *env, jobject thiz) {
    return hardwareInfo.getHardWare(env);

}extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getHost(JNIEnv *env, jobject thiz) {
    return hardwareInfo.getHost(env);

}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getManufacture(JNIEnv *env, jobject thiz) {
    return hardwareInfo.getManufacture(env);
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getProduct(JNIEnv *env, jobject thiz) {
    return hardwareInfo.getProduct(env);
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_thien_deviceinfo_MainActivity_testCheckPerm(JNIEnv *env, jobject thiz) {
    jboolean check = CheckPermission::hasPermission(env, "ACCESS_WIFI_STATE", thiz);
    return check;
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getAndroidID(JNIEnv *env, jobject thiz) {
    return identifiers.getAndroidId(env, thiz);

}


extern "C"
JNIEXPORT jint JNICALL
Java_com_thien_deviceinfo_MainActivity_batteryCapacity(JNIEnv *env, jobject thiz) {
    jobject bm = hardwareInfo.batteryManager(env, thiz);
    return hardwareInfo.batteryCapacity(env, bm);

}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_simSerial(JNIEnv *env, jobject thiz) {
    jobject telephonyManager = identifiers.telephonyManager(env, thiz);
    return identifiers.simProvider(env, telephonyManager);
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_user(JNIEnv *env, jobject thiz) {
    return hardwareInfo.user(env);

}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_thien_deviceinfo_MainActivity_installedPackage(JNIEnv *env, jobject thiz) {
    jobject pm = hardwareInfo.packageManager(env, thiz);
    jint flag = hardwareInfo.flagPackageManager(env);
    jobjectArray list_package = hardwareInfo.listPackageInstalled(env, pm, flag);
    return list_package;
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_thien_deviceinfo_MainActivity_longitude(JNIEnv *env, jobject thiz) {
    jobject locationManager = hardwareInfo.locationManager(env, thiz);
    jobject locationInfo = hardwareInfo.location(env, locationManager);
    jdouble longitude = hardwareInfo.longitude(env, locationInfo);

    return longitude;
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_thien_deviceinfo_MainActivity_latitude(JNIEnv *env, jobject thiz) {
    jobject locationManager = hardwareInfo.locationManager(env, thiz);
    jobject locationInfo = hardwareInfo.location(env, locationManager);
    jdouble latitude = hardwareInfo.latitude(env, locationInfo);

    return latitude;
}

extern "C"
JNIEXPORT jobjectArray JNICALL
Java_com_thien_deviceinfo_MainActivity_securityProvider(JNIEnv *env, jobject thiz) {
    return hardwareInfo.sercurityProvider(env, thiz);
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_thien_deviceinfo_MainActivity_isSecurityEncrypt(JNIEnv *env, jobject thiz) {
    jobject mgr = hardwareInfo.devicePolicyMgr(env, thiz);
    return hardwareInfo.isEncrypt(env, mgr);
}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_thien_deviceinfo_MainActivity_getTime(JNIEnv *env, jobject thiz) {
    jobject calendar = hardwareInfo.calendarInstance(env, thiz);
    jobject time = hardwareInfo.dateAndTime(env, calendar);
    return time;
}