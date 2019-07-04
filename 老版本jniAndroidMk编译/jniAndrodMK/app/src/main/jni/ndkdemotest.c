//
// Created by jll on 2019/7/1.
//

#include "com_study_jll_NDKTools.h"

JNIEXPORT jstring JNICALL Java_com_study_jll_NDKTools_getStringFromNDK
  (JNIEnv *env, jobject obj){
       return (*env)->NewStringUTF(env,"fisrt jni");
  }
