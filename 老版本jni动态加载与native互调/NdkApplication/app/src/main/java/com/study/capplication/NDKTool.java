package com.study.capplication;

import android.util.Log;

public class NDKTool {
    static {
        System.loadLibrary("jnidemo3");
    }


    public static native int add(int a, int b);

    public static native int sub(int a, int b);

    public static native int mul(int a, int b);

    public static native int div(int a, int b);

    public native void callJavaStatticMethod();

    public native void callJavaInstanceMethod();

    public static void setPersonInfo(String name, int age) {
        Log.i("PERSON", "name= " + name + "\\t age=" + age);
    }

    public void setPersonMoney(float money) {
        Log.i("PERSON", "money= " + money);
    }
}
