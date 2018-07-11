
#include <binder/Parcel.h>
#include <binder/IInterface.h>
#include <cutils/log.h>
#include <sys/types.h>  
#include <ICallback.h>
#include <MyServiceProxy.h>

namespace android{
 enum{
	 ONHELLOCALLBACK=IBinder::FIRST_CALL_TRANSACTION+0,
 };

			
    //使用宏，完成Callback定义  dtu.lib
    IMPLEMENT_META_INTERFACE(Callback, "com.chipsailing.binderdemo.ICallback");
	  
	BpCallback::BpCallback(const sp<IBinder>& impl) :
            BpInterface<ICallback>(impl) {
    }
	
	//客户端 发往服务端
	status_t BpCallback::onHelloCallback(uint32_t a,uint32_t b){
		
		printf("BpCallback:: onHelloCallback a=%d b=%d\n",a,b);
		Parcel _data,_reply;
		_data.writeInterfaceToken(ICallback::getInterfaceDescriptor());
		_data.writeInt32(a);
		_data.writeInt32(b);
		return remote()->transact(ONHELLOCALLBACK,_data,&_reply);
	}
}