#include <binder/Parcel.h>
#include <binder/IInterface.h>
#include <cutils/log.h>
#include <sys/types.h>
#include <ICallback.h>
#include <IMyService.h>

namespace android
{

    const android::String16
    IMyService::descriptor("com.chipsailing.binderdemo.IMyService");

    const android::String16&
    IMyService::getInterfaceDescriptor() const {
        return IMyService::descriptor;
    }

    //  使用宏，完成MyService定义
    //IMPLEMENT_META_INTERFACE(MyService, "com.chipsailing.binderdemo.IMyService");

    //服务端，接收远程消息，处理onTransact方法
    status_t BnMyService::onTransact(uint_t code, const Parcel& data,
            Parcel* reply, uint32_t flags) {
        switch (code) {

        case SAYHELLO: {    //收到HELLO命令的处理流程
            printf("BnMyService:: got the client hello  SAYHELLO\n");
            CHECK_INTERFACE(IMyService, data, reply);
            uint32_t a=data.readInt32();
			      uint32_t b=data.readInt32();
			      printf("BnMyService:: SayHello a=%d b=%d\n",a,b);
            const uint32_t ret=sayHello(a,b);
			      reply->writeNoException();
            //必须在writeNoException 才能把数据传递到上层 否在无法接受到数据
            //e:java.lang.RuntimeException: Unknown exception code: 7 msg null
            reply->writeInt32(ret);
            return NO_ERROR;
        }

		case ONHELLOCALLBACK: {    //收到ONHELLOCALLBACK命令的处理流程
            printf("BnMyService:: got the client hello  ONHELLOCALLBACK\n");
            CHECK_INTERFACE(IMyService, data, reply);
            uint32_t a=data.readInt32();
      			uint32_t b=data.readInt32();
      			onHelloCallback(a,b);
      			reply->writeNoException();
            return NO_ERROR;
        }

		case SETCALLBACK: {    //收到SETCALLBACK命令的处理流程
            printf("BnMyService:: got the client hello  SETCALLBACK\n");
            CHECK_INTERFACE(IMyService, data, reply);
		        sp<ICallback> callback = interface_cast<ICallback>(data.readStrongBinder());
            setCallback(callback);
		      	reply->writeNoException();
            return NO_ERROR;
        }

        default:
            break;
        }
        return NO_ERROR;
    }







}
