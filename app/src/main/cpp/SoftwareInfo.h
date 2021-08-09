//
// Created by Thien on 8/8/21.
//

#ifndef DEVICEINFO_SOFTWAREINFO_H
#define DEVICEINFO_SOFTWAREINFO_H


#include <jni.h>

class SoftwareInfo {
public:
    static jint getSDK(JNIEnv *env);
    static jstring getSecurityPatch(JNIEnv *env);
    static jstring getAndroidVersion(JNIEnv *env);
    static jstring getBaseOs(JNIEnv *env);

};


#endif //DEVICEINFO_SOFTWAREINFO_H
