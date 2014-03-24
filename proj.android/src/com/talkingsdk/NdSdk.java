package com.talkingsdk;

import com.talkingsdk.common_sdk.SdkBase;

public class NdSdk implements SdkBase{
	public void init(Object obj){
		System.out.println("NdSdk init");
	}
	public void exit() {
		System.out.println("NdSdk exit");
	}
}
