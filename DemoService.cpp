#include "IMyService.h"
#include <cutils/log.h>
#include <cutils/properties.h>
#include <binder/IServiceManager.h>
#include "binder/IPCThreadState.h"
#include "binder/ProcessState.h"
#include <MyServiceProxy.h>


int main() {
    //获取service manager引用
    android::sp < android::IServiceManager > sm = android::defaultServiceManager();
    //注册名为"com.chipsailing.binderdemo.myservice"的服务到service manager
     android::status_t ret = sm->addService(android::String16("com.chipsailing.binderdemo.IMyService"), new android::MyServiceProxy());
	if (ret != android::OK) {
       printf("Couldn't register IMyService binder service!");
        return -1;
    }
    android::ProcessState::self()->startThreadPool(); //启动线程池
    android::IPCThreadState::self()->joinThreadPool(); //把主线程加入线程池  等待线程死亡 才会走下去 类似poll
    return 0;
}
