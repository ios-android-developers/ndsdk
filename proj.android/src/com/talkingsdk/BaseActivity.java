package com.talkingsdk;

import java.util.List;

import android.app.Activity;
import android.app.ActivityManager;
import android.app.ActivityManager.RunningAppProcessInfo;
import android.app.ProgressDialog;
import android.content.Context;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import com.nd.commplatform.NdCommplatform;
import com.nd.commplatform.NdPageCallbackListener.OnPauseCompleteListener;

public class BaseActivity extends Activity{

	private String title;
	private Button buttonLeft;
	private ProgressDialog progressDialog;

	
	private boolean isAppForeground = true;
	
	@Override
	protected void onStop() {
		// TODO Auto-generated method stub
		super.onStop();
		if(!isAppOnForeground()){//app�����̨
			isAppForeground = false;
		}
	}
	
	
	@Override
	protected void onResume() {
		// TODO Auto-generated method stub
		super.onResume();
		if(!isAppForeground){//�Ӻ�̨�е�ǰ̨����91SDK��ͣҳ
			NdCommplatform.getInstance().ndPause(new OnPauseCompleteListener(this){

				@Override
				public void onComplete() {
					// TODO Auto-generated method stub
					Toast.makeText(BaseActivity.this, "�˳���ͣҳ", Toast.LENGTH_LONG).show();
				}
				
			});
			isAppForeground = true;
		}
	}
	
	/**
	 * �ж�App�Ƿ���ǰ̨����
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
	
	 
	
	protected void setTitle(String title){
		this.title = title;
	}
	
	protected void initUI(){
		
	}
	
	protected void showLoading(){
		progressDialog = new ProgressDialog(this);
		progressDialog.setMessage("���ڼ���...");
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
