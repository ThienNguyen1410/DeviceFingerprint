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

};


#endif //DEVICEINFO_NETWORKINFO_H
