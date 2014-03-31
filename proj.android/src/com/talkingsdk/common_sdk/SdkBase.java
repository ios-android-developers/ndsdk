package com.talkingsdk.common_sdk;

import com.talkingsdk.common_sdk.models.LoginData;

import android.app.Activity;

public interface SdkBase{
	public void initSdk(Object obj);
	public void initUI(Activity parentActivity);
	public void login();
	public void logout();
	public void changeAccount();
	public void exit();
	public LoginData getLoginData();
}
