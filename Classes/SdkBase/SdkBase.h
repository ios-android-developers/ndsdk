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

#define GET_CLASS_PATH( relative_path )  "com/talkingsdk/"#relative_path

#define GET_RETURN_SIGN( params_sign, return_type )  params_sign return_type ";"

#define SDKBASE_CLASS_PATH GET_CLASS_PATH(SdkBase)
#define MAINAPPLICATION_CLASS_PATH GET_CLASS_PATH(MainApplication)
#define LOGINDATA_CLASS_PATH GET_CLASS_PATH(models/LoginData)

#include "LoginData.h"
#include "PayData.h"
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
	void callVoidWithOneParam(const char* method,const char* methodSign, jobject obj);

public:
	static SdkBase* getInstance();
	LoginData* getLoginData();
	jobject getJLoginData();
	void logout();
	void login();
	void pay(PayData& pd);
	void changeAccount();
private:
	LoginData* _loginData;

};


#endif /* SDKBASE_H_ */
