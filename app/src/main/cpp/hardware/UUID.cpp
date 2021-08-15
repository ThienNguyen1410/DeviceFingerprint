//
// Created by Thien on 8/15/21.
//

#include "UUID.h"
#include "HandleException.h"
#include "utils/ClassUtils.h"

jstring UUID::getAndroidId(JNIEnv *env, jobject obj) {
    jclass context = ClassUtils::context(env);
    jmethodID mid_contentResolver = env->GetMethodID(context, "getContentResolver",
                                                     "()Landroid/content/ContentResolver;");

    jobject resolverInstance = env->CallObjectMethod(obj, mid_contentResolver);
    jclass cls_androidSecure = env->FindClass("android/provider/Settings$Secure");

    jfieldID fid_androidId = env->GetStaticFieldID(cls_androidSecure, "ANDROID_ID",
                                                   "Ljava/lang/String;");

    auto jstr_androidID = (jstring) env->GetStaticObjectField(cls_androidSecure, fid_androidId);
    jmethodID mid_getString = env->GetStaticMethodID(cls_androidSecure, "getString",
                                                     "(Landroid/content/ContentResolver;Ljava/lang/String;)Ljava/lang/String;");

    auto androidId = (jstring) env->CallStaticObjectMethod(cls_androidSecure, mid_getString,
                                                           resolverInstance, jstr_androidID);
    env->DeleteLocalRef(context);
    env->DeleteLocalRef(resolverInstance);
    env->DeleteLocalRef(cls_androidSecure);
    env->DeleteLocalRef(jstr_androidID);

    return androidId;
}

jstring UUID::getSerial(JNIEnv *env) {
    jclass cls = ClassUtils::androidBuild(env);
    jmethodID methodId = env->GetStaticMethodID(cls, "getSerial", "()Ljava/lang/String;");
    HandleException::handleException(env);
    auto serial = (jstring) env->CallStaticObjectMethod(cls, methodId);
    env->DeleteLocalRef(cls);
    return serial;
}

jstring UUID::telephonyAndroidId(JNIEnv *env, jobject obj) {
    jclass context = env->FindClass("android/content/Context");
    jfieldID fid_TEL_SERVICE = env->GetStaticFieldID(context, "TELEPHONY_SERVICE",
                                                     "Ljava/lang/String;");
    HandleException::handleException(env);
    auto TELEPHONE_SERVICE = (jstring) env->GetStaticObjectField(context, fid_TEL_SERVICE);
    jclass cls = env->GetObjectClass(obj);
    jmethodID mid_getSysService = env->GetMethodID(cls, "getSystemService",
                                                   "(Ljava/lang/String;)Ljava/lang/Object;");
    jobject telephonyManager = env->CallObjectMethod(obj, mid_getSysService, TELEPHONE_SERVICE);

    jclass cls_TeleMgr = env->FindClass("android/telephony/TelephonyManager");
    jmethodID mid_getAndroidID = env->GetMethodID(cls_TeleMgr, "getDeviceId",
                                                  "()Ljava/lang/String;");
    auto androidId = (jstring) env->CallObjectMethod(telephonyManager, mid_getAndroidID);
    env->DeleteLocalRef(context);
    env->DeleteLocalRef(cls);
    env->DeleteLocalRef(cls_TeleMgr);
    env->DeleteLocalRef(telephonyManager);

    return androidId;
}
