//
// Created by Thien on 8/7/21.
//

#ifndef DEVICEINFO_HARDWAREINFO_H
#define DEVICEINFO_HARDWAREINFO_H

#include "memory"
#include "iostream"

class HardwareInfo {
public:

    jclass getCls(JNIEnv *env);

    jstring getBootloader(JNIEnv *env);

    jstring getBrand(JNIEnv *env);

    jstring getDevice(JNIEnv *env);

    jstring getBuildNumber(JNIEnv *env);

    jstring getFingerPrint(JNIEnv *env);

    jstring getHardWare(JNIEnv *env);

    jstring getHost(JNIEnv *env);

    jstring getID(JNIEnv *env);

    jstring getManufacture(JNIEnv *env);

    jstring getModel(JNIEnv *env);

    jstring getProduct(JNIEnv *env);

    jstring user(JNIEnv *env);

//    std::string getSerial(JNIEnv *env);

    jobject batteryManager(JNIEnv *env, jobject obj);

    std::int64_t batteryCapacity(JNIEnv *env, jobject obj);

    jobjectArray sercurityProvider(JNIEnv *env, jobject obj);

    jobject devicePolicyMgr(JNIEnv *env, jobject obj);

    bool isEncrypt(JNIEnv *env, jobject mgr);

    jobject calendarInstance(JNIEnv *env, jobject obj);

    jobject dateAndTime(JNIEnv *env, jobject instance);

    jobject getResource(JNIEnv *env, jobject obj);

    jobject getConfiguration(JNIEnv *env, jobject obj);

    jobject packageManager(JNIEnv *env, jobject obj);

    jint flagPackageManager(JNIEnv *env);

    jobjectArray listPackageInstalled(JNIEnv *env, jobject pm, jint flag);

    jint getIp(JNIEnv *env, jobject wifiInfoObj);

    jstring getMac(JNIEnv *env);

    jobject locationManager(JNIEnv *env, jobject obj);

    jobject location(JNIEnv *env, jobject locationManager);

    jdouble longitude(JNIEnv *env, jobject location);

    jdouble latitude(JNIEnv *env, jobject location);

//    jobject getLocale(JNIEnv *env, jobject obj );


};


#endif //DEVICEINFO_HARDWAREINFO_H
