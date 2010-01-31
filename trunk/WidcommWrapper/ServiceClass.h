#ifndef _ServiceClass
#define _ServiceClass

#include <BtIfClasses.h>
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
				public ref class ServiceClass
				{
				public:
					/// <summary>
					/// Convert ServiceClass enumeration value to native Guid
					/// </summary>
					static GUID ToNativeGUID(const Enums::eGuidServiceClass guid)
					{
						switch (guid)
						{
							case (Enums::eGuidServiceClass::Undefined):
								return GUID();
							
							case (Enums::eGuidServiceClass::ServiceDiscoveryServer): return ::CBtIf::guid_SERVCLASS_SERVICE_DISCOVERY_SERVER;
							case (Enums::eGuidServiceClass::BrowseGroupDescriptor): return ::CBtIf::guid_SERVCLASS_BROWSE_GROUP_DESCRIPTOR;
							case (Enums::eGuidServiceClass::PublicBrowseGroup): return ::CBtIf::guid_SERVCLASS_PUBLIC_BROWSE_GROUP;
							case (Enums::eGuidServiceClass::SerialPort): return ::CBtIf::guid_SERVCLASS_SERIAL_PORT;
							case (Enums::eGuidServiceClass::LanAccessUsingPPP): return ::CBtIf::guid_SERVCLASS_LAN_ACCESS_USING_PPP;
							case (Enums::eGuidServiceClass::Panu): return ::CBtIf::guid_SERVCLASS_PANU;
							case (Enums::eGuidServiceClass::Nap): return ::CBtIf::guid_SERVCLASS_NAP;
							case (Enums::eGuidServiceClass::Gn): return ::CBtIf::guid_SERVCLASS_GN;
							case (Enums::eGuidServiceClass::DialupNetworking): return ::CBtIf::guid_SERVCLASS_DIALUP_NETWORKING;
							case (Enums::eGuidServiceClass::IrmcSync): return ::CBtIf::guid_SERVCLASS_IRMC_SYNC;
							case (Enums::eGuidServiceClass::ObexObjectPush): return ::CBtIf::guid_SERVCLASS_OBEX_OBJECT_PUSH;
							case (Enums::eGuidServiceClass::ObexFileTransfer): return ::CBtIf::guid_SERVCLASS_OBEX_FILE_TRANSFER;
							case (Enums::eGuidServiceClass::IrmcSyncCommand): return ::CBtIf::guid_SERVCLASS_IRMC_SYNC_COMMAND;
							case (Enums::eGuidServiceClass::Headset): return ::CBtIf::guid_SERVCLASS_HEADSET;
							case (Enums::eGuidServiceClass::CordlessTelephony): return ::CBtIf::guid_SERVCLASS_CORDLESS_TELEPHONY;
							case (Enums::eGuidServiceClass::Intercom): return ::CBtIf::guid_SERVCLASS_INTERCOM;
							case (Enums::eGuidServiceClass::Fax): return ::CBtIf::guid_SERVCLASS_FAX;
							case (Enums::eGuidServiceClass::HeadsetAudioGateway): return ::CBtIf::guid_SERVCLASS_HEADSET_AUDIO_GATEWAY;
							case (Enums::eGuidServiceClass::PnpInformation): return ::CBtIf::guid_SERVCLASS_PNP_INFORMATION;
							case (Enums::eGuidServiceClass::GenericNetworking): return ::CBtIf::guid_SERVCLASS_GENERIC_NETWORKING;
							case (Enums::eGuidServiceClass::GenericFileTransfer): return ::CBtIf::guid_SERVCLASS_GENERIC_FILETRANSFER;
							case (Enums::eGuidServiceClass::GenericAudio): return ::CBtIf::guid_SERVCLASS_GENERIC_AUDIO;
							case (Enums::eGuidServiceClass::GenericTelephony): return ::CBtIf::guid_SERVCLASS_GENERIC_TELEPHONY;
							case (Enums::eGuidServiceClass::BppPrinting): return ::CBtIf::guid_SERVCLASS_BPP_PRINTING;
							case (Enums::eGuidServiceClass::HcrpPrinting): return ::CBtIf::guid_SERVCLASS_HCRP_PRINTING;
							case (Enums::eGuidServiceClass::SppPrinting): return ::CBtIf::guid_SERVCLASS_SPP_PRINTING;
							case (Enums::eGuidServiceClass::HumanInterface): return ::CBtIf::guid_SERVCLASS_HUMAN_INTERFACE;
							case (Enums::eGuidServiceClass::AudioSink): return ::CBtIf::guid_SERVCLASS_AUDIO_SINK;

							default: throw gcnew System::ArgumentException("Invalid value");
						}
					}


					/// <summary>
					/// Convert managed GUID to native Guid
					/// </summary>
					static GUID ToNativeGUID(System::Guid guid)
					{
						array<System::Byte>^ guidData = guid.ToByteArray();
						pin_ptr<System::Byte> pData = &(guidData[0]);

						return *(GUID *)pData;
					}


					/// <summary>
					/// Convert ServiceClass enumeration value to managed Guid
					/// </summary>
					static System::Guid ToManagedGUID(const Enums::eGuidServiceClass guid)
					{
						GUID nativeGuid = ServiceClass::ToNativeGUID(guid);

						return ToManagedGUID(nativeGuid);
					}


					/// <summary>
					/// Convert native GUID to managed Guid
					/// </summary>
					static System::Guid ToManagedGUID(const GUID _guid)
					{
						return System::Guid::Guid(_guid.Data1, _guid.Data2, _guid.Data3, 
									_guid.Data4[0], _guid.Data4[1], 
									_guid.Data4[2], _guid.Data4[3], 
									_guid.Data4[4], _guid.Data4[5], 
									_guid.Data4[6], _guid.Data4[7]);
					}


					/// <summary>
					/// Convert native GUID to ServiceClass enumeration value
					/// </summary>
					static Enums::eGuidServiceClass ToEnum(const GUID _guid)
					{
						return ServiceClass::ToEnum(ServiceClass::ToManagedGUID(_guid));
					}


					/// <summary>
					/// Convert managed Guid to ServiceClass enumeration value
					/// </summary>
					static Enums::eGuidServiceClass ToEnum(const System::Guid& guid)
					{
						System::Array^ eValues = System::Enum::GetValues(Enums::eGuidServiceClass::typeid);
						for (int i = 0; i < eValues->Length; i++)
						{
							Enums::eGuidServiceClass val = (Enums::eGuidServiceClass)eValues->GetValue(i);
							if (guid == ServiceClass::ToManagedGUID(val))
								return val;
						}

						return Enums::eGuidServiceClass::Undefined;
					}
				};
			}
		}
	}
}

#endif