#include <IMyService.h>
#include <ICallback.h>


namespace android{
class MyServiceProxy : public BnMyService{

public:
		virtual uint32_t sayHello(uint32_t a,uint32_t b);
		virtual void setCallback(const sp<ICallback> &callback);
		virtual void onHelloCallback(uint32_t a,uint32_t b);
    
    MyServiceProxy(){};
    virtual ~MyServiceProxy(){};
    void binderDied(const wp<IBinder>& who);
    sp<ICallback> mICallback;

};
}
