package com.talkingsdk.common_sdk;


import android.app.Application;

public class MainApplication extends Application {
	private SdkBase _sdkInstance = null;
	public SdkBase getSdkInstance()
	{
		return _sdkInstance;
	}
	
	private static MainApplication _instance = null;
	public static MainApplication getInstance()
	{
		return _instance;
	}
	@Override
	public void onCreate() {
		super.onCreate(); 
		_instance = this;
		String name = "com.talkingsdk.NdSdk";
		System.out.print(name);
		Class<?> cls;
		try {
			cls = Class.forName(name);
			_sdkInstance = (SdkBase) cls.newInstance();
			_sdkInstance.initSdk(null);
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
		if( _sdkInstance != null ){
			_sdkInstance.exit();
		}
		super.onTerminate();
	}
}
