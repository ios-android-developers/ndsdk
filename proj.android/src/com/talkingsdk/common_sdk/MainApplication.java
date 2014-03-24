package com.talkingsdk.common_sdk;


import android.app.Application;

public class MainApplication extends Application {
	private SdkBase sdkInstance = null;
	@Override
	public void onCreate() {
		super.onCreate(); 
		String name = "com.talkingsdk.NdSdk";
		System.out.print(name);
		Class<?> cls;
		try {
			cls = Class.forName(name);
			sdkInstance = (SdkBase) cls.newInstance();
			sdkInstance.init(null);
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (InstantiationException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	@Override
	public void onTerminate() {
		if( sdkInstance != null ){
			sdkInstance.exit();
		}
		super.onTerminate();
	}
}
