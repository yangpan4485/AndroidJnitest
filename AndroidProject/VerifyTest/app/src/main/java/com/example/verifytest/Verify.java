package com.example.verifytest;

import android.util.Log;

import com.example.verify.VerifyTest;
import com.example.verify.TransmitterVerifyListener;
import com.example.verify.VerifyCallback;
import com.example.verify.VerifyClass;

public class Verify {

    private TransmitterVerifyListener mTransmitterVerifyListener;
    private VerifyTest mVerifyTest;
    private VerifyCallback mVerifyCallback;
    private VerifyClass mVerifyClass;
    public Verify(){

    }

    public void startVerify(){
        mTransmitterVerifyListener = new TransmitterVerifyListener() {
            @Override
            public void onTransmitterVerifyValue(int value) {
                Log.d("####", "value:"+value);
            }
        };

        mVerifyTest = new VerifyTest();
        mVerifyCallback = new VerifyCallback();
        mVerifyClass = new VerifyClass();

        Log.d("###","rand value:" + mVerifyTest.getRandValue());
        Log.d("###","string value:" + mVerifyTest.getStringValue());

        mVerifyCallback.registeVerifyListener(mTransmitterVerifyListener);
        mVerifyCallback.startListenTransmitter();
        mVerifyCallback.start();

        long clz_obj = mVerifyClass.createObject();
        mVerifyClass.setValue(clz_obj,1,"hello");
        Log.d("###","get value:"+mVerifyClass.getValue(clz_obj,1));

        int value = 0;
        while(true){
            value++;
            if(value > 100){
                break;
            }
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        mVerifyCallback.stop();

    }


}
