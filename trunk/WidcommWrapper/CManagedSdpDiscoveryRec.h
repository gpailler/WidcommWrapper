#ifndef _SdpDiscoveryRec
#define _SdpDiscoveryRec

#define _AFXDLL
#include <afxwin.h>         // MFC core and standard components

#include <BtIfDefinitions.h>

#include "Enums.h"
#include "ServiceClass.h"

using namespace System;
using namespace System::Runtime::InteropServices;



namespace CG
{
	namespace Wrappers
	{
		namespace Widcomm
		{
			/// <summary>
			/// When an application reads the services from a remote device, via CManagedBtIf.ReadDiscoveryRecords(), the service records are
			/// returned in objects of this class. Methods are provided to interrogate the discovery record.
			/// </summary>
			public ref class CManagedSdpDiscoveryRec
			{
			public:
				ref class SdpProtocolElem
				{
					public:
						Enums::eUuidProtocol mUuidProtocol;
						System::UInt16 mNumParams;
						array<System::UInt16>^ mParams;
				
						SdpProtocolElem()
						{
							mParams = gcnew array<System::UInt16>(SDP_MAX_PROTOCOL_PARAMS);
						}
				};



			private:
				::CSdpDiscoveryRec* _mRecs;
				array<CManagedSdpDiscoveryRec^>^ mListRecs;
				int mIdx;
				bool mDisposed;


			internal:
				CManagedSdpDiscoveryRec(::CSdpDiscoveryRec* _recs, int idx, array<CManagedSdpDiscoveryRec^>^ listRecs);


			public:
				/// <summary>
				/// To release native resources stored in this object, you should call Dispose() method after using object
				/// </summary>
				~CManagedSdpDiscoveryRec();


				!CManagedSdpDiscoveryRec();


				/// <summary>
				/// The service name
				/// </summary>
				property System::String^ ServiceName
				{
					System::String^ get();
				}


				/// <summary>
				/// The service GUID as Enum value
				/// </summary>
				property Enums::eGuidServiceClass ServiceClassEnum
				{
					Enums::eGuidServiceClass get();
				}


				/// <summary>
				/// The service GUID
				/// </summary>
				property System::Guid ServiceClassGuid
				{
					System::Guid get();
				}


				/// <summary>
				/// This function looks through the discovery record for the protocol descriptor list and, if found, returns the list element for the specified <see cref="Enums::eUuidProtocol">protocol UUID</see> to the caller.
				/// Specialized versions of this function are <see cref="FindRFCommScn">FindRFCommScn</see> for the SCN parameter, and <see cref="FindL2CapPsm">FindL2CapPsm</see> for the PSM parameter).
				/// This function would be used for other predefined protocols or new protocols.
				/// </summary>
				/// <param name="uuid">The <see cref="Enums::eUuidProtocol">UUID</see> of the protocol layer being looked for.</param>
				/// <param name="elem">The protocol list element.</param>
				/// <returns><b>true</b> if the list element was found; <b>false</b>, otherwise.</returns>
				bool FindProtocolListEnum(Enums::eUuidProtocol uuid, [Out] SdpProtocolElem^% elem);


				/// <summary>
				/// This function looks through the discovery record for the additional protocol descriptor list and, if found, returns the list element for the specified <see cref="Enums::eUuidProtocol">protocol UUID</see> to the caller.
				/// </summary>
				/// <param name="uuid">The <see cref="Enums::eUuidProtocol">UUID</see> of the protocol layer being looked for.</param>
				/// <param name="elem">The protocol list element.</param>
				/// <returns><b>true</b> if the list element was found; <b>false</b>, otherwise.</returns>
				bool FindAdditionalProtocolListElem(Enums::eUuidProtocol uuid, [Out] SdpProtocolElem^% elem);


				/// <summary>
				/// This function looks through the discovery record for the profile descriptor list and, if found, returns the profile version to the caller.
				/// </summary>
				/// <param name="guid">The GUID of the profile being searched for.</param>
				/// <param name="version">The version found.</param>
				/// <returns><b>true</b> if the profile descriptor list was found; <b>false</b>, otherwise.</returns>
				bool FindProfileVersion(Enums::eGuidServiceClass guid, [Out] System::UInt16% version);

				
				/// <summary>
				/// This function looks through the discovery record for the protocol descriptor list and, if found, tries to extract the RFCOMM SCN parameter from it.
				/// </summary>
				/// <param name="scn">The location where the function will store the SCN, if found.</param>
				/// <returns><b>true</b> if an SCN was found; <b>false</b>, otherwise.</returns>
				bool FindRFCommScn([Out] System::UInt16% scn);


				/// <summary>
				/// This function looks through the discovery record for the protocol descriptor list and, if found, tries to extract the L2CAP PSM parameter from it.
				/// </summary>
				/// <param name="psm">The location where the function will store the PSM, if found.</param>
				/// <returns><b>true</b> if an PSM was found; <b>false</b>, otherwise.</returns>
				bool FindL2CapPsm([Out] System::UInt16% psm);


				bool FindAttribute(Enums::eAttributeId attributeId, [Out] cli::array<System::Object^>^% output);
			};
		}
	}
}

#endif