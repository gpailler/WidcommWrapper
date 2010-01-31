#ifndef _DeviceVersionInfo
#define _DeviceVersionInfo

#include <BtIfDefinitions.h>

#include "DeviceAddress.h"
#include "Enums.h"

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
				/// This class contains Device version informations
				/// </summary>
				public ref class DeviceVersionInfo
				{
				private:
					Datatypes::DeviceAddress^ mDeviceAddress;
					Enums::eHCIVersion mHCIVersion;
					System::UInt16 mHCIRevision;
					System::Byte mLMPVersion;
					Enums::eManufacturer mManufacturer;
					System::UInt16 mLMPSubVersion;


				internal:
					DeviceVersionInfo(Datatypes::DeviceAddress^ deviceAddress, Enums::eHCIVersion hciVersion, System::UInt16 hciRevision, Enums::eManufacturer manufacturer, System::Byte lmpVersion, System::UInt16 lmpSubVersion) :
						mDeviceAddress(deviceAddress), mHCIVersion(hciVersion), mHCIRevision(hciRevision), mManufacturer(manufacturer), mLMPVersion(lmpVersion), mLMPSubVersion(lmpSubVersion)
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
					/// Return HCI Version
					/// </summary>
					property Enums::eHCIVersion HCIVersion
					{
						Enums::eHCIVersion get()
						{
							 return this->mHCIVersion;
						}
					}


					/// <summary>
					/// Return HCI Revision
					/// </summary>
					property System::UInt16 HCIRevision
					{
						System::UInt16 get()
						{
							 return this->mHCIRevision;
						}
					}


					/// <summary>
					/// Return LMP Version
					/// </summary>
					property System::Byte LMPVersion
					{
						System::Byte get()
						{
							 return this->mLMPVersion;
						}
					}


					/// <summary>
					/// Return Manufacturer
					/// </summary>
					property Enums::eManufacturer Manufacturer
					{
						Enums::eManufacturer get()
						{
							 return this->mManufacturer;
						}
					}



					/// <summary>
					/// Return LMP Sub Version
					/// </summary>
					property System::UInt16 LMPSubVersion
					{
						System::UInt16 get()
						{
							 return this->mLMPSubVersion;
						}
					}
				};

			}
		}
	}
}

#endif