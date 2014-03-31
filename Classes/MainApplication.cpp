/*
 * MainApplication.cpp

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
#include "MainApplication.h"

MainApplication* MainApplication::_instance = NULL;

MainApplication::MainApplication()
{
	getJInstance();
	getJSdkInstance();
}

jobject MainApplication::getJSingletonInstance(const char* clazzName) {
	jobject instance;
	JniMethodInfo minfo;
	bool isHave = JniHelper::getStaticMethodInfo(minfo, clazzName,
			"getInstance", "()Lcom/talkingsdk/common_sdk/MainApplication;");
	if (isHave) {
		instance = minfo.env->CallStaticObjectMethod(minfo.classID,
				minfo.methodID);
	}
	assert(instance);
	return instance;
}

jobject MainApplication::getJInstance() {
	jobject instance = MainApplication::getJSingletonInstance("com/talkingsdk/common_sdk/MainApplication");
	return instance;
}

jobject MainApplication::getJSdkInstance()
{
	JniMethodInfo minfo;
	jobject instance;
	if (JniHelper::getMethodInfo(minfo,
			"com/talkingsdk/common_sdk/MainApplication", "getSdkInstance",
			"()Lcom/talkingsdk/common_sdk/SdkBase;")) {
		instance = (jobject) minfo.env->CallObjectMethod(getJInstance(),
				minfo.methodID);
		assert(instance);
	}
	return instance;
}

MainApplication* MainApplication::getInstance() {
	if (NULL == MainApplication::_instance) {
		MainApplication::_instance = new MainApplication();
	}
	return MainApplication::_instance;
}
