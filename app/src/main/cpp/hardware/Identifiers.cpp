//
// Created by Thien on 8/24/21.
//

#include <utils/ClassUtils.h>
#include <HandleException.h>
#include "Identifiers.h"

jstring Identifiers::getAndroidId(JNIEnv *env, jobject obj) {
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

jobject Identifiers::getWifiManagerObj(JNIEnv *env, jobject obj) {
    jclass context = ClassUtils::context(env);
    HandleException::handleException(env);
    jfieldID fid_wifi_service = env->GetStaticFieldID(context, "WIFI_SERVICE",
                                                      "Ljava/lang/String;");
    auto jstr_wifi_serveice = (jstring) env->GetStaticObjectField(context, fid_wifi_service);

    jclass jclz = env->GetObjectClass(obj);
    jmethodID mid_getSystemService = env->GetMethodID(jclz, "getSystemService",
                                                      "(Ljava/lang/String;)Ljava/lang/Object;");
    jobject wifiManager = env->CallObjectMethod(obj, mid_getSystemService, jstr_wifi_serveice);

    env->DeleteLocalRef(context);
    env->DeleteLocalRef(jclz);
    env->DeleteLocalRef(jstr_wifi_serveice);
    return wifiManager;
}

jobject Identifiers::getWifiInfoObj(JNIEnv *env, jobject wifiMgrObj) {
    if (wifiMgrObj == nullptr) {
        return nullptr;
    }
    jclass jclz = env->GetObjectClass(wifiMgrObj);
    jmethodID mid = env->GetMethodID(jclz, "getConnectionInfo", "()Landroid/net/wifi/WifiInfo;");
    jobject wifiInfo = env->CallObjectMethod(wifiMgrObj, mid);

    env->DeleteLocalRef(jclz);
    return wifiInfo;
}

jstring Identifiers::getMacAddress(JNIEnv *env, jobject wifiInfoObj) {
    jclass jclz = env->GetObjectClass(wifiInfoObj);
    HandleException::handleException(env);
    jmethodID mid = env->GetMethodID(jclz, "getMacAddress", "()Ljava/lang/String;");
    HandleException::handleException(env);
    auto mac = (jstring) env->CallObjectMethod(wifiInfoObj, mid);
    HandleException::handleException(env);
    env->DeleteLocalRef(jclz);
    return mac;

}

jobject Identifiers::telephonyManager(JNIEnv *env, jobject obj) {
    jclass context = env->FindClass("android/content/Context");
    jfieldID fid_TEL_SERVICE = env->GetStaticFieldID(context, "TELEPHONY_SERVICE",
                                                     "Ljava/lang/String;");
    HandleException::handleException(env);
    auto TELEPHONE_SERVICE = (jstring) env->GetStaticObjectField(context, fid_TEL_SERVICE);
    jclass cls = env->GetObjectClass(obj);
    jmethodID mid_getSysService = env->GetMethodID(cls, "getSystemService",
                                                   "(Ljava/lang/String;)Ljava/lang/Object;");
    jobject telephonyManager = env->CallObjectMethod(obj, mid_getSysService, TELEPHONE_SERVICE);

    env->DeleteLocalRef(context);
    env->DeleteLocalRef(cls);

    return telephonyManager;
}

jstring Identifiers::simProvider(JNIEnv *env, jobject mgr) {
    jclass cls = env->FindClass("android/telephony/TelephonyManager");
    HandleException::handleException(env);
    jmethodID mid = env->GetMethodID(cls, "getSimCarrierIdName", "()Ljava/lang/CharSequence;");
    HandleException::handleException(env);
    auto simProvider = (jstring) env->CallObjectMethod(mgr, mid);
    env->DeleteLocalRef(cls);
    return simProvider;
}

int Identifiers::simState(JNIEnv *env, jobject teleMgr) {
    jclass cls = env->FindClass("android/telephony/TelephonyManager");
    jmethodID mid = env->GetMethodID(cls, "getSimCarrierId", "()I");
    jint sim = env->CallIntMethod(teleMgr, mid);
    env->DeleteLocalRef(cls);
    return sim;
}


//
//jstring UUID::telephonyAndroidId(JNIEnv *env, jobject telephonyManager) {
//
//    jclass cls_TeleMgr = env->FindClass("android/telephony/TelephonyManager");
//    jmethodID mid_getAndroidID = env->GetMethodID(cls_TeleMgr, "getDeviceId",
//                                                  "()Ljava/lang/String;");
//    auto androidId = (jstring) env->CallObjectMethod(telephonyManager, mid_getAndroidID);
//
//    env->DeleteLocalRef(cls_TeleMgr);
//
//}
