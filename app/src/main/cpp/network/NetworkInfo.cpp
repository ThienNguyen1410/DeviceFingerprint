//
// Created by Thien on 8/9/21.
//

#include "NetworkInfo.h"
#include "software/SoftwareInfo.h"
#include "HandleException.h"
#include <iostream>
#include <fstream>
#include <memory>
#include <android/log.h>

jstring NetworkInfo::getMac(JNIEnv *env) {
    std::fstream file;
    std::string mac;
    std::string path = "/sys/class/net/wlan0/address";

    if (SoftwareInfo::getSDK(env) >= 28) {
        path = "/sys/class/net/p2p0/address";
    }
    file.open(path, std::ios::in);
    if (!file) {
        return env->NewStringUTF("File not found");
    }
    file >> mac;
    file.close();
    return env->NewStringUTF(mac.c_str());

}

jobject NetworkInfo::getWifiManagerObj(JNIEnv *env, jobject jCtxObj) {
    jclass jCtxClz = env->FindClass("android/content/Context");
    HandleException::handleException(env);
    jfieldID fid_wifi_service = env->GetStaticFieldID(jCtxClz, "WIFI_SERVICE",
                                                      "Ljava/lang/String;");
    jstring jstr_wifi_serveice = (jstring) env->GetStaticObjectField(jCtxClz, fid_wifi_service);

    jclass jclz = env->GetObjectClass(jCtxObj);
    jmethodID mid_getSystemService = env->GetMethodID(jclz, "getSystemService",
                                                      "(Ljava/lang/String;)Ljava/lang/Object;");
    jobject wifiManager = env->CallObjectMethod(jCtxObj, mid_getSystemService, jstr_wifi_serveice);

    env->DeleteLocalRef(jCtxClz);
    env->DeleteLocalRef(jclz);
    env->DeleteLocalRef(jstr_wifi_serveice);
    return wifiManager;
}

jobject NetworkInfo::getWifiInfoObj(JNIEnv *env, jobject wifiMgrObj) {
    if (wifiMgrObj == nullptr) {
        return nullptr;
    }
    jclass jclz = env->GetObjectClass(wifiMgrObj);
    jmethodID mid = env->GetMethodID(jclz, "getConnectionInfo", "()Landroid/net/wifi/WifiInfo;");
    jobject wifiInfo = env->CallObjectMethod(wifiMgrObj, mid);

    env->DeleteLocalRef(jclz);
    return wifiInfo;
}

jstring NetworkInfo::getMacAddress(JNIEnv *env, jobject wifiInfoObj) {
    if (wifiInfoObj == nullptr) {
        return nullptr;
    }
    jclass jclz = env->GetObjectClass(wifiInfoObj);
    HandleException::handleException(env);
    jmethodID mid = env->GetMethodID(jclz, "getMacAddress", "()Ljava/lang/String;");
    HandleException::handleException(env);
    auto mac = (jstring) env->CallObjectMethod(wifiInfoObj, mid);
    HandleException::handleException(env);
    env->DeleteLocalRef(jclz);
    return mac;
}
