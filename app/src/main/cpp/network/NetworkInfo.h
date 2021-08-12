//
// Created by Thien on 8/9/21.
//

#ifndef DEVICEINFO_NETWORKINFO_H
#define DEVICEINFO_NETWORKINFO_H


#include <jni.h>

class NetworkInfo {
public:
    static jstring getMac(JNIEnv *env);

    static jobject getWifiManagerObj(JNIEnv *env, jobject jCtxObj);

    static jobject getWifiInfoObj(JNIEnv *env, jobject wifiMgrObj);

    static jstring getMacAddress(JNIEnv *env, jobject wifiInfoObj);

    static jstring permission(JNIEnv *env, const char *name);

    static bool checkPermission(JNIEnv *env, const char *name, jobject obj);
};


#endif //DEVICEINFO_NETWORKINFO_H
