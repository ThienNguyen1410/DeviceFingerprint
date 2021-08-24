//
// Created by Thien on 8/24/21.
//

#ifndef DEVICEINFO_IDENTIFIERS_H
#define DEVICEINFO_IDENTIFIERS_H


#include <jni.h>

class Identifiers {
public:
    jstring getAndroidId(JNIEnv *env, jobject obj);

    jobject getWifiManagerObj(JNIEnv *env, jobject obj);

    jobject getWifiInfoObj(JNIEnv *env, jobject wifiMgrObj);

    jstring getMacAddress(JNIEnv *env, jobject wifiInfoObj);

//    jstring getSerial(JNIEnv *env);
    jobject telephonyManager(JNIEnv *env, jobject obj);

    jstring simProvider(JNIEnv *env, jobject mgr);

    int simState(JNIEnv *env, jobject teleMgr);

};


#endif //DEVICEINFO_IDENTIFIERS_