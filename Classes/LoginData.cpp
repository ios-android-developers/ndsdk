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

char* LoginData::jclass_path = "com/talkingsdk/common_sdk/models/LoginData";
LoginData* LoginData::_instance = NULL;
LoginData::LoginData() {
	// TODO Auto-generated constructor stub

}
LoginData* LoginData::getInstance()
{
	if( NULL == LoginData::_instance  ){
		LoginData::_instance = new LoginData();
	}
	return LoginData::_instance;
}
jobject LoginData::getJObject(const char* method, const char* jType )
{
	JniMethodInfo minfo;
	jobject obj = NULL;
	if (JniHelper::getMethodInfo(minfo, LoginData::jclass_path,
			method, jType)) {
		jobject jLoginData = SdkBase::getInstance()->getJLoginData();
		obj = minfo.env->CallObjectMethod(jLoginData,
				minfo.methodID);
	}
	return obj;
}

const string LoginData::getUsername()
{
	jobject obj = LoginData::getJObject("getUsername", "()Ljava/lang/String;");
	string un = JniHelper::jstring2string((jstring)obj);
	return un;
}

const string LoginData::getLoginDataEx(const char* key)
{
	return "";
	/*
	jobject obj = LoginData::getJObject("getEx", "()L<K:Ljava/lang/String;V:Ljava/lang/String;>Ljava/util/HashMap<TK;TV;>;");
	return obj;
	JniMethodInfo minfo;
	jobject obj = SdkBase::getJObject("getLoginData", "()Lcom/talkingsdk/common_sdk/models/LoginData;");

	if (JniHelper::getMethodInfo(minfo,
			jclass_path, "getUsername",	"()Ljava/lang/String;")) {
		jobject jSdkInstance  = MainApplication::getInstance()->getJSdkInstance();
		jstring username = (jstring) minfo.env->CallObjectMethod(jSdkInstance,
				minfo.methodID);
		string un = JniHelper::jstring2string(username);
		const char * tmp = un.c_str();
		printf("%s",tmp);
	}
	return NULL;
	*/
}
