#ifndef _CNativeBtIf
#define _CNativeBtIf


#define _AFXDLL
#include <afxwin.h>         // MFC core and standard components

#include <BtIfDefinitions.h>
#include <BtIfClasses.h>
#include <vcclr.h>

#include "CManagedBtIf.h"




namespace CG
{
	namespace Wrappers
	{
		namespace Widcomm
		{
			ref class CManagedBtIf ;


			class CNativeBtIf : public CBtIf
			{
				public:
					CNativeBtIf(CManagedBtIf^ managedBtIf);
					virtual ~CNativeBtIf();

				private:
					//Reference to managed wrapper class. Usefull to wrap virtual native functions
					gcroot<CManagedBtIf^> mManagedBtIf; 


					virtual void OnDeviceResponded(::BD_ADDR _bda, ::DEV_CLASS _devClass, ::BD_NAME _bdName, ::BOOL _bConnected);
					virtual void OnInquiryComplete(::BOOL _success, ::SHORT _num_responses);
					virtual void OnDiscoveryComplete();
					virtual void OnDiscoveryComplete(::UINT16 _nRecs, ::LONG _lResultCode);
					virtual void OnStackStatusChange(::CBtIf::STACK_STATUS _new_status);
			};
		}
	}
}

#endif