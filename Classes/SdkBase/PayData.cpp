/*
 * PayData.cpp
 *
 *  Created on: Apr 3, 2014
 *      Author: roscus
 */

#include "PayData.h"

char* PayData::jclass_path = GET_CLASS_PATH(models/PayData);

PayData* PayData::_instance = NULL;
PayData::PayData() {
	// TODO Auto-generated constructor stub

}
PayData* PayData::getInstance()
{
	if( NULL == PayData::_instance  ){
		PayData::_instance = new PayData();
	}
	return PayData::_instance;
}
jobject PayData::toJObject(const char* method, const char* jType )
{
	JniMethodInfo minfo;
	if(JniHelper::getMethodInfo(minfo, PayData::jclass_path, "<init>", "()V"))
	{
		jobject data = minfo.env->NewObject(minfo.classID, minfo.methodID);
		jstring jmyOrderId = minfo.env->NewStringUTF(_myOrderId.c_str());
		jstring jProductId = minfo.env->NewStringUTF(_productId.c_str());
		jstring jProductName = minfo.env->NewStringUTF(_productName.c_str());
		jdouble jProductRealPrice = (jdouble)_productRealPrice;
		jdouble jProductIdealPrice = (jdouble)_productIdealPrice;
		jint jProductCount = (jint)_paydata.productCount;
		jstring jProductDesription = minfo.env->NewStringUTF(_paydata.productDesription.c_str());
		LOG_("data param create success");
		jfieldID fid;


		fid = minfo.env->GetFieldID(minfo.classID, "serial", "Ljava/lang/String;");
		LOG_("get serial fid");
		minfo.env->SetObjectField(data, fid, jSerial);
		LOG_("set serial");

		fid = minfo.env->GetFieldID(minfo.classID, "productId", "Ljava/lang/String;");
		LOG_("get productId fid");
		minfo.env->SetObjectField(data, fid, jProductId);
		LOG_("set productId");

		fid = minfo.env->GetFieldID(minfo.classID, "productName", "Ljava/lang/String;");
		LOG_("get productName fid");
		minfo.env->SetObjectField(data, fid, jProductName);
		LOG_("set productName");

		fid = minfo.env->GetFieldID(minfo.classID, "productPrice", "D");
		LOG_("get productPrice fid");
		minfo.env->SetDoubleField(data, fid, jProductPrice);
		LOG_("set productPrice");

		fid = minfo.env->GetFieldID(minfo.classID, "orginalPrice", "D");
		LOG_("get orginalPrice fid");
		minfo.env->SetDoubleField(data, fid, jOrginalPrice);
		LOG_("set orginalPrice");

		fid = minfo.env->GetFieldID(minfo.classID, "productCount", "I");
		LOG_("get productCount fid");
		minfo.env->SetIntField(data, fid, jProductCount);
		LOG_("set productCount");
	}
	return NULL;
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

void setMyOrderId(const char* myOrderId)
{
	_myOrderId ＝ myOrderId;
}
void setProductId(const char* myProductId)
{
	_productId = myProductId;
}
void setProductName(const char* myProductName)
{
	_productName = myProductName;
}
void setProductRealPrice(float realPrice)
{
	_productRealPrice = realPrice;
}
void setProductIdealPrice(float idealPrice)
{
	_productIdealPrice = idealPrice;
}
void setProductCount(int productCount)
{
	_productCount = productCount;
}
void setDescription(const char* desc )
{
	_description = desc;
}
void setPayDataEx(const char* key, const char* value)
{
}
