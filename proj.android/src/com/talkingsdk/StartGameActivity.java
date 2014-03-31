package com.talkingsdk;

import org.cocos2dx.lib.Cocos2dxActivity;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Toast;

import com.nd.commplatform.NdCommplatform;
import com.nd.commplatform.NdErrorCode;
import com.nd.commplatform.NdMiscCallbackListener;
import com.nd.commplatform.NdPageCallbackListener.OnExitCompleteListener;
import com.nd.commplatform.OnInitCompleteListener;
import com.nd.commplatform.entry.NdLoginStatus;
import com.talkingsdk.common_sdk.MainApplication;

/**
 * 欢迎界面
 *
 */
public class StartGameActivity extends  Cocos2dxActivity{
	static StartGameActivity _instance = null;
	public static StartGameActivity getInstance()
	{
		return _instance;
	}
	protected void onCreate(Bundle savedInstanceState){
		System.out.print("StartGameActivity");
		_instance =  this;
		super.onCreate(savedInstanceState);
	}

    static {
    	System.out.print("loadLibrary");
        System.loadLibrary("game");
    }
}
