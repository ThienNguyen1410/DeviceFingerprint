//
// Created by Thien on 8/8/21.
//

#include "SoftwareInfo.h"
#include "HandleException.h"
#include "utils/ClassUtils.h"
#include <android/log.h>

jint SoftwareInfo::getSDK(JNIEnv *env) {
    jclass cls = ClassUtils::androidBuildVersion(env);
    HandleException::handleException(env);
    jfieldID fieldId = env->GetStaticFieldID(cls, "SDK_INT", "I");
    HandleException::handleException(env);
    jint sdk = env->GetStaticIntField(cls, fieldId);
    env->DeleteLocalRef(cls);
    return sdk;
}

jstring SoftwareInfo::getSecurityPatch(JNIEnv *env) {
    jclass cls = ClassUtils::androidBuildVersion(env);
    HandleException::handleException(env);
    jfieldID fieldId = env->GetStaticFieldID(cls, "SECURITY_PATCH", "Ljava/lang/String;");
    HandleException::handleException(env);
    auto patch = (jstring) env->GetStaticObjectField(cls, fieldId);
    env->DeleteLocalRef(cls);
    return patch;
}

jstring SoftwareInfo::getAndroidVersion(JNIEnv *env) {
    jclass cls = ClassUtils::androidBuildVersion(env);
    HandleException::handleException(env);
    jfieldID fieldId = env->GetStaticFieldID(cls, "RELEASE", "Ljava/lang/String;");
    HandleException::handleException(env);
    auto version = (jstring) env->GetStaticObjectField(cls, fieldId);
    env->DeleteLocalRef(cls);
    return version;
}


jstring SoftwareInfo::getBaseOs(JNIEnv *env) {
    jclass cls = ClassUtils::androidBuildVersion(env);
    HandleException::handleException(env);
    jfieldID fieldId = env->GetStaticFieldID(cls, "BASE_OS", "Ljava/lang/String;");
    HandleException::handleException(env);
    auto baseOs = (jstring) env->GetStaticObjectField(cls, fieldId);
    env->DeleteLocalRef(cls);
    return baseOs;
}