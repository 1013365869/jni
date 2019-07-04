package com.study.jll;

public class NDKTools {
    static {
        System.loadLibrary("ndkdemotest-jni");
    }
    public static native String getStringFromNDK();
}
