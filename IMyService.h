#ifndef IMyService_H
#define IMyService_H

#include <ICallback.h>
#include <binder/Parcel.h>
#include <binder/IInterface.h>
#include <cutils/log.h>
#include <sys/types.h>
#include <inttypes.h>
#include <utils/Errors.h>

namespace android
{
    class IMyService : public IInterface ,public IBinder::DeathRecipient
    {

    public:
        enum{
             //定义命令字段  这里顺序必须和app中的aidl文件对应
             SAYHELLO=IBinder::FIRST_CALL_TRANSACTION+0,
             SETCALLBACK=IBinder::FIRST_CALL_TRANSACTION+1,
             ONHELLOCALLBACK=IBinder::FIRST_CALL_TRANSACTION+2,
        };

        //only service not need DECLARE_META_INTERFACE   DECLARE_META_INTERFACE need BpXXService
        //DECLARE_META_INTERFACE(MyService); //使用宏，申明MyService  需要用到client才使用
        virtual uint32_t sayHello(uint32_t a,uint32_t b)=0; //定义方法
       	virtual void setCallback(const sp<ICallback> &callback)=0;
      	virtual void onHelloCallback(uint32_t a,uint32_t b)=0;

        virtual const android::String16& getInterfaceDescriptor() const;
        static const android::String16 descriptor;

        };


        //申明服务端BnMyService
        class BnMyService: public BnInterface<IMyService> {
          public:
            virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply,
                        uint32_t flags = 0);
        };
}
#endif //IMyService_H
