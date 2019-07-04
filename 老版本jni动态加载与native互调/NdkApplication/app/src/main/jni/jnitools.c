#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include <android/log.h>

jint addNumber(JNIEnv *env, jclass clazz, jint a, jint b);

jint subNumber(JNIEnv *env, jclass clazz, jint a, jint b);

jint mulNumber(JNIEnv *env, jclass clazz, jint a, jint b);

jint divNumber(JNIEnv *env, jclass clazz, jint a, jint b);

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {

    __android_log_print(ANDROID_LOG_DEBUG, "JNITag", "enter jni_onload");
    JNIEnv *env = NULL;
    jint result = -1;

    if ((*vm)->GetEnv(vm, (void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return result;
    }

    const JNINativeMethod method[] ={
                                    {"add","(II)I",(void*)addNumber},
                                    {"sub","(II)I",(void*)subNumber},
                                    {"mul","(II)I",(void*)mulNumber},
                                    {"div","(II)I",(void*)divNumber}
                                     };
    jclass jClassName= (*env)->FindClass(env,"com/study/capplication/NDKTool");

    jint ret = (*env)->RegisterNatives(env,jClassName,method,4);

    if (ret!=JNI_OK){
        __android_log_print(ANDROID_LOG_DEBUG,"JNITag","jni_register Error");
        return -1;
    }
    return JNI_VERSION_1_6;
}

jint addNumber(JNIEnv *env, jclass clazz, jint a, jint b) {
    return a + b;
}

jint subNumber(JNIEnv *env, jclass clazz, jint a, jint b) {
    return a - b;
}

jint mulNumber(JNIEnv *env, jclass clazz, jint a, jint b) {
    return a * b;
}

jint divNumber(JNIEnv *env, jclass clazz, jint a, jint b) {
    return a / b;
}

JNIEXPORT void JNICALL Java_com_study_capplication_NDKTool_callJavaStatticMethod(JNIEnv *env, jobject instance) {
    //1.获取类类型的Class对象
    jclass personClass = (*env)->FindClass(env, "com/study/capplication/NDKTool");

    if (NULL == personClass) {
        __android_log_print(ANDROID_LOG_ERROR, "PERSON", "NOT FIND CLASS");
        return;
    }
    //2.获取方法ID  方法签名：(String:Ljava/lang/String ；int:I)  方法签名可以通过javap -s命令生成

    jmethodID pJmethodID = (*env)->GetStaticMethodID(env, personClass, "setPersonInfo",
                                                     "(Ljava/lang/String;I)V");
    if (NULL == pJmethodID) {
        __android_log_print(ANDROID_LOG_ERROR, "PERSON", "NOT FIND STATIC METHOD");
        return;
    }
    jstring str = (*env)->NewStringUTF(env, "Yimi");

    //3.调用方法
    (*env)->CallStaticVoidMethod(env, personClass, pJmethodID, str, 18);

    // 删除局部变量引用表,JVM内部由于引用表，
    // 记录全局和局部的变量，当超过引用表数量，导致内存溢出
    // 造成崩溃
    (*env)->DeleteLocalRef(env, personClass);
    (*env)->DeleteLocalRef(env, str);
}
