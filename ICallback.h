#ifndef ICallback_H
#define ICallback_H

#include <binder/Parcel.h>
#include <binder/IInterface.h>
#include <cutils/log.h>
#include <sys/types.h>

namespace android{

	class ICallback : public IInterface{
		public:
		DECLARE_META_INTERFACE(Callback);
		virtual status_t onHelloCallback(uint32_t a,uint32_t b)=0;
	};

   //申明客户端BpMyService
    class BpCallback : public BpInterface<ICallback> {
    public:
        BpCallback(const sp<IBinder>& impl);

		virtual status_t onHelloCallback(uint32_t a,uint32_t b);
    };

}
#endif //ICallback_H
