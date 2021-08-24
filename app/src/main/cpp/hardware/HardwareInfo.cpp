//
// Created by Thien on 8/7/21.
//
#include <jni.h>
#include <cstdio>
#include "HardwareInfo.h"
#include "HandleException.h"
#include "software/SoftwareInfo.h"
#include "utils/ClassUtils.h"
#include <android/log.h>
#include <fstream>


jclass HardwareInfo::getCls(JNIEnv *env) {
    jclass cls = env->FindClass("android/os/Build");
    HandleException::handleException(env);
    return cls;
}

jstring HardwareInfo::getBootloader(JNIEnv *env) {
    jclass cls = getCls(env);
    HandleException::handleException(env);
    jfieldID fieldId = env->GetStaticFieldID(cls, "BOOTLOADER", "Ljava/lang/String;");
    HandleException::handleException(env);
    auto bootloader = (jstring) env->GetStaticObjectField(cls, fieldId);
    env->DeleteLocalRef(cls);
    return bootloader;
}

jstring HardwareInfo::getBrand(JNIEnv *env) {
    jclass cls = getCls(env);
    HandleException::handleException(env);
    jfieldID fieldId = env->GetStaticFieldID(cls, "BOARD", "Ljava/lang/String;");
    HandleException::handleException(env);
    auto brand = (jstring) env->GetStaticObjectField(cls, fieldId);
    env->DeleteLocalRef(cls);
    return brand;
}

jstring HardwareInfo::getDevice(JNIEnv *env) {
    jclass cls = getCls(env);
    HandleException::handleException(env);
    jfieldID fieldId = env->GetStaticFieldID(cls, "DEVICE", "Ljava/lang/String;");
    HandleException::handleException(env);
    auto device = (jstring) env->GetStaticObjectField(cls, fieldId);
    env->DeleteLocalRef(cls);
    return device;
}

jstring HardwareInfo::getBuildNumber(JNIEnv *env) {
    jclass cls = getCls(env);
    HandleException::handleException(env);
    jfieldID fieldId = env->GetStaticFieldID(cls, "DISPLAY", "Ljava/lang/String;");
    HandleException::handleException(env);
    auto buildNum = (jstring) env->GetStaticObjectField(cls, fieldId);
    env->DeleteLocalRef(cls);
    return buildNum;
}

jstring HardwareInfo::getFingerPrint(JNIEnv *env) {
    jclass cls = getCls(env);
    HandleException::handleException(env);
    jfieldID fieldId = env->GetStaticFieldID(cls, "FINGERPRINT", "Ljava/lang/String;");
    HandleException::handleException(env);
    auto fp = (jstring) env->GetStaticObjectField(cls, fieldId);
    env->DeleteLocalRef(cls);
    return fp;
}

jstring HardwareInfo::getHardWare(JNIEnv *env) {
    jclass cls = getCls(env);
    HandleException::handleException(env);
    jfieldID fieldId = env->GetStaticFieldID(cls, "HARDWARE", "Ljava/lang/String;");
    HandleException::handleException(env);
    auto hardware = (jstring) env->GetStaticObjectField(cls, fieldId);
    env->DeleteLocalRef(cls);
    return hardware;
}

jstring HardwareInfo::getID(JNIEnv *env) {
    jclass cls = getCls(env);
    HandleException::handleException(env);
    jfieldID fieldId = env->GetStaticFieldID(cls, "ID", "Ljava/lang/String;");
    HandleException::handleException(env);
    auto id = (jstring) env->GetStaticObjectField(cls, fieldId);
    env->DeleteLocalRef(cls);
    return id;
}

jstring HardwareInfo::getHost(JNIEnv *env) {
    jclass cls = getCls(env);
    HandleException::handleException(env);
    jfieldID fieldId = env->GetStaticFieldID(cls, "HOST", "Ljava/lang/String;");
    HandleException::handleException(env);
    auto host = (jstring) env->GetStaticObjectField(cls, fieldId);
    env->DeleteLocalRef(cls);
    return host;
}

jstring HardwareInfo::getManufacture(JNIEnv *env) {
    jclass cls = getCls(env);
    HandleException::handleException(env);
    jfieldID fieldId = env->GetStaticFieldID(cls, "MANUFACTURER", "Ljava/lang/String;");
    HandleException::handleException(env);
    auto manu = (jstring) env->GetStaticObjectField(cls, fieldId);
    env->DeleteLocalRef(cls);
    return manu;
}

jstring HardwareInfo::getModel(JNIEnv *env) {
    jclass cls = getCls(env);
    HandleException::handleException(env);
    jfieldID fieldId = env->GetStaticFieldID(cls, "MODEL", "Ljava/lang/String;");
    HandleException::handleException(env);
    auto model = (jstring) env->GetStaticObjectField(cls, fieldId);
    env->DeleteLocalRef(cls);
    return model;
}

jstring HardwareInfo::getProduct(JNIEnv *env) {
    jclass cls = ClassUtils::androidBuild(env);
    HandleException::handleException(env);
    jfieldID fieldId = env->GetStaticFieldID(cls, "PRODUCT", "Ljava/lang/String;");
    HandleException::handleException(env);
    auto product = (jstring) env->GetStaticObjectField(cls, fieldId);
    env->DeleteLocalRef(cls);
    return product;
}

jstring HardwareInfo::user(JNIEnv *env) {
    jclass cls = ClassUtils::androidBuild(env);
    HandleException::handleException(env);
    jfieldID fieldId = env->GetStaticFieldID(cls, "USER", "Ljava/lang/String;");
    HandleException::handleException(env);
    auto user = (jstring) env->GetStaticObjectField(cls, fieldId);
    env->DeleteLocalRef(cls);
    return user;

}

jobject HardwareInfo::batteryManager(JNIEnv *env, jobject obj) {
    jclass context = ClassUtils::context(env);
    HandleException::handleException(env);
    jfieldID fid_BatteryService = env->GetStaticFieldID(context, "BATTERY_SERVICE",
                                                        "Ljava/lang/String;");
    HandleException::handleException(env);
    auto batteryService = (jstring) env->GetStaticObjectField(context, fid_BatteryService);
    jclass cls = env->GetObjectClass(obj);
    HandleException::handleException(env);
    jmethodID mid_getSysService = env->GetMethodID(cls, "getSystemService",
                                                   "(Ljava/lang/String;)Ljava/lang/Object;");
    HandleException::handleException(env);
    jobject obj_batteryManager = env->CallObjectMethod(obj, mid_getSysService, batteryService);

    env->DeleteLocalRef(cls);
    env->DeleteLocalRef(context);

    return obj_batteryManager;

}

std::int64_t HardwareInfo::batteryCapacity(JNIEnv *env, jobject bm_obj) {
    jclass cls_bm = env->GetObjectClass(bm_obj);
    HandleException::handleException(env);
    jclass bm = env->FindClass("android/os/BatteryManager");
    HandleException::handleException(env);
    jfieldID fid_capacity = env->GetStaticFieldID(cls_bm, "BATTERY_PROPERTY_CAPACITY", "I");

    jint id = env->GetStaticIntField(bm, fid_capacity);

    HandleException::handleException(env);
    jmethodID mid = env->GetMethodID(cls_bm, "getIntProperty", "(I)I");
    jint batteryCapacity = env->CallIntMethod(bm_obj, mid, id);

    env->DeleteLocalRef(cls_bm);
    env->DeleteLocalRef(bm);

    return batteryCapacity;

}

jobjectArray HardwareInfo::sercurityProvider(JNIEnv *env, jobject obj) {
    jclass cls = env->FindClass("java/security/Security");
    HandleException::handleException(env);
    jmethodID mid_getProvider = env->GetStaticMethodID(cls, "getProviders",
                                                       "()[Ljava/security/Provider;");
    HandleException::handleException(env);
    jobjectArray providers = (jobjectArray) env->CallStaticObjectMethod(cls, mid_getProvider);

    env->DeleteLocalRef(cls);

    return providers;
}

jobject HardwareInfo::devicePolicyMgr(JNIEnv *env, jobject obj) {
    jclass context = ClassUtils::context(env);
    HandleException::handleException(env);
    jfieldID fid_device_policy_service = env->GetStaticFieldID(context, "DEVICE_POLICY_SERVICE",
                                                               "Ljava/lang/String;");
    HandleException::handleException(env);
    auto device_policy_service = (jstring) env->GetStaticObjectField(context,
                                                                     fid_device_policy_service);
    jmethodID mid_getSysService = env->GetMethodID(context, "getSystemService",
                                                   "(Ljava/lang/String;)Ljava/lang/Object;");
    HandleException::handleException(env);
    jobject device_policy_manager = env->CallObjectMethod(obj, mid_getSysService,
                                                          device_policy_service);

    env->DeleteLocalRef(context);

    return device_policy_manager;

}

bool HardwareInfo::isEncrypt(JNIEnv *env, jobject mgr) {
    if (SoftwareInfo::getSDK(env) > 14) {
        jclass manager = env->GetObjectClass(mgr);
        jclass cls = env->FindClass("android/app/admin/DevicePolicyManager");
        HandleException::handleException(env);
        jmethodID mid_gSES = env->GetMethodID(manager, "getStorageEncryptionStatus", "()I");
        HandleException::handleException(env);
        jfieldID fid_encryptStatus = env->GetStaticFieldID(cls, "ENCRYPTION_STATUS_ACTIVE", "I");
        HandleException::handleException(env);
        jint encrypt_status = env->GetStaticIntField(cls, fid_encryptStatus);
        jint current_status = env->CallIntMethod(mgr, mid_gSES);
        if (encrypt_status == current_status) {
            return true;
        }
    }

    return false;

}

jobject HardwareInfo::calendarInstance(JNIEnv *env, jobject obj) {
    jclass cls = env->FindClass("java/util/Calendar");
    HandleException::handleException(env);
    jmethodID mid_getInstance = env->GetStaticMethodID(cls, "getInstance",
                                                       "()Ljava/util/Calendar;");
    jobject getInstance = env->CallStaticObjectMethod(cls, mid_getInstance);

    env->DeleteLocalRef(cls);

    return getInstance;
}

jobject HardwareInfo::dateAndTime(JNIEnv *env, jobject instance) {
    jclass cls = env->GetObjectClass(instance);
    HandleException::handleException(env);
    jmethodID mid_getTime = env->GetMethodID(cls, "getTime", "()Ljava/util/Date;");
    jobject time = env->CallObjectMethod(instance, mid_getTime);

    env->DeleteLocalRef(cls);

    return time;
}

jobject HardwareInfo::getResource(JNIEnv *env, jobject obj) {
    jclass context = ClassUtils::context(env);
    HandleException::handleException(env);
    jmethodID mid = env->GetMethodID(context, "getResources", "()Landroid/content/res/Resources;");
    jobject resource = env->CallObjectMethod(obj, mid);

    env->DeleteLocalRef(context);

    return resource;
}

jobject HardwareInfo::getConfiguration(JNIEnv *env, jobject obj) {
    jclass cls = env->FindClass("android/content/res/Resources");
    HandleException::handleException(env);
    jmethodID mid = env->GetMethodID(cls, "getConfiguration",
                                     "()Landroid/content/res/Configuration;");
    jobject configuration = env->CallObjectMethod(obj, mid);

    env->DeleteLocalRef(cls);

    return configuration;
}

jobject HardwareInfo::packageManager(JNIEnv *env, jobject obj) {
    jclass pm_cls = env->FindClass("android/content/Context");
    HandleException::handleException(env);
    jmethodID mid_pm = env->GetMethodID(pm_cls, "getPackageManager",
                                        "()Landroid/content/pm/PackageManager;");
    jobject pm = env->CallObjectMethod(obj, mid_pm);

    env->DeleteLocalRef(pm_cls);

    return pm;

}

jint HardwareInfo::flagPackageManager(JNIEnv *env) {
    jclass pm_cls = env->FindClass("android/content/pm/PackageManager");
    HandleException::handleException(env);
    jfieldID fid_getProvider = env->GetStaticFieldID(pm_cls, "GET_PROVIDERS", "I");
    jint getProvider = env->GetStaticIntField(pm_cls, fid_getProvider);

    env->DeleteLocalRef(pm_cls);
    return getProvider;
}


jobjectArray HardwareInfo::listPackageInstalled(JNIEnv *env, jobject pm, jint flag) {
    jclass pm_cls = env->FindClass("android/content/pm/PackageManager");
    HandleException::handleException(env);
    jmethodID mid_getInstallPack = env->GetMethodID(pm_cls, "getInstalledPackages",
                                                    "(I)Ljava/util/List;");
    HandleException::handleException(env);
    auto list_package = (jobjectArray) env->CallObjectMethod(pm, mid_getInstallPack, flag);

    env->DeleteLocalRef(pm_cls);

    return list_package;
}

jstring HardwareInfo::getMac(JNIEnv *env) {
    std::fstream file;
    std::string mac;
    std::string path = "/sys/class/net/wlan0/address";

    if (SoftwareInfo::getSDK(env) >= 28) {
        path = "/sys/class/net/p2p0/address";
    }
    file.open(path, std::ios::in);
    if (!file) {
        return env->NewStringUTF("File not found");
    }
    file >> mac;
    file.close();
    return env->NewStringUTF(mac.c_str());

}

jint HardwareInfo::getIp(JNIEnv *env, jobject wifiInfoObj) {
    jclass cls = env->GetObjectClass(wifiInfoObj);
    HandleException::handleException(env);
    jmethodID mid = env->GetMethodID(cls, "getIpAddress", "()I");
    HandleException::handleException(env);
    jint ip = env->CallIntMethod(wifiInfoObj, mid);

    env->DeleteLocalRef(cls);

    return ip;

}

jobject HardwareInfo::locationManager(JNIEnv *env, jobject obj) {
    jclass context = env->FindClass("android/content/Context");
    HandleException::handleException(env);
    jfieldID fid = env->GetStaticFieldID(context, "LOCATION_SERVICE", "Ljava/lang/String;");
    auto location_service = (jstring) env->GetStaticObjectField(context, fid);
    jclass jclz = env->GetObjectClass(obj);
    jmethodID mid_getSystemService = env->GetMethodID(jclz, "getSystemService",
                                                      "(Ljava/lang/String;)Ljava/lang/Object;");
    jobject location_manager = env->CallObjectMethod(obj, mid_getSystemService, location_service);

    env->DeleteLocalRef(context);
    env->DeleteLocalRef(jclz);

    return location_manager;
}

jobject HardwareInfo::location(JNIEnv *env, jobject locationManager) {
    jclass lm = env->GetObjectClass(locationManager);
    HandleException::handleException(env);
    jclass cls_lm = env->FindClass("android/location/LocationManager");
    HandleException::handleException(env);
    jfieldID fid_GpsProvider = env->GetStaticFieldID(cls_lm, "GPS_PROVIDER", "Ljava/lang/String;");
    auto gps_provider = env->GetStaticObjectField(cls_lm, fid_GpsProvider);
    jmethodID mid_getLastLocation = env->GetMethodID(lm, "getLastKnownLocation",
                                                     "(Ljava/lang/String;)Landroid/location/Location;");
    HandleException::handleException(env);
    jobject location = env->CallObjectMethod(locationManager, mid_getLastLocation, gps_provider);
    if (location == nullptr) {
        jmethodID mid_request = env->GetMethodID(cls_lm, "requestLocationUpdates",
                                                 "(Ljava/lang/String;JFLandroid/app/PendingIntent;)V");
        int64_t minTimeMs = 0L;
        float minDistanceM = 1.0f;
        jclass test = env->FindClass("android/location/LocationListener");
        env->CallVoidMethod(locationManager, mid_request, gps_provider, minTimeMs, minDistanceM,
                            test);
    }

    env->DeleteLocalRef(lm);
    env->DeleteLocalRef(cls_lm);

    return location;

}

jdouble HardwareInfo::longitude(JNIEnv *env, jobject location) {
    jclass cls = env->GetObjectClass(location);
    HandleException::handleException(env);
    jmethodID mid_getLong = env->GetMethodID(cls, "getLongitude", "()D");
    auto longitude = env->CallDoubleMethod(location, mid_getLong);

    env->DeleteLocalRef(cls);

    return longitude;
}

jdouble HardwareInfo::latitude(JNIEnv *env, jobject location) {
    jclass cls = env->GetObjectClass(location);
    HandleException::handleException(env);
    jmethodID mid_getLat = env->GetMethodID(cls, "getLatitude", "()D");
    auto latitude = env->CallDoubleMethod(location, mid_getLat);

    env->DeleteLocalRef(cls);

    return latitude;
}


//jobject HardwareInfo::getLocale(JNIEnv *env, jobject obj) {
//    jclass cls = env->FindClass("java/util/Locale");
//    HandleException::handleException(env);
//    jmethodID mid = env->GetMethodID(cls,"getLocale", "");
//    jobject locale = env->CallObjectMethod(obj,mid);
//
//    env->DeleteLocalRef(cls);
//
//    return locale;
//
//}
