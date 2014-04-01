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
private:
	LoginData();
	LoginData(LoginData const&);
	LoginData& operator=( LoginData const &);
	~LoginData() {};
	static LoginData* _instance;

protected:
	jobject getJObject(const char* method, const char* jType );

public:
	static char* jclass_path;
	static LoginData* getInstance();
	const string getUsername();
	const string getPassword();
	const string getSessionId();
	const string getLoginDataEx(const char* key);

private:

};


#endif /* LoginData_H_ */
