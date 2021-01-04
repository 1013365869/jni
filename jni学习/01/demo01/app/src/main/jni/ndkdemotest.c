//
// Created by jll on 2021/1/4.
//
#include "gebilaolitou_ndkdemo_NDKTools.h"

JNIEXPORT jstring JNICALL Java_gebilaolitou_ndkdemo_NDKTools_getStringFromNDK
  (JNIEnv *env, jobject obj){
     return (*env)->NewStringUTF(env,"Hellow World，这是隔壁老李头的NDK的第一行代码");
  }
