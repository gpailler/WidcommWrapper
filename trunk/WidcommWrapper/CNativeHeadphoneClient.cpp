#include "CNativeHeadphoneClient.h"

namespace CG
{
	namespace Wrappers
	{
		namespace Widcomm
		{
			void OnHAGStatusChangeCB(void *userData, BD_ADDR bda, DEV_CLASS dev_class, BD_NAME bd_name, long lHandle, long lStatus);

			CNativeHeadphoneClient::CNativeHeadphoneClient(CManagedHeadphoneClient^ managedHeadphoneClient)
			{
				this->mManagedHeadphoneClient = managedHeadphoneClient; 

				// Register callback
				this->RegStatusChangeCB(OnHAGStatusChangeCB, this);
			}

			CNativeHeadphoneClient::~CNativeHeadphoneClient()
			{
			}

			void OnHAGStatusChangeCB(void *userData, BD_ADDR bda, DEV_CLASS dev_class, BD_NAME bd_name, long lHandle, long lStatus)
			{
				// Notify managed side
				CNativeHeadphoneClient* pThis = (CNativeHeadphoneClient*)userData;
				pThis->mManagedHeadphoneClient->OnHeadphoneStatusChanged(bda, dev_class, bd_name, lHandle, lStatus);
			}
		}
	}
} 