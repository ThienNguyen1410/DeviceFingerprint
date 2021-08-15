//
// Created by Thien on 8/15/21.
//

#ifndef DEVICEINFO_CLASSUTILS_H
#define DEVICEINFO_CLASSUTILS_H


#include <jni.h>

class ClassUtils {
public:
    static jclass context(JNIEnv *env);

    static jclass androidBuildVersion(JNIEnv *env);

    static jclass androidBuild(JNIEnv *env);

    static jclass androidSettingSecure(JNIEnv *env);
};


#endif //DEVICEINFO_CLASSUTILS_H
