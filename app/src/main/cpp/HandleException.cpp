//
// Created by Thien on 8/7/21.
//

#include <jni.h>
#include "HandleException.h"

void HandleException::handleException(JNIEnv *env) {
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
        return;
    }
}

