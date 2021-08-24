//
// Created by Thien on 8/15/21.
//

#include "ClassUtils.h"
#include "HandleException.h"


jclass ClassUtils::context(JNIEnv *env) {
    jclass context = env->FindClass("android/content/Context");
    if (context != nullptr) {
        HandleException::handleException(env);
        return context;
    }
    return nullptr;
}

jclass ClassUtils::androidBuildVersion(JNIEnv *env) {
    jclass cls = env->FindClass("android/os/Build$VERSION");
    if (cls != nullptr) {
        HandleException::handleException(env);
        return cls;
    }
    return nullptr;
}

jclass ClassUtils::androidBuild(JNIEnv *env) {
    jclass cls = env->FindClass("android/os/Build");
    if (cls != nullptr) {
        HandleException::handleException(env);
        return cls;
    }
    return nullptr;
}

jclass ClassUtils::androidSettingSecure(JNIEnv *env) {
    jclass cls = env->FindClass("android/provider/Settings$Secure");
    if (cls != nullptr) {
        HandleException::handleException(env);
        return cls;
    }
    return nullptr;
}
