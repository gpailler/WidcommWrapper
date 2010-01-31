#include "CNativeBtIf.h"

namespace CG
{
	namespace Wrappers
	{
		namespace Widcomm
		{
			CNativeBtIf::CNativeBtIf(CManagedBtIf^ managedBtIf)
			{
				this->mManagedBtIf = managedBtIf; 
			}


			CNativeBtIf::~CNativeBtIf()
			{
				//stub WIDCOMMSDK_ShutDown();
			}


			void CNativeBtIf::OnDeviceResponded(::BD_ADDR _bda, ::DEV_CLASS _devClass, ::BD_NAME _bdName, ::BOOL _bConnected)
			{
				this->mManagedBtIf->OnDeviceResponded(_bda, _devClass, _bdName, _bConnected);
			}


			void CNativeBtIf::OnInquiryComplete(::BOOL _success, ::SHORT _num_responses)
			{
				this->mManagedBtIf->OnInquiryComplete(_success, _num_responses);
			}


			void CNativeBtIf::OnDiscoveryComplete()
			{
				this->mManagedBtIf->OnDiscoveryComplete();
			}


			void CNativeBtIf::OnDiscoveryComplete(::UINT16 _nRecs, ::LONG _lResultCode)
			{
				this->mManagedBtIf->OnDiscoveryComplete(_nRecs, _lResultCode);
			}


			void CNativeBtIf::OnStackStatusChange(CBtIf::STACK_STATUS _new_status)
			{
				this->mManagedBtIf->OnStackStatusChange(_new_status);
			}
		}
	}
}