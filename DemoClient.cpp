#include "IMyService.h"
#include <cutils/log.h>
#include <binder/IServiceManager.h>
#include <cutils/properties.h>

int main() {
    //获取service manager引用
    android::sp < android::IServiceManager > sm = android::defaultServiceManager();
    //获取名为"service.myservice"的binder接口
    android::sp < android::IBinder > binder = sm->getService(android::String16("com.chipsailing.binderdemo.IMyService"));
    //将biner对象转换为强引用类型的IMyService
    android::sp<android::IMyService> cs = android::interface_cast < android::IMyService> (binder);
    //利用binder引用调用远程sayHello()方法
    cs->sayHello(1,2);
    return 0;
}
