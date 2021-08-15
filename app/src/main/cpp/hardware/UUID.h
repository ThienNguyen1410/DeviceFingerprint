//
// Created by Thien on 8/15/21.
//

#ifndef DEVICEINFO_UUID_H
#define DEVICEINFO_UUID_H


#include <jni.h>

class UUID {
public:
    static jstring getAndroidId(JNIEnv *env, jobject obj);

    static jstring telephonyAndroidId(JNIEnv *env, jobject teleMgr);

    static jobject telephonyManager(JNIEnv *env, jobject obj);

    static jstring getSerial(JNIEnv *env);

};


#endif //DEVICEINFO_UUID_H
