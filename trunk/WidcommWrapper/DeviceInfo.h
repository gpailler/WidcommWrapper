#ifndef _DeviceInfo
#define _DeviceInfo

#include <BtIfClasses.h>

#include "DeviceAddress.h"
#include "DeviceClass.h"

using namespace System;
using namespace System::Runtime::InteropServices;



namespace CG
{
	namespace Wrappers
	{
		namespace Widcomm
		{
			namespace Datatypes
			{
				/// <summary>
				/// This class contains usefull information about a Device
				/// </summary>
				public ref class DeviceInfo
				{
				private:
					DeviceAddress^ mDeviceAddress;
					DeviceClass^ mDeviceClass;
					System::String^ mDeviceName;
					bool mPaired;
					bool mConnected;


				internal:
					/// <summary>
					/// Convert an unmanaged REM_DEV_INFO to managed DeviceInfo class
					/// </summary>
					/// <param name="_deviceInfo">Unmanaged DeviceInfo</param>
					/// <exception cref="System::ArgumentNullException">Argument is null</exception>
					static DeviceInfo^ ConvertFrom(::CBtIf::REM_DEV_INFO* _deviceInfo)
					{
						if (_deviceInfo == NULL)
						{
							throw gcnew System::ArgumentNullException("_deviceInfo argument can't be null");
						}


						return gcnew DeviceInfo(
							Datatypes::DeviceAddress::ConvertFrom(_deviceInfo->bda),
							Datatypes::DeviceClass::ConvertFrom(_deviceInfo->dev_class),
							gcnew System::String((const char*)_deviceInfo->bd_name),
							_deviceInfo->b_paired != 0,
							_deviceInfo->b_connected != 0
							);
					}


					DeviceInfo(Datatypes::DeviceAddress^ deviceAddress, Datatypes::DeviceClass^ deviceClass, System::String^ name, bool paired, bool connected):
						mDeviceAddress(deviceAddress), mDeviceClass(deviceClass), mDeviceName(name), mPaired(paired), mConnected(connected)
					{
					}


				public:
					/// <summary>
					/// Return device address
					/// </summary>
					property Datatypes::DeviceAddress^ DeviceAddress
					{
						Datatypes::DeviceAddress^ get()
						{
							return this->mDeviceAddress;
						}
					}


					/// <summary>
					/// Return device class
					/// </summary>
					property Datatypes::DeviceClass^ DeviceClass
					{
						Datatypes::DeviceClass^ get()
						{
							return this->mDeviceClass;
						}
					}


					/// <summary>
					/// Return device name
					/// </summary>
					property System::String^ Name
					{
						System::String^ get()
						{
							return this->mDeviceName;
						}
					}


					/// <summary>
					/// Return device pairing status
					/// </summary>
					property bool Paired
					{
						bool get()
						{
							return this->mPaired;
						}
					}

					/// <summary>
					/// Return device connection status
					/// </summary>
					property bool Connected
					{
						bool get()
						{
							return this->mConnected;
						}
					}

					/// <summary>
					/// This function return device infos in human-readable format
					/// </summary>
					/// <returns>Device name, Device address, Connection status, Paired status and Device class</returns>
					virtual System::String^ ToString() override
					{
						return String::Format("Device name: {0}, Device address: {1}, Connected: {2}, Paired: {3}{4}Device class: {5}",
							this->mDeviceName, this->mDeviceAddress, this->mConnected, this->mPaired, Environment::NewLine, this->mDeviceClass);
					}
				};
			}
		}
	}
}

#endif