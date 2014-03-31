package com.talkingsdk;

import android.app.Activity;
import android.content.Intent;

import com.nd.commplatform.NdCommplatform;
import com.nd.commplatform.NdErrorCode;
import com.nd.commplatform.NdMiscCallbackListener;
import com.nd.commplatform.OnInitCompleteListener;
import com.nd.commplatform.NdMiscCallbackListener.OnLoginProcessListener;
import com.nd.commplatform.entry.NdAppInfo;
import com.nd.commplatform.entry.NdLoginStatus;
import com.talkingsdk.common_sdk.SdkBase;
import com.talkingsdk.common_sdk.models.LoginData;


public class NdSdk implements SdkBase{
	public static final int appID_91Bean = 100010;//91appID
	public static final String appKEY_91Bean = "C28454605B9312157C2F76F27A9BCA2349434E546A6E9C75";//91appKEY
	private Activity _startActivity;
	private LoginData _loginData;

	public void startActivity( Intent intent )
	{
		this._startActivity.startActivity(intent);
	}
	Activity getParentActivity()
	{
		return this._startActivity;
	}
	public void initSdk(Object obj){
	}
	public void initGame(Object obj){
		System.out.println("NdSdk init");
	}
	public void exit() {
		System.out.println("NdSdk exit");
	}
	private void doGameLogin(int code) {

		String tip = "";
		if (code == NdErrorCode.ND_COM_PLATFORM_SUCCESS) {
			if (NdCommplatform.getInstance().ndGetLoginStatus() == NdLoginStatus.AccountLogin) {// 账号登录
				_loginData = new LoginData();
				_loginData.setUsername(NdCommplatform.getInstance().getLoginUin());
				_loginData.setSessionId(NdCommplatform.getInstance().getSessionId());
				// 账号登录成功，此时可用初始化玩家游戏数据
				tip = "账号登录成功";
				getParentActivity().finish();
				if( StartGameActivity.getInstance() == null ){
					startActivity(new Intent(getParentActivity(), StartGameActivity.class));
				}
			} else if (NdCommplatform.getInstance().ndGetLoginStatus() == NdLoginStatus.GuestLogin) {// 游客登录
				// 游客登录成功，此时可获取玩家的游客UIN做为保存游戏数据的标识，玩家游客账号转正后该UIN不变。
				tip = "游客登录成功";
			}
		} else if (code == NdErrorCode.ND_COM_PLATFORM_ERROR_CANCEL) {
			tip = "取消账号登录";
		} else if (code == NdErrorCode.ND_COM_GUEST_OFFICIAL_SUCCESS) {
			tip = "游客转正成功";
		} else {
			tip = "登录失败，错误代码：" + code;
		}
	}
	@Override
	public void initUI(Activity parentActivity) {
		// TODO Auto-generated method stub
		this._startActivity = parentActivity;
		OnInitCompleteListener mOnInitCompleteListener = new OnInitCompleteListener() {

			@Override
			protected void onComplete(int ndFlag) {
				switch (ndFlag) {
				case OnInitCompleteListener.FLAG_NORMAL:
					NdCommplatform.getInstance().ndSetScreenOrientation(NdCommplatform.SCREEN_ORIENTATION_AUTO);
					// 初始化自己的游戏
					// 根据91自测文档我们需要首先打开登录界面
					login();
					break;
				case OnInitCompleteListener.FLAG_FORCE_CLOSE:
				default:
					 // 如果还有别的Activity或资源要关闭的在这里处理
					break;
				}
			}
		};

	    NdAppInfo appInfo = new NdAppInfo();
	    appInfo.setCtx(this._startActivity);
	    appInfo.setAppId(appID_91Bean);// 应用ID
	    appInfo.setAppKey(appKEY_91Bean);// 应用Key
	    /*  
	     * NdVersionCheckLevelNormal 版本检查失败可以继续进行游戏 NdVersionCheckLevelStrict
	     * 版本检查失败则不能进入游戏 默认取值为NdVersionCheckLevelStrict
	     */
	    appInfo.setNdVersionCheckStatus(NdAppInfo.ND_VERSION_CHECK_LEVEL_STRICT);

	    // 初始化91SDK
	    NdCommplatform.getInstance().ndInit(this._startActivity, appInfo, mOnInitCompleteListener);
	}

	@Override
	public void login() {
		NdCommplatform.getInstance().ndLogin(getParentActivity(),
			new NdMiscCallbackListener.OnLoginProcessListener() {
				@Override
				public void finishLoginProcess(int code) {
					doGameLogin(code);
				}
			}
		);

	}
    public void changeAccount()
    {
		NdCommplatform.getInstance().ndEnterAccountManage(StartGameActivity.getInstance(), new OnLoginProcessListener(){

			@Override
			public void finishLoginProcess(int code) {
				// TODO Auto-generated method stub
				// 登录的返回码检查
				String tip = null;
				if (code == NdErrorCode.ND_COM_PLATFORM_SUCCESS) { 
					doGameLogin(code);
				} else if (code == NdErrorCode.ND_COM_PLATFORM_ERROR_CANCEL) {
//					tip = "取消账号切换"; 
				} else  {
					getParentActivity().finish(); 
					Intent intent = new Intent(StartGameActivity.getInstance(),getParentActivity().getClass());	
					StartGameActivity.getInstance().startActivity(intent);
//					tip = "账号切换失败"; 
				}
			}
			
		});
	}
	@Override
	public void logout() {
		NdCommplatform.getInstance().ndLogout(NdCommplatform.LOGOUT_TO_NON_RESET_AUTO_LOGIN_CONFIG, this._startActivity);
	}

	@Override
	public LoginData getLoginData() {
		return _loginData;
	}
}
