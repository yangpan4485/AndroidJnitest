package com.example.verify;

public class VerifyClass {
    static {
        System.loadLibrary("verify_android");
    }

    public native long createObject();

    public native void setValue(long verify , int id,String value);

    public native String getValue(long verify , int id);
}
