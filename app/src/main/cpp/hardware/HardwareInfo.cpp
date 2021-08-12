//
// Created by Thien on 8/7/21.
//
#include <jni.h>
#include <cstdio>
#include "HardwareInfo.h"
#include "HandleException.h"
#include <android/log.h>

jclass HardwareInfo::getCls(JNIEnv *env) {
	jclass cls = env->FindClass("android/os/Build");
	HandleException::handleException(env);
	return cls;
}

jstring HardwareInfo::getBootloader(JNIEnv *env) {
	jclass cls = getCls(env);
	jfieldID fieldId = env->GetStaticFieldID(cls, "BOOTLOADER", "Ljava/lang/String;");
	HandleException::handleException(env);
	auto bootloader = (jstring) env->GetStaticObjectField(cls, fieldId);
	env->DeleteLocalRef(cls);
	return bootloader;
}

jstring HardwareInfo::getBrand(JNIEnv *env) {
	jclass cls = getCls(env);
	jfieldID fieldId = env->GetStaticFieldID(cls, "BOARD", "Ljava/lang/String;");
	HandleException::handleException(env);
	auto brand = (jstring) env->GetStaticObjectField(cls, fieldId);
	env->DeleteLocalRef(cls);
	return brand;
}

jstring HardwareInfo::getDevice(JNIEnv *env) {
	jclass cls = getCls(env);
	jfieldID fieldId = env->GetStaticFieldID(cls, "DEVICE", "Ljava/lang/String;");
	HandleException::handleException(env);
	auto device = (jstring) env->GetStaticObjectField(cls, fieldId);
	env->DeleteLocalRef(cls);
	return device;
}

jstring HardwareInfo::getBuildNumber(JNIEnv *env) {
	jclass cls = getCls(env);
	jfieldID fieldId = env->GetStaticFieldID(cls, "DISPLAY", "Ljava/lang/String;");
	HandleException::handleException(env);
	auto buildNum = (jstring) env->GetStaticObjectField(cls, fieldId);
	env->DeleteLocalRef(cls);
	return buildNum;
}

jstring HardwareInfo::getFingerPrint(JNIEnv *env) {
	jclass cls = getCls(env);
	jfieldID fieldId = env->GetStaticFieldID(cls, "FINGERPRINT", "Ljava/lang/String;");
	HandleException::handleException(env);
	auto fp = (jstring) env->GetStaticObjectField(cls, fieldId);
	env->DeleteLocalRef(cls);
	return fp;
}

jstring HardwareInfo::getHardWare(JNIEnv *env) {
	jclass cls = getCls(env);
	jfieldID fieldId = env->GetStaticFieldID(cls, "HARDWARE", "Ljava/lang/String;");
	HandleException::handleException(env);
	auto hardware = (jstring) env->GetStaticObjectField(cls, fieldId);
	env->DeleteLocalRef(cls);
	return hardware;
}

jstring HardwareInfo::getID(JNIEnv *env) {
	jclass cls = getCls(env);
	jfieldID fieldId = env->GetStaticFieldID(cls, "ID", "Ljava/lang/String;");
	HandleException::handleException(env);
	auto id = (jstring) env->GetStaticObjectField(cls, fieldId);
	env->DeleteLocalRef(cls);
	return id;
}

jstring HardwareInfo::getHost(JNIEnv *env) {
	jclass cls = getCls(env);
	jfieldID fieldId = env->GetStaticFieldID(cls, "HOST", "Ljava/lang/String;");
	HandleException::handleException(env);
	auto host = (jstring) env->GetStaticObjectField(cls, fieldId);
	env->DeleteLocalRef(cls);
	return host;
}

jstring HardwareInfo::getManufacture(JNIEnv *env) {
	jclass cls = getCls(env);
	jfieldID fieldId = env->GetStaticFieldID(cls, "MANUFACTURER", "Ljava/lang/String;");
	HandleException::handleException(env);
	auto manu = (jstring) env->GetStaticObjectField(cls, fieldId);
	env->DeleteLocalRef(cls);
	return manu;
}

jstring HardwareInfo::getModel(JNIEnv *env) {
	jclass cls = getCls(env);
	jfieldID fieldId = env->GetStaticFieldID(cls, "MODEL", "Ljava/lang/String;");
	HandleException::handleException(env);
	auto model = (jstring) env->GetStaticObjectField(cls, fieldId);
	env->DeleteLocalRef(cls);
	return model;
}

jstring HardwareInfo::getProduct(JNIEnv *env) {
	jclass cls = getCls(env);
	jfieldID fieldId = env->GetStaticFieldID(cls, "PRODUCT", "Ljava/lang/String;");
	HandleException::handleException(env);
	auto product = (jstring) env->GetStaticObjectField(cls, fieldId);
	env->DeleteLocalRef(cls);
	return product;
}



//java.lang.SecurityException: getSerial: The user 10169 does not meet the requirements to access device identifiers.
//jstring HardwareInfo::getSerial(JNIEnv *env) {
//    jclass cls = env->FindClass("android/os/Build");
//    HandleException::handleException(env);
//    jmethodID methodId = env->GetStaticMethodID(cls,"getSerial", "()Ljava/lang/String;");
//    HandleException::handleException(env);
//    auto serial = (jstring) env->CallStaticObjectMethod(cls, methodId);
//    env->DeleteLocalRef(cls);
//    return serial;
//
//}
