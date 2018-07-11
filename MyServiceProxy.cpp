#include <IMyService.h>
#include <MyServiceProxy.h>
#include <ICallback.h>

namespace android{

	uint32_t MyServiceProxy::sayHello(uint32_t a,uint32_t b){
		if (mICallback!=NULL)
   	  {
    	onHelloCallback(a,b);
      }
    	return a+b;
	}

 	void MyServiceProxy::setCallback(const sp<ICallback> &callback){
     if (callback==NULL)
     {
     	printf("ICallback is Null\n");
     }else{
     	printf("ICallback is not Null\n");
     	IInterface::asBinder(callback)->linkToDeath(this);
     	mICallback=callback;
     }
 	}

	void MyServiceProxy::onHelloCallback(uint32_t a,uint32_t b){
     if (mICallback!=NULL)
     {
     	mICallback->onHelloCallback(a,b);
     }
	}

	void MyServiceProxy::binderDied(const wp<IBinder>& who){
		 printf("MyServiceProxy::binderDied \n");
        if (IInterface::asBinder(mICallback) == who) {
            printf("mICallback is dead \n");
            mICallback = NULL;
	}
}
}