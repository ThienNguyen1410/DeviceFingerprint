////
//// Created by Thien on 8/9/21.
////
//
//#include "NetworkInfo.h"
//#include "HandleException.h"
//
//jobject getWifiManager(JNIEnv *env,jclass cls,jobject obj){
//    jclass context = env->FindClass("android/content/Context");
//    HandleException::handleException(env);
//    jfieldID field = env->GetStaticFieldID(context,"WIFI_SERVICE", "Ljava/lang/String;");
//    HandleException::handleException(env);
//    auto wifiService = (jstring) env->GetStaticObjectField(context,field);
//    jclass jcls = env->GetObjectClass(obj);
//    jmethodID getSysService = env->GetMethodID(jcls,"getSystemService","(Ljava/lang/String;)Ljava/lang/Object;");
//    jobject wifiManager = env->CallObjectMethod(obj,getSysService,wifiService);
//    env->DeleteLocalRef(context);
//    env->DeleteLocalRef(jcls);
//    env->DeleteLocalRef(wifiService);
//
//    return wifiManager;
//
//}
//
//jobject getWifiInfo(JNIEnv *env,jobject obj) {
//    if (obj == nullptr){
//        return nullptr;
//    }
//    jclass cls = env->GetObjectClass(obj);
//    jmethodID method = env->GetMethodID(cls,"getConnectionInfo","()Landroid/net/wifi/WifiInfo;");
//    jobject wifiInfo = env->CallObjectMethod(cls,method);
//    env->DeleteLocalRef(cls);
//    return wifiInfo;
//}
//
//jstring NetworkInfo::getMac(JNIEnv *env,jobject obj) {
//    jclass cls = env->FindClass("android/net/wifi/WifiInfo");
//    HandleException::handleException(env);
//    jmethodID methodId = env->GetMethodID(cls,"getMacAddress","()Ljava/lang/String;");
//    HandleException::handleException(env);
//    auto mac = (jstring) env->CallObjectMethod(cls,methodId);
//    env->DeleteLocalRef(cls);
//    return mac;
//}
