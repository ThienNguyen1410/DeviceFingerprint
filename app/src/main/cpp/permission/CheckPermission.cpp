//
// Created by Thien on 8/13/21.
//

#include "CheckPermission.h"

jstring CheckPermission::permissionName(JNIEnv *env, const char *name) {
    jclass cls_manifest = env->FindClass(
            "android/Manifest$permission"
    );
    jfieldID fid = env->GetStaticFieldID(
            cls_manifest, name, "Ljava/lang/String;"
    );
    auto perm_name = (jstring) (env->GetStaticObjectField(
            cls_manifest, fid
    ));
    return perm_name;
}

bool CheckPermission::hasPermission(JNIEnv *env, const char *name, jobject obj) {
    bool result = false;

    jstring perm_name = permissionName(env, name);

    jint PERMISSION_GRANTED = jint(-1);
    {
        jclass cls_packageManager = env->FindClass(
                "android/content/pm/PackageManager"
        );
        jfieldID fid_PERMISSION_GRANTED = env->GetStaticFieldID(
                cls_packageManager, "PERMISSION_GRANTED", "I"
        );
        PERMISSION_GRANTED = env->GetStaticIntField(
                cls_packageManager, fid_PERMISSION_GRANTED
        );
    }
    {
        jobject activity = obj;
        jclass cls_context = env->FindClass(
                "android/content/Context"
        );
        jmethodID methodId_checkSelfPermission = env->GetMethodID(
                cls_context, "checkSelfPermission", "(Ljava/lang/String;)I"
        );
        jint int_result = env->CallIntMethod(
                activity, methodId_checkSelfPermission, perm_name
        );
        result = (int_result == PERMISSION_GRANTED);
    }

    return result;
}
