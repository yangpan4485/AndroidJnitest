package com.example.verify;

public class VerifyTest {
    static{
        System.loadLibrary("verify_android");
    }

    public native int getRandValue();

    public native String getStringValue();
}
