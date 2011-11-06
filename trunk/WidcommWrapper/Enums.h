#ifndef _TypesEnums
#define _TypesEnums

#include <BtIfDefinitions.h>
#include <BtIfClasses.h>

using namespace System;




namespace CG
{
	namespace Wrappers
	{
		namespace Widcomm
		{
			namespace Enums
			{
				[FlagsAttribute]
				/// <summary>
				/// Service class
				/// </summary>
				public enum class eServiceClass
				{
					Undefined			= 0,
					Networking			= (1 << 1),
					Rendering			= (1 << 2),
					Capturing			= (1 << 3),
					ObjectTransfer		= (1 << 4),
					ObjectAudio			= (1 << 5),
					ObjectTelephony		= (1 << 6),
					ObjectInformation	= (1 << 7)
				};


				/// <summary>
				/// Major device class
				/// </summary>
				public enum class eMajorDeviceClass
				{
					Misc				= 0x00,
					Computer			= 0x01,
					Phone				= 0x02,
					LanAccess			= 0x03,
					Audio				= 0x04,
					Peripheral			= 0x05,
					Imaging				= 0x06,
					Unspecified			= 0x1F,
					
					LimitedDiscMode		= 0x20
				};


				/// <summary>
				/// Minor device class (be carefull, this enum mix all values for all major device class.)
				/// </summary>
				public enum class eMinorDeviceClass
				{
					CompUnclassified		= 0x00,
					CompWorkstation			= (0x01 << 2),
					CompServer				= (0x02 << 2),
					CompLaptop				= (0x03 << 2),
					CompHandled				= (0x04 << 2),
					CompPalm				= (0x05 << 2),

					PhoneUnclassified		= 0x00,
					PhoneCellular			= (0x01 << 2),
					PhoneCordless			= (0x02 << 2),
					PhoneSmart				= (0x03 << 2),
					PhoneModem				= (0x04 << 2),

					ImagingUnclassified		= 0x00,
					ImagingDisplay			= (0x04 << 2),
					ImagingCamera			= (0x08 << 2),
					ImagingScanner			= (0x10 << 2),
					ImagingPrinter			= (0x20 << 2),

					AudioUnclassified		= 0x00,
					AudioHeadset			= (0x01 << 2)
				};

				
				/// <summary>
				/// HCI version
				/// </summary>
				public enum class eHCIVersion
				{
					/// <summary>Bluetooth HCI specification 1.0b</summary>
					BluetoothHCISpecification1_0b	= 0x00,
					/// <summary>Bluetooth HCI specification 1.1</summary>
					BluetoothHCISpecification1_1	= 0x01,
					/// <summary>Bluetooth HCI specification 1.2</summary>
					BluetoothHCISpecification1_2	= 0x02,
					/// <summary>Bluetooth HCI specification 2.0</summary>
					BluetoothHCISpecification2_0	= 0x03

					//0x04-0xFFF Reserved for future use
				};

				/// <summary>
				/// Bluetooth hardware manufacturers
				/// </summary>
				/// <remarks>
				/// Not complete list
				/// </remarks>
				public enum class eManufacturer
				{
					/// <summary>Ericsson</summary>
					Ericsson			= 0,
					/// <summary>Nokia</summary>
					Nokia				= 1,
					/// <summary>Intel</summary>
					Intel				= 2,
					/// <summary>Ibm</summary>
					Ibm					= 3,
					/// <summary>Toshiba</summary>
					Toshiba				= 4,
					/// <summary>3Com</summary>
					_3Com				= 5,
					/// <summary>Microsoft</summary>
					Microsoft			= 6,
					/// <summary>Lucent</summary>
					Lucent				= 7,
					/// <summary>Motorola</summary>
					Motorola			= 8,
					/// <summary>Infineon</summary>
					Infineon			= 9,
					/// <summary>CSR</summary>
					CSR					= 10,
					/// <summary>Sillicon Wave</summary>
					SiliconWave			= 11,
					/// <summary>DigiAnswer</summary>
					DigiAnswer			= 12,
					/// <summary>Texas Instruments</summary>
					TexasInstruments	= 13,
					/// <summary>Parthus</summary>
					Parthus				= 14,
					/// <summary>Broadcom</summary>
					Broadcom			= 15
				};


				public enum class eGuidServiceClass
				{
					Undefined,
					ServiceDiscoveryServer,
					BrowseGroupDescriptor,
					PublicBrowseGroup,
					SerialPort,
					LanAccessUsingPPP,
					Panu,
					Nap,
					Gn,
					DialupNetworking,
					IrmcSync,
					ObexObjectPush,
					ObexFileTransfer,
					IrmcSyncCommand,
					Headset,
					CordlessTelephony,
					Intercom,
					Fax,
					HeadsetAudioGateway,
					PnpInformation,
					GenericNetworking,
					GenericFileTransfer,
					GenericAudio,
					GenericTelephony,
					BppPrinting,
					HcrpPrinting,
					SppPrinting,
					HumanInterface,
					AudioSink,
				};


				public enum class eUuidProtocol : System::UInt16
				{
					Sdp			= 0x0001,
					Udp			= 0x0002,
					RfComm		= 0x0003,
					Tcp			= 0x0004,
					TcsBin		= 0x0005,
					TcsAt		= 0x0006,
					Obex		= 0x0008,
					Ip			= 0x0009,
					Ftp			= 0x000A,
					Http		= 0x000C,
					Wsp			= 0x000E,
					Bnep		= 0x000F,
					Upnp		= 0x0010,
					Hidp		= 0x0011,
					HcrpCtrl	= 0x0012,
					HcrpData	= 0x0014,
					HcrpNotif	= 0x0016,
					Avctp		= 0x0017,
					Avdtp		= 0x0019,
					L2cap		= 0x0100
				};


				public enum class eUuidServiceClass : System::UInt16
				{
					ServiceDiscoveryServer			= 0X1000,
					BrowseGroupDescriptor			= 0X1001,
					PublicBrowseGroup				= 0X1002,
					SerialPort						= 0X1101,
					LanAccessUsingPpp				= 0X1102,
					DialupNetworking				= 0X1103,
					IrmcSync						= 0X1104,
					ObexObjectPush					= 0X1105,
					ObexFileTransfer				= 0X1106,
					IrmcSyncCommand					= 0X1107,
					Headset							= 0X1108,
					CordlessTelephony				= 0X1109,
					Intercom						= 0X1110,
					Fax								= 0X1111,
					HeadsetAudioGateway				= 0X1112,
					PnpInformation					= 0X1200,
					GenericNetworking				= 0X1201,
					GenericFileTransfer				= 0X1202,
					GenericAudio					= 0X1203,
					GenericTelephony				= 0X1204,
					AudioSink						= 0X110B
				};

				
				public enum class eAttributeId : System::UInt16
				{
					ServiceRecordHdl				= 0x0000,
					ServiceClassIdList				= 0x0001,
					ServiceRecordState				= 0x0002,
					ServiceId						= 0x0003,
					ProtocolDescList				= 0x0004,
					BrowseGroupList					= 0x0005,
					LanguageBaseAttrIdList			= 0x0006,
					ServiceInfoTimeToLive			= 0x0007,
					ServiceAvailability				= 0x0008,
					BtProfileDescList				= 0x0009,
					DocumentationUrl				= 0x000A,
					ClientExeUrl					= 0x000B,
					IconUrl							= 0x000C,
					AdditionProtoDescLists			= 0x000D,
					
					LanguageBaseId					= 0x0100,
					ServiceName						= ((System::UInt16)LanguageBaseId + 0x0000),
					ServiceDescription				= ((System::UInt16)LanguageBaseId + 0x0001),
					ProviderName					= ((System::UInt16)LanguageBaseId + 0x0002),

					VersionOrGroup					= 0x0200,
					VersionNumberList				= VersionOrGroup,
					GroupId							= VersionOrGroup,
					ServiceDatabaseState			= 0x0201,
					DataStoresOrNetwork				= 0x0301,
					SupportedDataStores				= DataStoresOrNetwork,
					ExternalNetwork					= DataStoresOrNetwork,
					Fax1OrAudVolOrDevName			= 0x0302,
					FaxClass1OrAudioVolume			= Fax1OrAudVolOrDevName,
					FaxClass1Support				= Fax1OrAudVolOrDevName,
					RemoteAudioVolumeControl		= Fax1OrAudVolOrDevName,
					DeviceName						= Fax1OrAudVolOrDevName,
					FormatsOrFax20					= 0x0303,
					SupportedFormatsList			= FormatsOrFax20,
					FaxClass20Support				= FormatsOrFax20,
					FaxClass2OrFriendlyName			= 0x0304,
					FaxClass2Support				= FaxClass2OrFriendlyName,
					FriendlyName					= FaxClass2OrFriendlyName,
					AudioFeedbackSupport			= 0x0305
				};

				public enum class eStackStatus
				{
					/// <summary>Device is present, but down</summary>
					Down,
					/// <summary>Device is present and UP</summary>
					Up,
					/// <summary>Device is in error (maybe being removed)</summary>
					Error,
					/// <summary>Stack is being unloaded</summary>
					Unloaded,
					/// <summary>Stack reloaded after being unloaded</summary>
					Reloaded
				};

				
				public enum class eDiscoveryResult
				{
					Success,
					/// <summary>Could not connect to remote device</summary>
					ConnectError,
					/// <summary>Remote device rejected the connection</summary>
					ConnectRejected,
					/// <summary>Security failed</summary>
					Security,
					/// <summary>Remote Service Record Error</summary>
					BadRecord,
					/// <summary>Other error</summary>
					OtherError
				};


				public enum class eBondReturnCode
				{
					/// <summary>Everything is OK.</summary>
					Success,
					/// <summary>PIN code is <b>null</b> or too long.</summary>
					BadParameter,
					/// <summary>Cannot access the local Bluetooth COM server.</summary>
					NoBtServer,
					/// <summary>The devices hae been previously bonded.</summary>
					/// <remarks>Maintained for compatibility, BTW stack allows rebonding</remarks>
					AlreadyBonded,
					/// <summary>If timeout or rejection by other device.</summary>
					Fail,
					/// <summary>Device reports too many failed attempts to bond, will continue until after device security timeout.</summary>
					/// <remarks>Pairing has failed repeatedly, and further attempts will continue to return this code until after the device security timeout</remarks>
					RepeatedAttempts
				};


				public enum class eRemoteDeviceInfoReturnCode
				{
					/// <summary>Success response</summary>
					Success,
					/// <summary>No more devices found</summary>
					Eof,
					/// <summary>Can not find exsiting entry for bda provided as input</summary>
					Error,
					/// <summary>Out of memory</summary>
					MemoryError
				};



				public enum class eRole
				{
					NewMaster,
					NewSlave
				};

				/// <summary>
				/// Predefined security level
				/// </summary>
				public enum class eSecurityId : System::Byte
				{
					SdpServer		= 0,
					SerialPort		= 1,
					LanAccess		= 2,
					Dun				= 3,
					IrmcSync		= 4,
					ObexPush		= 5,
					ObexFtp			= 6,
					IrmcSyncMd		= 7,
					Headset			= 8,
					Cordless		= 9,
					Intercom		= 10,
					Fax				= 11,
					HeadsetAg		= 12,
					PnpInfo			= 13,
					Panu			= 14,
					Nap				= 15,
					Gn				= 16,
					HcrpCtrl		= 17,
					Avdtp			= 18,
					Avctp			= 19,
					HfHandsfree		= 20,
					AgHandsFree		= 21,
					HidCtrl			= 22,
					HidIntr			= 23,
					Sap				= 24,
					Bip				= 25,
					HcrpData		= 26,
					BipPrint		= 27,
					Bpp				= 28
				};


				[FlagsAttribute]
				/// <summary>
				/// Valid Security Service Levels
				/// </summary>
				public enum class eSecurityLevel
				{
					/// <summary>Nothing required</summary>
					None			= 0x0000,
					/// <summary>Inbound call requires authorization</summary>
					InAuthorize		= 0x0001,
					/// <summary>Inbound call requires authentication </summary>
					InAuthenticate	= 0x0002,
					/// <summary>Inbound call requires encryption </summary>
					InEncrypt		= 0x0004,
					/// <summary>Outbound call requires authorization</summary>
					OutAuthorize	= 0x0008,
					/// <summary>Outbound call requires authentication</summary>
					OutAuthenticate	= 0x0010,
					/// <summary>Outbound call requires encryption</summary>
					OutEncrypt		= 0x0020,
					/// <summary>Bonding</summary>
					Bond			= 0x0040
				};


				public enum class WBT_STATUS_CODE
				{
					WBT_SUCCESS,
					WBT_ERROR,
					WBT_NO_SECURITY_API_OBJECT,
					WBT_SECURITY_ERR_CREATE_API,
					WBT_SECURITY_ERR_CANNOT_CREATE_API,
					WBT_SECURITY_ERR_INVALID_DISPATCH,

					WBT_NO_BTM_API_OBJECT,
					WBT_BTM_ERR_CANNOT_CREATE_API,
					WBT_BTM_ERR_INVALID_DISPATCH,

					WBT_NO_GAP_API_OBJECT,

					WBT_NO_FTP_API_OBJECT,
					WBT_FTP_ERR_CANNOT_CREATE_API,
					WBT_FTP_ERR_INVALID_DISPATCH,

					WBT_NO_SPP_API_OBJECT,
					WBT_SPP_ERR_CANNOT_CREATE_API,
					WBT_SPP_ERR_INVALID_DISPATCH,
					WBT_SPP_ERR_NO_API,
					WBT_SPP_ERR_NO_DISPATCH,
					WBT_SPP_ERROR,

					WBT_NO_DUN_API_OBJECT,
					WBT_DUN_ERR_CREATE_API,
					WBT_DUN_ERR_CANNOT_CREATE_API,
					WBT_DUN_ERR_INVALID_DISPATCH,
					WBT_DUN_ERR_NO_API,
					WBT_DUN_ERR_NO_DISPATCH,
					WBT_DUN_ERROR,
				    
					WBT_NO_FAX_API_OBJECT,
					WBT_FAX_ERR_CREATE_API,
					WBT_FAX_ERR_CANNOT_CREATE_API,
					WBT_FAX_ERR_INVALID_DISPATCH,
					WBT_FAX_ERR_NO_API,
					WBT_FAX_ERR_NO_DISPATCH,
					WBT_FAX_ERROR,

					WBT_NO_LAP_API_OBJECT,
					WBT_LAP_ERR_CREATE_API,
					WBT_LAP_ERR_CANNOT_CREATE_API,
					WBT_LAP_ERR_INVALID_DISPATCH,
					WBT_LAP_ERR_NO_API,
					WBT_LAP_ERR_NO_DISPATCH,
					WBT_LAP_ERROR,  

					WBT_NO_OPP_API_OBJECT,
					WBT_OPP_ERR_CREATE_API,
					WBT_OPP_ERR_CANNOT_CREATE_API,
					WBT_OPP_ERR_INVALID_DISPATCH,
					WBT_OPP_ERROR,  

					WBT_NO_SYNC_API_OBJECT,
					WBT_SYNC_ERR_CANNOT_CREATE_API,
					WBT_SYNC_ERR_INVALID_DISPATCH,
					WBT_SYNC_ERR_NO_API,
					WBT_SYNC_ERROR,  

					WBT_NO_TRACE_API_OBJECT,
					WBT_TRACE_ERR_CANNOT_CREATE_API,
					WBT_TRACE_ERR_INVALID_DISPATCH,
					WBT_TRACE_ERR_NO_API,
					WBT_TRACE_ERR_MALLOC_SINK,
					WBT_TRACE_ERR_INVALID_SINK,
					WBT_TRACE_ERROR,  

					WBT_NO_HSP_API_OBJECT,
					WBT_HSP_ERR_CANNOT_CREATE_API,
					WBT_HSP_ERR_INVALID_DISPATCH,
					WBT_NO_HAG_API_OBJECT,
					WBT_HAG_ERR_CANNOT_CREATE_API,
					WBT_HAG_ERR_INVALID_DISPATCH,

					WBT_EXCEPTION,
					WBT_OLE_EXCEPTION,                      // Most commonly, receiving this error means the connection to
															// the COM server "btstackserver.exe" was lost
					WBT_C_EXCEPTION,
					WBT_COM_EXCEPTION,

					WBT_NO_HCRP_API_OBJECT,
					WBT_HCRP_ERR_CREATE_API,
					WBT_HCRP_ERR_CANNOT_CREATE_API,
					WBT_HCRP_ERR_INVALID_DISPATCH,
					WBT_HCRP_ERR_NO_API,
					WBT_HCRP_ERR_NO_DISPATCH,
					WBT_HCRP_ERROR,
				    
					WBT_NO_VDP_API_OBJECT,
					WBT_VDP_ERR_CANNOT_CREATE_API,
					WBT_VDP_ERR_INVALID_DISPATCH,

					/* Errors returned from COM server */
					WBT_COM_ERR_BASE = 0x81000000,

					WBT_BUSY,                               // Busy with another operation
					WBT_ERR_SERVER_DOWN,
					WBT_ERR_ALLOC_SCN_FAILED,               
					WBT_ERR_SDP_FULL,                       
					WBT_ERR_RFCOMM_CONNECTION_FAILED,       
					WBT_ERR_SERVICE_NOT_FOUND,              
					WBT_ERR_UNKNOWN_PORT,                   
					WBT_ERR_TRANSPORT_NOT_FOUND,            
					WBT_ERR_PPP_START_FAILED,               
					WBT_ERR_RAS_NOT_LOADED,                 
					WBT_ERR_RAS_CONNECTION_SETUP_FAILED,    
					WBT_ERR_NO_MODEM_FOUND,                 
					WBT_ERR_LANACCESS_START_FAILED,         
					WBT_ERR_NOT_ENOUGH_MEMORY,              // 
					WBT_ERR_BAD_SCN,                        // invalid scn for connection
					WBT_ERR_ALLOC_SCN,                      // unable to allocate SCN
					WBT_ERR_CREATE_SDP_RECORD,              // unable to create SDP record
					WBT_ERR_BAD_CONFIG,
					WBT_DIALING,                            // NOT an error, the stack is about to put up the dial dialog
					WBT_ERR_BOTH_DUN_LAP_UNSUPPORTED,       // simultaneous DUN & LAP not supported in this OS
					WBT_ERR_NO_AUDIO_PRESENT,               // BT Audio is not installed to start HSP or HAG
					WBT_ERR_COM_PORT_IN_USE,                // COM port used for connection is already in use

					/* COM server errors returned from GapStartInquiry() */
				#define WBT_ERR_START_INQUIRY_OFFSET 0x81000020
					WBT_ERR_BTM_BUSY = WBT_ERR_START_INQUIRY_OFFSET + 2, /* Device busy with another command  */
					WBT_ERR_BTM_NO_RESOURCES,               /* No resources to issue command     */
					WBT_ERR_BTM_MODE_UNSUPPORTED,           /* Request for 1 or more unsupported modes */
					WBT_ERR_BTM_ILLEGAL_VALUE,              /* Illegal parameter value           */
					WBT_ERR_BTM_WRONG_MODE,                 /* No device found  */
					WBT_ERR_BTM_LICENSE_ERROR,				/* BTW license unauthorized */

					/* Generic HCI errors passed to the application */
					WBT_ERR_GEN_HCI = 0x810000F0,

					WBT_ERR_AUTH_FAILURE,           // Authentication failed, redo pairing
					WBT_ERR_PAIRING_NOT_ALLOWED,    // Pairing is not allowed by peer device
					WBT_ERR_RESPONCE_TIMEOUT,       // Timeout occured during pairing
					WBT_ERR_PAGE_TIMEOUT,           // Device is not available
					WBT_ERR_NOT_SUPPPORTED,         // Pairing not supported
					WBT_ERR_REPEATED_ATTEMPTS,      // Repeated attempts

					/* FTP error codes returned from COM server */
					WBT_FTP_ERR_BASE = 0x81000100,

					WBT_FTP_ERR_BAD_ADDR,            /* bad BD_ADDR */
					WBT_FTP_ERR_HANDLE,              /* bad handle */
					WBT_FTP_ERR_NOT_UNIQUE_DEV,      /* specified device is not unique (i.e. multiple
													 ** matching entries
													 */
					WBT_FTP_ERR_NO_HANDLES,          /* reached session limit;  no handle available */
					WBT_FTP_ERR_BAD_STATE,           /* could not handle request in present state */
					WBT_FTP_ERR_EXISTS,              /* file exists */
					WBT_FTP_ERR_BAD_REQUEST,         /* invalid request */
					WBT_FTP_ERR_NOT_FOUND,           /* no such file */
					WBT_FTP_ERR_NO_SERVICE,          /* could not find the specified FTP server */
					WBT_FTP_ERR_DISCONNECT,          /* connection lost */
					WBT_FTP_ERR_READ,                /* read error */
					WBT_FTP_ERR_WRITE,               /* write error */
					WBT_FTP_ERR_MEM,                 /* could not allocate memory */
					WBT_FTP_ERR_OBEX_AUTH,           /* OBEX Authentication required */
					WBT_FTP_ERR_DENIED,              /* request could not be honored */
				//    WBT_FTP_ERR_BAD_LOCAL_FOLDER,    /* bad local folder */
					WBT_FTP_ERR_CONNECT,             /* error establishing connection */
					WBT_FTP_ERR_PERM,                /* incorrect permissions */
					WBT_FTP_ERR_SERVER_INTERNAL,     /* server error */
					WBT_FTP_ERR_NO_SERVER_SUPPORT,   /* server does not support the operation */
					WBT_FTP_ERR_NOT_INITIALIZED,     /* not initialized */
					WBT_FTP_ERR_PARAM,               /* bad parameter */
					WBT_FTP_ERR_PERMISSIONS,         /* incorrect file permissions */
					WBT_FTP_ERR_FS_RESOURCES,        /* out of file system resources (handles, disk space, etc) */
					WBT_FTP_ERR_SHARING,             /* file sharing violation */
					WBT_FTP_ERR_TIMEOUT,             /* timeout */
					WBT_FTP_ERR_PATH_TOO_BIG,

					/* OPP error codes returned from COM server */
					WBT_OPP_ERR_BASE = 0x81000120,

					WBT_OPP_ERR_BAD_ADDR,             /* bad BD_ADDR */
					WBT_OPP_ERR_HANDLE,               /* bad handle */
					WBT_OPP_ERR_NOT_UNIQUE,           /* specified device is not unique (i.e. multiple
													  ** matching entries
													  */
					WBT_OPP_ERR_NO_HANDLES,           /* reached session limit;  no handle available */
					WBT_OPP_ERR_BAD_STATE,            /* could not handle request in present state */
					WBT_OPP_ERR_EXISTS,               /* file exists */
					WBT_OPP_ERR_BAD_REQUEST,          /* invalid request */
					WBT_OPP_ERR_NOT_FOUND,            /* no such file */
					WBT_OPP_ERR_NO_SERVICE,           /* could not find the specified FTP server */
					WBT_OPP_ERR_DISCONNECT,           /* connection lost */
					WBT_OPP_ERR_READ,                 /* read error */
					WBT_OPP_ERR_WRITE,                /* write error */
					WBT_OPP_ERR_OBEX_AUTH,            /* OBEX Authentication required */
					WBT_OPP_ERR_DENIED,               /* request could not be honored */
					WBT_OPP_ERR_DATA_NOT_SUPPORTED,   /* server does not support the requested data */
					WBT_OPP_ERR_CONNECT,              /* error establishing connection */
					WBT_OPP_ERR_NOT_INITIALIZED,      /* not initialized */
					WBT_OPP_ERR_PARAM,                /* bad parameter */
					WBT_OPP_ERR_BAD_INBOX,            /* inbox is not valid */
					WBT_OPP_ERR_BAD_NAME,             /* bad name for object */
					WBT_OPP_ERR_PERMISSIONS,          /* prohibited by file permissions */
					WBT_OPP_ERR_SHARING,              /* file sharing violation */
					WBT_OPP_ERR_FS_RESOURCES,         /* out of file system resources (handles, disk space, etc) */
					WBT_OPP_ERR_NO_DATATYPES_ACCEPTED,/* No OPP datatypes are checked for acceptance in the cpanel */
					WBT_OPP_ERR_PIM,                  /* problem with PIM */
					WBT_OPP_ERR_PARSE,                /* problem parsing object */
					WBT_OPP_ERR_TIMEOUT,
					WBT_OPP_ERR_PATH_TOO_BIG,

					/* SYNC error codes returned from COM server */
					WBT_SYNC_ERR_BASE = 0x81000160,

					WBT_SYNC_ERR_NO_HANDLES,		   /* no handle available */
					WBT_SYNC_ERR_HANDLE,			   /* bad handle */
					WBT_SYNC_ERR_NOT_INITIALIZED,      /* not initialized */
					WBT_SYNC_ERR_OBJECT_NOT_FOUND,	   /* an object to be deleted or modified was not there */
					WBT_SYNC_ERR_ALREADY_STARTED,	   /* sync is already started */
					WBT_SYNC_ERR_OPENING_FILE,		   /* couldn't open a file */
					WBT_SYNC_ERR_SERVICE_UNAVAILABLE,  /* the IrMC server was not available */
					WBT_SYNC_ERR_OBEX,				   /* general obex error */
					WBT_SYNC_ERR_OBEX_CLOSED,		   /* the obex session was lost */
					WBT_SYNC_ERR_OBEX_ABORTED,		   /* the obex session was aborted */
					WBT_SYNC_ERR_BAD_OBEX_RESPONSE,	   /* there was a bad obex response to a request */
					WBT_SYNC_ERR_PIM_NOT_PRESENT,	   /* there is no PIM present */
					WBT_SYNC_ERR_ALREADY_SYNCHING,	   /* machine is already sychronizing */
				//    WBT_SYNC_ERR_SAVE_IN_PIM_DISABLED, /* "Save Objects in PIM" is not checked in the cpanel */
					WBT_SYNC_ERR_RETIRED1,              /* this code has been retired */
					WBT_SYNC_ERR_BAD_FOLDER,           /* work folder is not there & could not be created */
					WBT_SYNC_ERR_IRMC_SERVER,          /* IrMC Server error */
					WBT_SYNC_ERR_TIMEOUT,              /* timeout */
					WBT_SYNC_ERR_PIM,                  /* PIM caused an error */
					WBT_SYNC_ABORTED,                  /* the sync session was aborted */

					/* SDP service discovery error codes returned from COM server */
					WBT_SDP_ERR_BASE = 0x81000180,

					WBT_SDP_ERR_CONNECT_ERR,		    /* Could not connect to device */
					WBT_SDP_ERR_CONNECT_REJ,            /* Remote device rejected the connection */
					WBT_SDP_ERR_SECURITY,		        /* Security failed */
					WBT_SDP_ERR_BAD_RECORD,             /* Remote Service Record Error */

					/* PAN error codes */
					WBT_PAN_ERR_BASE = 0x81000190,
					WBT_PAN_LOCAL_NAP_EXISTS,           /* somebody already connected to us as a NAP, disconnect first */
					WBT_PAN_REMOTE_NAP_EXISTS,          /* we are already connected to NAP, disconnect first */
					WBT_PAN_LOCAL_GN_EXISTS,            /* somebody already connected to GN, can not connect to NAP */
					WBT_PAN_INVALID_REQ,                /* invalid request from app */
					WBT_PAN_WRONG_ROLE,                 /* PAN is in invalid role state */
					WBT_PAN_NAP_BOTH_SIDES,             /* NAP is setup on both sides */
				    
					/* General connection error codes */
					WBT_CONN_ERR_BASE = 0x810001A0,

					WBT_CONN_DISCONNECTED,               /* An established connection has disconnected */
					WBT_CONN_CONNECT_ERROR,              /* Could not connect to remote */
					WBT_CONN_SECURITY_ERROR,             /* Security error during connection */
					WBT_CONN_LOCAL_CLOSED,               /* Local application opened and closed the COM port */
					WBT_CONN_LOCAL_TIMEOUT,               /* Local connection has not been started within timeout */

					/* BIP error codes returned from COM server */
					WBT_BIP_ERR_BASE = 0x810001B0,

					WBT_BIP_ERR_NO_HANDLES,           /* reached session limit;  no handle available */
					WBT_BIP_ERR_HANDLE,               /* bad handle */
					WBT_BIP_ERR_NOT_INITIALIZED,      /* not initialized */
					WBT_BIP_ERR_PARAM,                /* bad parameter */

					/* Print error codes returned from COM server */
					WBT_PRINT_ERR_BASE = 0x810001C0,

					WBT_PRINT_ERR_NO_PRINTER_FOUND,   /* no printer found to serve */

					/* Audio on demand error codes returned from COM server to Tray */
					WBT_AUDIO_DEMAND_ERR_BASE = 0x810001D0,
					WBT_AUDIO_DEMAND_HEADSET_NOT_CONFIGURED,
					WBT_AUDIO_DEMAND_HEADSET_NOT_CONNECTED,
					WBT_AUDIO_DEMAND_HEADSET_FAILED_TO_CONNECT,
					WBT_HEADSET_CONNECT_PENDING,
					WBT_AUDIO_FEATURE_NOT_SUPPORTED,

					/* BPP error codes */
					WBT_BPP_ERR_BASE = 0x820001B0,

					WBT_BPP_ERR_NO_HANDLES,           /* reached session limit;  no handle available */
					WBT_BPP_ERR_HANDLE,               /* bad handle */
					WBT_BPP_ERR_NOT_INITIALIZED,      /* not initialized */
					WBT_BPP_ERR_PARAM,                /* bad parameter */

					/* Voice Recognition error/status codes */
					WBT_VOICE_RECO_ERR_BASE = 0x820001C0,
					WBT_VOICE_RECO_STATUS_STARTED,  /* Started Voice recognition on local connection successfully */
					WBT_VOICE_RECO_STATUS_FAILED,   /* Failed to start Voice recognition on local connection */
					WBT_VOICE_RECO_STATUS_STOPPED,  /* Stopped Voice recognition on local connection */
					WBT_VOICE_RECO_STATUS_DIAL_COMMAND,     /* Dail Command received */
					WBT_VOICE_RECO_STATUS_ONE,              /* User said one */
					WBT_VOICE_RECO_STATUS_TWO,              /* User said two */
					WBT_VOICE_RECO_STATUS_THREE,            /* User said three */
					WBT_VOICE_RECO_STATUS_FOUR,             /* User said four */
					WBT_VOICE_RECO_STATUS_FIVE,             /* User said five */
					WBT_VOICE_RECO_STATUS_SIX,              /* User said six */
					WBT_VOICE_RECO_STATUS_SEVEN,            /* User said seven */
					WBT_VOICE_RECO_STATUS_EIGHT,            /* User said eight */
					WBT_VOICE_RECO_STATUS_NINE,             /* User said nine */
					WBT_VOICE_RECO_STATUS_ZERO,             /* User said zero */    
					WBT_VOICE_RECO_STATUS_CALL_COMMAND,    /* Call Command received */    
					WBT_VOICE_RECO_STATUS_MOVE_PROGRESS,    /* Dial timer ticked one */
					WBT_VOICE_RECO_STATUS_DIAL_DONE        /* Dial number done */
				};


				/// <summary>
				/// Define return code for Headphone Client functions
				/// </summary>
				public enum class eHeadphoneReturnCode
				{
					/// <summary>Operation initiated without error.</summary>
					Success = CHeadphoneClient::SUCCESS,
					/// <summary>COM server could not be started.</summary>
					NoBtServer = CHeadphoneClient::NO_BT_SERVER,
					/// <summary>Attempt to connect before previous connection closed.</summary>
					AlreadyConnected = CHeadphoneClient::ALREADY_CONNECTED,
					/// <summary>Attempt to close unopened connection.</summary>
					NotConnected = CHeadphoneClient::NOT_CONNECTED,
					/// <summary>Local processor could not allocate memory for open.</summary>
					NotEnoughMemory = CHeadphoneClient::NOT_ENOUGH_MEMORY,
					/// <summary>One or more of function parameters are not valid</summary>
					InvalidParameter = CHeadphoneClient::INVALID_PARAMETER,
					/// <summary>Any condition other than those here.</summary>
					UnknownError = CHeadphoneClient::UNKNOWN_ERROR,
					/// <summary>Invalid license.</summary>
					LicenseError = CHeadphoneClient::LICENSE_ERROR,
					/// <summary>Device busy.</summary>
					DeviceBusy = CHeadphoneClient::DEVICE_BUSY,
					/// <summary>No SDP record found.</summary>
					ServiceNotFound = CHeadphoneClient::SERVICE_NOT_FOUND,
					/// <summary>Local device is disabled or not up.</summary>
					BtmWrongMode = CHeadphoneClient::BTM_WRONG_MODE
				};


				/// <summary>
				/// Define connection states for AV
				/// </summary>
				public enum class eHeadphoneStatus
				{
					/// <summary>Device is connected.</summary>
					Connected = CHeadphoneClient::HEADPHONE_CONNECTED,
					/// <summary>Connection closed by local device.</summary>
					LocalDisconnect = CHeadphoneClient::HEADPHONE_LOCAL_DISCONNECT,
					/// <summary>Connection closed by remote device.</summary>
					RemoteDisconnect = CHeadphoneClient::HEADPHONE_REMOTE_DISCONNECT,
					/// <summary>Device not authorized.</summary>
					DeviceNotAuthorized = CHeadphoneClient::HEADPHONE_DEVICE_NOT_AUTHORIZED,
					/// <summary>No audio stream found.</summary>
					NoStreamFound = CHeadphoneClient::HEADPHONE_NO_STREAM_FOUND,
					/// <summary>Remote device suspended the stream.</summary>
					RemoteSuspended = CHeadphoneClient::HEADPHONE_REMOTE_SUSPENDED,
					/// <summary>Incoming stream.</summary>
					IncomingStream = CHeadphoneClient::HEADPHONE_INCOMING_STREAM,
					/// <summary>Streaming data.</summary>
					Streaming = CHeadphoneClient::HEADPHONE_STREAMING,
					/// <summary>Streaming stopped.</summary>
					Stopped = CHeadphoneClient::HEADPHONE_STOPPED
				};
			}
		}
	}
}

#endif