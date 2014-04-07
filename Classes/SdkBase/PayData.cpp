/*
 * PayData.cpp
 *
 *  Created on: Apr 3, 2014
 *      Author: roscus
 */
#include "cocos2d.h"
using namespace cocos2d;


#include <jni.h>
#include "platform/android/jni/JniHelper.h"

#include "SdkBase.h"
#include "PayData.h"


char* PayData::jclass_path = GET_CLASS_PATH(models/PayData);

PayData::PayData():_productRealPrice(0.0f), _productIdealPrice(0.0f), _productCount(0) {
	// TODO Auto-generated constructor stub

}
jobject PayData::toJObject()
{
	jobject ret = NULL;
	JniMethodInfo minfo;
	if(JniHelper::getMethodInfo(minfo, PayData::jclass_path, "<init>", "()V"))
	{
		jobject data = minfo.env->NewObject(minfo.classID, minfo.methodID);
		jstring jmyOrderId = minfo.env->NewStringUTF(_myOrderId.c_str());
		jstring jProductId = minfo.env->NewStringUTF(_productId.c_str());
		jstring jProductName = minfo.env->NewStringUTF(_productName.c_str());
		jdouble jProductRealPrice = (jdouble)_productRealPrice;
		jdouble jProductIdealPrice = (jdouble)_productIdealPrice;
		jint jProductCount = (jint)_productCount;
		jstring jProductDesription = minfo.env->NewStringUTF(_description.c_str());

		jfieldID fid;
		fid = minfo.env->GetFieldID(minfo.classID, "_myOrderId", "Ljava/lang/String;");
		minfo.env->SetObjectField(data, fid, jmyOrderId);

		fid = minfo.env->GetFieldID(minfo.classID, "_productId", "Ljava/lang/String;");
		minfo.env->SetObjectField(data, fid, jProductId);


		fid = minfo.env->GetFieldID(minfo.classID, "_productName", "Ljava/lang/String;");
		minfo.env->SetObjectField(data, fid, jProductName);

		fid = minfo.env->GetFieldID(minfo.classID, "_productRealPrice", "F");
		minfo.env->SetFloatField(data, fid, jProductRealPrice);

		fid = minfo.env->GetFieldID(minfo.classID, "_productIdealPrice", "F");
		minfo.env->SetFloatField(data, fid, jProductIdealPrice);

		fid = minfo.env->GetFieldID(minfo.classID, "_productCount", "I");
		minfo.env->SetIntField(data, fid, jProductCount);

		fid = minfo.env->GetFieldID(minfo.classID, "_description", "Ljava/lang/String;");
		minfo.env->SetObjectField(data, fid, jProductDesription);

		ret = data;
	}
	return ret;
}
const string PayData::getMyOrderId()
{
	return _myOrderId;
}
const string PayData::getProductId()
{
	return _productId;
}
const string PayData::getProductName()
{
	return _productName;
}
float PayData::getProductRealPrice()
{
	return _productRealPrice;
}
float PayData::getProductIdealPrice()
{
	return _productIdealPrice;
}
int PayData::getProductCount()
{
	return _productCount;
}
const string PayData::getDescription()
{
	return _description;
}
const string PayData::getPayDataEx(const char* key)
{
	return "";
}

void PayData::setMyOrderId(const char* myOrderId)
{
	_myOrderId = myOrderId;
}
void PayData::setProductId(const char* myProductId)
{
	_productId = myProductId;
}
void PayData::setProductName(const char* myProductName)
{
	_productName = myProductName;
}
void PayData::setProductRealPrice(float realPrice)
{
	_productRealPrice = realPrice;
}
void PayData::setProductIdealPrice(float idealPrice)
{
	_productIdealPrice = idealPrice;
}
void PayData::setProductCount(int productCount)
{
	_productCount = productCount;
}
void PayData::setDescription(const char* desc )
{
	_description = desc;
}
void PayData::setPayDataEx(const char* key, const char* value)
{
}
