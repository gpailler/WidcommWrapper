#ifndef _CManagedHeadphoneClient
#define _CManagedHeadphoneClient


#define _AFXDLL
#include <afxwin.h>         // MFC core and standard components

#include "Enums.h"
#include "DeviceAddress.h"
#include "DeviceClass.h"

#include <BtIfDefinitions.h>
#include <BtIfClasses.h>
#include "CNativeHeadphoneClient.h"

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace CG::Wrappers::Widcomm::Datatypes;

#using <mscorlib.dll>

namespace CG
{
	namespace Wrappers
	{
		namespace Widcomm
		{
			class CNativeHeadphoneClient;

			/// <summary>
			/// Provides interface headphone client
			/// </summary>
			public ref class CManagedHeadphoneClient sealed
			{
				public:
					/// <summary>
					/// This public constructor instantiate native Widcomm HeadphoneClient class
					/// </summary>
					CManagedHeadphoneClient();

					/// <summary>
					/// This public destructor free unmanaged ressources
					/// </summary>
					~CManagedHeadphoneClient();

					/// <summary>
					/// This function connects to headphone
					/// </summary>
					/// <param name="deviceAddress">The server’s Bluetooth device address. If this parameter is null, an <see cref="Enums::eHeadphoneReturnCode">InvalidParameter</see> error is returned</param>
					/// <param name="deviceAddress">The server’s service name, set string::Empty or custom string</param>
					/// <returns>One value of the <see cref="Enums::eHeadphoneReturnCode">eHeadphoneReturnCode</see> enum.</returns>
					Enums::eHeadphoneReturnCode ConnectHeadphone(DeviceAddress^ deviceAddress, System::String^ serviceName);

					/// <summary>
					/// This function disconnects from headphone
					/// </summary>
					Enums::eHeadphoneReturnCode DisconnectHeadphone(long handle);

					/// <summary>
					/// This delegate is called for each headphone status change.
					/// </summary>
					/// <param name="deviceAddress">The address of the responding device.</param>
					/// <param name="deviceClass">The class of the responding device.</param>
					/// <param name="deviceName">The user-friendly name of the responding device – <see cref="String::Empty">String.Empty</see> when the device is reporting only its address.</param>
					/// <param name="handle">Corresponding handle.</param>
					/// <param name="status">Status change.</param>
					delegate void HeadphoneStatusChangedHandler(DeviceAddress^ deviceAddress, DeviceClass^ deviceClass, System::String^ deviceName, long handle, Enums::eHeadphoneStatus status);

					/// <summary>
					/// This event is fired when headphone status changed.
					/// </summary>
					event HeadphoneStatusChangedHandler^ HeadphoneStatusChanged;

				private:
					// Reference to native HeadphoneClient class
					CNativeHeadphoneClient* _mHeadphoneClient;

					//Free native wdStack resources
					!CManagedHeadphoneClient();

				internal:
					// Used by callback
					void OnHeadphoneStatusChanged(::BD_ADDR bda, ::DEV_CLASS dev_class, ::BD_NAME bd_name, long lHandle, long lStatus);
			};
		}
	}
}
#endif 