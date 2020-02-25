package com.example.verify;

public class VerifyCallback {
    static{
        System.loadLibrary("verify_android");
    }

    private TransmitterVerifyListener mTransmitterVerifyListener;

    public void registeVerifyListener(TransmitterVerifyListener transmitterVerifyListener){
        mTransmitterVerifyListener = transmitterVerifyListener;
    }

    public native void start();

    public native void stop();

    public native void startListenTransmitter();
}
