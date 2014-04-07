/*
 * LoginData.cpp
 *
 *  Created on: Apr 1, 2014
 *      Author: roscus
 */
#include "cocos2d.h"
using namespace cocos2d;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#endif

#include "SdkBase.h"
#include "LoginData.h"

char* LoginData::jclass_path = GET_CLASS_PATH(models/LoginData);

LoginData::LoginData() {
	// TODO Auto-generated constructor stub

}
jobject LoginData::getJObject(const char* method, const char* jType )
 {
       JniMethodInfo minfo;
       jobject obj = NULL;
       if (JniHelper::getMethodInfo(minfo, LoginData::jclass_path, method, jType)) {
               jobject jLoginData = SdkBase::getInstance()->getJLoginData();
               obj = minfo.env->CallObjectMethod(jLoginData,minfo.methodID);
       }
       return obj;
 }
void LoginData::fromJObject(jobject obj)
{
	jobject jUsername = LoginData::getJObject("getUsername", "()Ljava/lang/String;");
	_username = JniHelper::jstring2string((jstring)jUsername);

	jobject jPassword = LoginData::getJObject("getPassword", "()Ljava/lang/String;");
	_password = JniHelper::jstring2string((jstring)jPassword);

	jobject jSessionId = LoginData::getJObject("getSessionId", "()Ljava/lang/String;");
	_session_id = JniHelper::jstring2string((jstring)jSessionId);

}

const string LoginData::getUsername()
{
	return _username;
}

const string LoginData::getSessionId()
{
	return _session_id;
}
const string LoginData::getLoginDataEx(const char* key)
{
	return "";
}

