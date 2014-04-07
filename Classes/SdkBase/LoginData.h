/*
 * LoginData.h
 *
 *  Created on: Apr 1, 2014
 *      Author: roscus
 */

#ifndef LOGINDATA_H_
#define LOGINDATA_H_

#include <jni.h>
#include <string>
using namespace std;
class LoginData{
public:
	LoginData();
	void fromJObject(jobject obj);
	jobject getJObject(const char* method, const char* jType );

public:
	static char* jclass_path;
	const string getUsername();
	const string getSessionId();
	const string getLoginDataEx(const char* key);

private:
	string _username;
	string _password;
	string _session_id;
};

#endif /* LoginData_H_ */
