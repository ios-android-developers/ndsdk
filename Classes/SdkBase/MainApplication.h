/*
 * MainApplication.h
 *
 *  Created on: Mar 29, 2014
 *      Author: roscus
 */

#ifndef MAINAPPLICATION_H_
#define MAINAPPLICATION_H_
#include <jni.h>
#include <string>
using namespace std;

class MainApplication{
private:
	MainApplication();
	MainApplication(MainApplication const&);
	MainApplication& operator=( MainApplication const &);
	~MainApplication() {};
	static MainApplication* _instance;

public:
	static jobject getJSingletonInstance(const char* clazzName);
	static MainApplication* getInstance();
	jobject getJInstance();
	jobject getJSdkInstance();
};

#endif /* MAINAPPLICATION_H_ */
