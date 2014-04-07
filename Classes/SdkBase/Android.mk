LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := SdkBase
LOCAL_MODULE_FILENAME := libSdkBase
LOCAL_SRC_FILES := SdkBase.cpp \
                   LoginData.cpp \
                   PayData.cpp \
                   MainApplication.cpp

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)
LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)

include $(BUILD_STATIC_LIBRARY)
$(call import-module,cocos2dx)
