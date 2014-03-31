/*
 * SdkBase.h
 *
 *  Created on: Mar 30, 2014
 *      Author: roscus
 */

#ifndef SDKBASE_H_
#define SDKBASE_H_
#include <jni.h>
#include <string>
#include "LoginData.h"
using namespace std;
class SdkBase{
private:
	SdkBase();
	SdkBase(SdkBase const&);
	SdkBase& operator=( SdkBase const &);
	~SdkBase() {};
	static SdkBase* _instance;

protected:
	jobject getJObject(const char* method, const char* jType );
	void callVoid(const char* method);


public:
	static SdkBase* getInstance();
	LoginData* getLoginData();
	jobject getJLoginData();
	void logout();
	void login();
	void changeAccount();
private:

};


#endif /* SDKBASE_H_ */
