LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := SdkBase
LOCAL_MODULE_FILENAME := libSdkBase
LOCAL_SRC_FILES := SdkBase/SdkBase.cpp \
                   SdkBase/LoginData.cpp \
                   SdkBase/MainApplication.cpp
                   

include $(BUILD_STATIC_LIBRARY)
