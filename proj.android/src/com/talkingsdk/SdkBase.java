package com.talkingsdk;

import com.talkingsdk.models.LoginData;
import com.talkingsdk.models.PayData;

import android.app.Activity;

public interface SdkBase{
	public void initSdk(Object obj);
	public void initUI(Activity parentActivity);
	public void login();
	public void pay(PayData payData);
	public void logout();
	public void changeAccount();
	public void exit();
	public LoginData getLoginData();
}
