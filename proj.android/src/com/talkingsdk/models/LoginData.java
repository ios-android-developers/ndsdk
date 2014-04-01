package com.talkingsdk.models;

import java.util.HashMap;

public class LoginData {
	private String _username;
	private String _password;
	private String _sessionId;
	private HashMap<String,String> _ex;
	public LoginData()
	{
		_ex = null; 
	}

	public String getUsername() {
		return _username;
	}

	public void setUsername(String username) {
		this._username = username;
	}

	public String getSessionId() {
		return _sessionId;
	}

	public void setSessionId(String sessionId) {
		this._sessionId = sessionId;
	}

	public String getPassword() {
		return _password;
	}

	public void setPassword(String password) {
		this._password = password;
	}

	public HashMap<String,String> getEx() {
		if( null == _ex ){
			_ex = new HashMap<String,String>();
		}
		return _ex;
	}
}
