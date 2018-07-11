LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

#LOCAL_CFLAGS := -Wall -Wextra -Werror -Wunused


LOCAL_SRC_FILES:= \
        DemoService.cpp \
		IMyService.cpp \
		ICallback.cpp \
		MyServiceProxy.cpp \
		
		
LOCAL_SHARED_LIBRARIES := \
			libbinder \
			libc \
			libutils \
			libcutils \
			liblog \
			
	
LOCAL_LDLIBS := -llog 	
	
LOCAL_MODULE:= DemoService

include $(BUILD_EXECUTABLE)

