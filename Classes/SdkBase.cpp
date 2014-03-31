/*
 * SdkBase.cpp

 *
 *  Created on: Mar 29, 2014
 *      Author: roscus
 */
#include "cocos2d.h"
using namespace cocos2d;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#endif
#include "SdkBase.h"
#include "MainApplication.h"
SdkBase* SdkBase::_instance = NULL;

const char* jclass_path = "com/talkingsdk/common_sdk/SdkBase";
SdkBase::SdkBase()
{
}
SdkBase* SdkBase::getInstance()
{
	if( NULL == SdkBase::_instance  ){
		SdkBase::_instance = new SdkBase();
	}
	return SdkBase::_instance;
}
jobject SdkBase::getJObject(const char* method, const char* jType )
{
	JniMethodInfo minfo;
	jobject obj = NULL;
	if (JniHelper::getMethodInfo(minfo, jclass_path,
			method, jType)) {
		jobject jSdkInstance =
				MainApplication::getInstance()->getJSdkInstance();
		obj = minfo.env->CallObjectMethod(jSdkInstance,
				minfo.methodID);
	}
	return obj;
}
void SdkBase::callVoid(const char* method)
{
	JniMethodInfo minfo;
	jobject obj = NULL;
	if (JniHelper::getMethodInfo(minfo, jclass_path, method, "()V")) {
		jobject jSdkInstance = MainApplication::getInstance()->getJSdkInstance();
		minfo.env->CallVoidMethod(jSdkInstance, minfo.methodID);
	}
}
void SdkBase::logout()
{
	callVoid("logout");
}
void SdkBase::login()
{
	callVoid("login");
}
void SdkBase::changeAccount()
{
	callVoid("changeAccount");
}
jobject SdkBase::getJLoginData()
{
	jobject obj = SdkBase::getJObject("getLoginData", "()Lcom/talkingsdk/common_sdk/models/LoginData;");
	return obj;
}
LoginData* SdkBase::getLoginData()
{
	return LoginData::getInstance();
}

