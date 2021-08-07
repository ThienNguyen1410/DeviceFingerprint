//Java
#include <jni.h>
//C++
#include <iostream>
#include <fstream>
#include <memory>
//Android
#include <android/log.h>
#include <jni.h>
#include "HardwareInfo.h"
#include "HandleException.h"
jstring getMac(JNIEnv *env) {
    std::fstream my_file;
    std::string mac;
    std::string path = "/sys/class/net/wlan0/address";
    jint sdk;
    jclass cls;
    jfieldID getSdk;

    cls = env->FindClass("android/os/Build$VERSION");
    HandleException::handleException(env);
    return env->NewStringUTF("");

    getSdk = env->GetStaticFieldID(cls, "SDK_INT", "I");

    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
        return env->NewStringUTF("");

    }
    sdk = env->GetStaticIntField(cls, getSdk);
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
        return env->NewStringUTF("");
    }
    env->DeleteLocalRef(cls);


    if (sdk >= 28) {
        path = "/sys/class/net/p2p0/address";
    }

    my_file.open(path, std::ios::in);
    if (!my_file) {
        return env->NewStringUTF("File not found");
    }

    my_file >> mac;
    my_file.close();

    return env->NewStringUTF(mac.c_str());

}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getModel(JNIEnv *env, jobject thiz) {
    return HardwareInfo::getModel(env);
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_thien_deviceinfo_MainActivity_getBrand(JNIEnv *env, jobject thiz) {
    return HardwareInfo::getDevice(env);
}
