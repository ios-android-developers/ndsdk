package com.talkingsdk;

import java.util.List;

import android.app.Activity;
import android.app.ActivityManager;
import android.app.ActivityManager.RunningAppProcessInfo;
import android.app.ProgressDialog;
import android.content.Context;
import android.widget.Toast;

import com.nd.commplatform.NdCommplatform;
import com.nd.commplatform.NdPageCallbackListener.OnPauseCompleteListener;

public class BaseActivity extends Activity{

	private ProgressDialog progressDialog;


	private boolean isAppForeground = true;

	@Override
	protected void onStop() {
		// TODO Auto-generated method stub
		super.onStop();
		if(!isAppOnForeground()){//app进入后台
			isAppForeground = false;
		}
	}


	@Override
	protected void onResume() {
		// TODO Auto-generated method stub
		super.onResume();
		if(!isAppForeground){//从后台切到前台，打开91SDK暂停页
			NdCommplatform.getInstance().ndPause(new OnPauseCompleteListener(this){

				@Override
				public void onComplete() {
					// TODO Auto-generated method stub
					Toast.makeText(BaseActivity.this, "退出暂停页", Toast.LENGTH_LONG).show();
				}

			});
			isAppForeground = true;
		}
	}

	/**
	 * 判断App是否在前台运行
	 * @return
	 */
	public boolean isAppOnForeground() {
		ActivityManager activityManager = (ActivityManager) getApplicationContext()
				.getSystemService(Context.ACTIVITY_SERVICE);
		String packageName = getApplicationContext().getPackageName();
		List<RunningAppProcessInfo> appProcesses = activityManager.getRunningAppProcesses();
		if (appProcesses == null)
			return false;
		for (RunningAppProcessInfo appProcess : appProcesses) {
			if (appProcess.processName.equals(packageName)
					&& appProcess.importance == RunningAppProcessInfo.IMPORTANCE_FOREGROUND) {
				return true;
			}
		}
		return false;
	}

	protected void initUI(){
	}

	protected void showLoading(){
		progressDialog = new ProgressDialog(this);
		progressDialog.setMessage("正在加载...");
		progressDialog.setIndeterminate(true);
		progressDialog.setCancelable(false);
		progressDialog.show();
	}


	protected void showLoading(String tips){
		progressDialog = new ProgressDialog(this);
		progressDialog.setMessage(tips);
		progressDialog.setIndeterminate(true);
		progressDialog.setCancelable(false);
		progressDialog.show();
	}

	protected void hideLoading(){
		if(progressDialog != null){
			progressDialog.cancel();
			progressDialog = null;
		}
	}



}
