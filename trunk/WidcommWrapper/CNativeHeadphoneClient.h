#ifndef _CNativeHeadPhoneClient
#define _CNativeHeadPhoneClient


#define _AFXDLL
#include <afxwin.h>         // MFC core and standard components

#include <BtIfDefinitions.h>
#include <BtIfClasses.h>
#include <vcclr.h>

#include "CManagedHeadphoneClient.h"




namespace CG
{
	namespace Wrappers
	{
		namespace Widcomm
		{
			ref class CManagedHeadphoneClient;


			class CNativeHeadphoneClient : public CHeadphoneClient
			{
				public:
					CNativeHeadphoneClient(CManagedHeadphoneClient^ managedBtIf);
					virtual ~CNativeHeadphoneClient();

					// Reference to managed wrapper class. Used by callback
					gcroot<CManagedHeadphoneClient^> mManagedHeadphoneClient;
			};
		}
	}
}
#endif