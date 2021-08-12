//
// Created by Thien on 8/13/21.
//

#ifndef DEVICEINFO_CHECKPERMISSION_H
#define DEVICEINFO_CHECKPERMISSION_H


#include <jni.h>

class CheckPermission {
public:
    static jstring permissionName(JNIEnv *env, const char *name);

    static bool hasPermission(JNIEnv *env, const char *name, jobject obj);

};


#endif //DEVICEINFO_CHECKPERMISSION_H
