//
// Created by Thien on 8/7/21.
//

#ifndef DEVICEINFO_HARDWAREINFO_H
#define DEVICEINFO_HARDWAREINFO_H

class HardwareInfo {
public:

    static jclass getCls(JNIEnv *env);

    static jstring getBootloader(JNIEnv *env);

    static jstring getBrand(JNIEnv *env);

    static jstring getDevice(JNIEnv *env);

    static jstring getBuildNumber(JNIEnv *env);

    static jstring getFingerPrint(JNIEnv *env);

    static jstring getHardWare(JNIEnv *env);

    static jstring getHost(JNIEnv *env);

    static jstring getID(JNIEnv *env);

    static jstring getManufacture(JNIEnv *env);

    static jstring getModel(JNIEnv *env);

    static jstring getProduct(JNIEnv *env);
//    static jstring getSerial(JNIEnv *env);


};


#endif //DEVICEINFO_HARDWAREINFO_H
