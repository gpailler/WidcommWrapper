#ifndef _CManagedBtIf
#define _CManagedBtIf


#define _AFXDLL
#include <afxwin.h>         // MFC core and standard components

#include "Enums.h"
#include "DeviceAddress.h"
#include "DeviceClass.h"
#include "DeviceInfo.h"
#include "DeviceVersionInfo.h"
#include "ServiceClass.h"

#include <BtIfDefinitions.h>
#include <BtIfClasses.h>
#include "CNativeBtIf.h"
#include "CManagedSdpDiscoveryRec.h"




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
			class CNativeBtIf;


			/// <summary>
			/// Provides interface level management functions, e.g., methods for doing inquiry and service discovery
			/// </summary>
			public ref class CManagedBtIf sealed
			{
				public:

					/// <summary>
					/// This public constructor instantiate native Widcomm BtIf class
					/// </summary>
					CManagedBtIf();


					/// <summary>
					/// This public destructor free unmanaged ressources
					/// </summary>
					~CManagedBtIf();


					/// <summary>
					/// This function check if btwapi.dll library is loadable on the system.
					/// If this function return false, the wrapper is inusable and exception will trow if you try to use it
					/// </summary>
					/// <returns><b>true</b> if wrapper is usable; <b>false</b> otherwise</returns>
					static bool IsDllPresent();

					

					/// <summary>
					/// This function starts the Bluetooth device inquiry procedure.
					/// </summary>
					/// <remarks>
					/// Because the Bluetooth stack is multiuser, an inquiry may not start immediately when this function is called; the stack may be busy with another operation.
					/// Until the application calls <see cref="StopInquiry()">StopInquiry()</see>, it will receive notification of all new devices found, even though the inquiry that found them was originated by a different process.
					/// While the inquiry is in progress, the <see cref="DeviceResponded">DeviceResponded</see> event is fired each time a device responds. 
					/// Typically, an application will use this function to accumulate a list of responding devices.
					/// The application may receive more than one <see cref="DeviceResponded">DeviceResponded</see> call for the same device and should discard duplicate BD addresses.
					/// </remarks>
					/// <returns><b>true</b> if the inquiry was started, <b>false</b> otherwise.</returns>
					bool StartInquiry();


					/// <summary>
					/// This function stops a running inquiry.
					/// </summary>
					void StopInquiry();


					/// <summary>
					/// This delegate is called for each inquiry response from each device in the Bluetooth neighborhood.
					/// </summary>
					/// <remarks>
					/// This delegate may trigger multiple times per inquiry – even multiple times per device – once for the address alone, and once for the address and the user-friendly name.
					/// </remarks>
					/// <param name="deviceAddress">The address of the responding device.</param>
					/// <param name="deviceClass">The class of the responding device.</param>
					/// <param name="deviceName">The user-friendly name of the responding device – <see cref="String::Empty">String.Empty</see> when the device is reporting only its address.</param>
					/// <param name="connected"><b>true</b> if the responding device is currently connected to the local device.</param>
					delegate void DeviceRespondedDelegate(DeviceAddress^ deviceAddress, DeviceClass^ deviceClass, System::String^ deviceName, bool connected);


					/// <summary>
					/// This event is fired for each inquiry response from each device in the Bluetooth neighborhood.
					/// </summary>
					/// <remarks>
					/// This event may trigger multiple times per inquiry – even multiple times per device – once for the address alone, and once for the address and the user-friendly name.
					/// </remarks>
					event DeviceRespondedDelegate^ DeviceResponded;


					/// <summary>
					/// This optional delegate may be called when all inquiries are complete, including obtaining the user-friendly names of the devices in the Bluetooth neighborhood.
					/// </summary>
					/// <param name="success"><b>true</b> if the inquiry is successful; otherwise, there is a device error.</param>
					/// <param name="num_responses">The number of devices responding to the inquiry.</param>
					delegate void InquiryCompleteDelegate(bool success, short numResponses);


					/// <summary>
					/// This optional event may be called when all inquiries are complete, including obtaining the user-friendly names of the devices in the Bluetooth neighborhood.
					/// </summary>
					event InquiryCompleteDelegate^ InquiryComplete;


					/// <summary>
					/// This function requests a service discovery for a specific device. When the discovery is complete, the events <see cref="DiscoveryComplete">DiscoveryComplete</see> and <see cref="DiscoveryCompleteWithInfos">DiscoveryCompleteWithInfos</see> are fired.
					/// </summary>
					/// <remarks>
					/// In BTW, the discovery database is cumulative. It contains the results of all this application's previous discoveries. It also contains the discovery results of any other applications that are running or that have run.
					/// Discovery results for a device are not removed until the device fails to respond to an inquiry.
					/// An application can minimize the chance of unwanted discovery results by specifying a specific <see cref="Guid">Guid</see> from <see cref="ServiceClass">Guid_ServClass</see> when calling <see cref="StartDiscovery()">StartDiscovery()</see>. 
					/// </remarks>
					/// <param name="deviceAddress">The Bluetooth device address of the device on which the service discovery is to be performed.</param>
					/// <param name="serviceGuid">
					/// The <see cref="Guid">Guid</see> from <see cref="ServiceClass">Guid_ServClass</see> of the service being looked for. If this parameter is <see cref="Guid::Empty">Guid.Empty</see> or <see cref="ServiceClass">Guid_ServClass.guid_SERVCLASS_NULL</see>, all public browseable services for the device will be reported.
					/// Standard <see cref="Guid">Guid</see> values are available in <see cref="ServiceClass">Guid_ServClass</see>Guid_ServClass class.
					/// </param>
					/// <returns><b>true</b> if discovery started. <b>false</b>, otherwise.</returns>
					bool StartDiscovery(DeviceAddress^ deviceAddress, Enums::eGuidServiceClass serviceGuid);


					/// <summary>
					/// This delegate is called when discovery is complete. The application can then call <see cref="ReadDiscoveryRecords">ReadDiscoveryRecords</see> to retrieve the records found.
					/// <seealso cref="DiscoveryCompleteWithInfosDelegate"/>
					/// </summary>
					/// <remarks>
					/// In BTW the discovery database is cumulative. It contains the results of all this application’s previous discoveries. It also contains the discovery results of any other applications that are running or that have run.
					/// Discovery results for a device are not removed until the device fails to respond to an inquiry.
					/// An application can minimize the chance of unwanted discovery results by specifying a specific <see cref="Guid">Guid</see> from <see cref="ServiceClass">Guid_ServClass</see> when calling <see cref="StartDiscovery()">StartDiscovery()</see>.
					/// </remarks>
					delegate void DiscoveryCompleteDelegate();


					/// <summary>
					/// This event is fired when discovery is complete. The application can then call <see cref="ReadDiscoveryRecords">ReadDiscoveryRecords</see> to retrieve the records found.
					/// <seealso cref="DiscoveryCompleteWithInfos"/>
					/// </summary>
					event DiscoveryCompleteDelegate^ DiscoveryComplete;


					/// <summary>
					/// This delegate is called when discovery is complete. The application can then call <see cref="ReadDiscoveryRecords">ReadDiscoveryRecords</see> to retrieve the records found.
					/// <seealso cref="DiscoveryCompleteDelegate"/>
					/// </summary>
					/// <remarks>
					/// In BTW the discovery database is cumulative. It contains the results of all this application’s previous discoveries. It also contains the discovery results of any other applications that are running or that have run.
					/// Discovery results for a device are not removed until the device fails to respond to an inquiry.
					/// An application can minimize the chance of unwanted discovery results by specifying a specific <see cref="Guid">Guid</see> from <see cref="ServiceClass">Guid_ServClass</see> when calling <see cref="StartDiscovery()">StartDiscovery()</see>.
					/// </remarks>
					/// <param name="numRecs">The number of services discovered.</param>
					/// <param name="resultCode">Result code for the discovery operation: <see cref="Enums::WBT_STATUS_CODE">WBT_SUCCESS</see> if discovery completed, else one of the error codes in <see cref="Enums::WBT_STATUS_CODE">WBT_STATUS_CODE</see>.</param>
					delegate void DiscoveryCompleteWithInfosDelegate(short numRecs, Enums::WBT_STATUS_CODE resultCode);


					/// <summary>
					/// This event is fired when discovery is complete. The application can then call <see cref="ReadDiscoveryRecords">ReadDiscoveryRecords</see> to retrieve the records found.
					/// <seealso cref="DiscoveryComplete"/>
					/// </summary>
					event DiscoveryCompleteWithInfosDelegate^ DiscoveryCompleteWithInfos;


					/// <summary>
					/// An application uses this method to request that the device switch role to Master or Slave. If the application wants to accept multiple simultaneous connections, it must execute this command to request that the device switch role to Master.
					/// </summary>
					/// <remarks>
					/// For example, if a service must support multiple L2CAP connections, the server starts by allocating a PSM using an L2CapIf object. Then if <i>n</i> concurrent connections are required, the server instantiates <i>n</i> L2Cap connection objects, and calls the Listen() function for each. These objects may share a PSM value. Now the server is prepared to receive connections from <i>n</i> clients.
					/// The <see cref="SwitchRole()">SwitchRole()</see> function is required when the client connections start arriving.
					/// When the first client successfully connects with the server, the Bluetooth stack automatically puts the server into Bluetooth slave mode. The connection is fine; but in slave mode the server can no longer respond to service discovery requests from other clients. So the server must call <see cref="SwitchRole()">SwitchRole()</see> to restore the server to Bluetooth master mode. The connection is not disturbed; but the server can now accept additional connections.
					///
					/// Each time a client connection request is accepted, the server must call <see cref="SwitchRole()">SwitchRole()</see>.
					/// </remarks>
					/// <param name="deviceAddress">The BD Address of the remote device associated with the connection to be switched.</param>
					/// <param name="newRole">The role to which the device should switch. Valid values are in <see cref="Enums::eRole">MASTER_SLAVE_ROLE</see> enum.</param>
					/// <returns><b>true</b> is successful.</returns>
					static bool SwitchRole(DeviceAddress^ deviceAddress, Enums::eRole newRole);


					/// <summary>
					/// The application can use this method after notification from the <see cref="DiscoveryComplete">DiscoveryComplete</see> delegate to find out the discovery results.
					/// </summary>
					/// <param name="deviceAddress">The BD Address of the device for which the service discovery has been performed.</param>
					/// <param name="numRecs">Variable to receive the number of service records obtained during the service discovery.</param>
					/// <returns>One value of the <see cref="Enums::eDiscoveryResult">DISCOVERY_RESULT</see> enum.</returns>
					Enums::eDiscoveryResult GetLastDiscoveryResult(DeviceAddress^ deviceAddress, [Out] System::UInt16% numRecs);


					/// <summary>
					/// This function is called when discovery is complete to retrieve the records received from the remote device.
					/// </summary>
					/// <remarks>
					/// In BTW the discovery database is cumulative. It contains the results of all previous discoveries of this application. It also contains the discovery results of any other applications that are running or that have run.
					/// Discovery results for a device are not removed until the device fails to respond to an inquiry.
					/// An application can minimize the chance of unwanted discovery results by specifying a specific <see cref="Guid">Guid</see> from <see cref="ServiceClass">Guid_ServClass</see> when calling <see cref="StartDiscovery()">StartDiscovery()</see>.
					/// </remarks>
					/// <param name="deviceAddress">The BD address of the device for which records are to be read.</param>
					/// <param name="maxRecords">The maximum number of discovery records to read.</param>
					/// <param name="listRecords">The place to store the records. The list must have the capacity for <i>max_size</i> entries.</param>
					/// <param name="guidFilter">
					/// A <see cref="Guid">Guid</see> from <see cref="ServiceClass">Guid_ServClass</see>. Only record(s) that have a service class ID matching this <see cref="Guid">Guid</see> are returned (typically only one record will match).
					/// If this parameter is <see cref="Guid::Empty">Guid.Empty</see> or <see cref="ServiceClass">Guid_ServClass.guid_SERVCLASS_NULL</see>, all records are returnes
					/// </param>
					/// <returns>The number of discovery records read.</returns>
					int ReadDiscoveryRecords(DeviceAddress^ deviceAddress, int maxRecords, [Out] array<CManagedSdpDiscoveryRec^>^% listRecords, Enums::eGuidServiceClass guidFilter);


					/// <summary>
					/// This function initiates the bonding procedure with the specified device. This function will block for up to 1 minute while the security functions at the lower levels perform the bonding procedure.
					/// </summary>
					/// <remarks>
					/// The purpose of bonding is to create a relation between two Bluetooth devices based on a common link key (a bond). The link key is created and exchanged (pairing) during the bonding procedure and is expected to be stored by both Bluetooth devices to be used for future authentication.
					/// A temporary connection is set up by the stack server to authenticate the remote device. If the authentication is successful, the devices are bonded.
					/// Once bonded, future connections for services will automatically be authenticated by the stack server security logic, using the link key, without intervention by the application.
					/// </remarks>
					/// <param name="deviceAddress">The BD address of the device to bond with.</param>
					/// <param name="pinCode">The PIN code to use for the bonding. A code with the length >= PIN_CODE_LEN (= 16) is invalid</param>
					/// <returns>One value of the <see cref="Enums::eBondReturnCode">BOND_RETURN_CODE</see> enum.</returns>
					Enums::eBondReturnCode Bond(DeviceAddress^ deviceAddress, System::String^ pinCode);
					
					
					/// <summary>
					/// This function tests if the indicated device is already paired with the local device.
					/// </summary>
					/// <param name="deviceAddress">The BD address of the device to bond with.</param>
					/// <returns><b>true</b> if the devices are already paired; <b>false</b>, otherwise.</returns>
					bool BondQuery(DeviceAddress^ deviceAddress);
					

					/// <summary>
					/// This function deletes the bond between the devices.
					/// </summary>
					/// <param name="deviceAddress">The BD address of the device to delete the bond with.</param>
					/// <returns><b>true</b> if the devices are now unbonded; <b>false</b>, otherwise.</returns>
					bool UnBond(DeviceAddress^ deviceAddress);
					

					/// <summary>
					/// This function verifies that the application is connected to the stack server, and that the stack server and Bluetooth device are ready to accept commands.
					/// </summary>
					/// <returns><b>true</b> if the device is ready; <b>false</b>, otherwise.</returns>
					bool IsDeviceReady();


					/// <summary>
					/// This function checks to see if the Bluetooth stack server is up.
					/// </summary>
					/// <returns><b>true</b>, if the stack is up; <b>false</b>, otherwise.</returns>
					bool IsStackServerUp();


					/// <summary>
					/// This event is used to indicate that the status of the stack server has changed. Applications may provide a derived method to process the status change notice.
					/// </summary>
					/// <param name="new_status">Result code from <see cref="Enums::eStackStatus">eStackStatus</see> enum.</param>
					delegate void StackStatusChangeDelegate(Enums::eStackStatus newStatus);

					
					/// <summary>
					/// This event is used to indicate that the status of the stack server has changed. Applications may provide a derived method to process the status change notice.
					/// </summary>
					event StackStatusChangeDelegate^ StackStatusChange
					{
					public:
						void add(StackStatusChangeDelegate^ d);
						void remove(StackStatusChangeDelegate^ d);
					private:
						void raise(Enums::eStackStatus new_status);
					}


					/// <summary>
					/// This function returns the object’s last-error code. The last-error code is maintained on a per-object basis. Multiple objects do not overwrite each other's last-error code.
					/// </summary>
					/// <remarks>
					/// This function is intended for obtaining extended error information when the SDK return/result codes are not sufficient. This is useful when the UNKNOWN_RETURN_ERROR code is returned from an SDK API function, or the UNKNOWN_RESULT_ERROR code is returned in an SDK callback function.
					/// 
					/// To retrieve an extended error code of a method of this class in the case where the method has failed, call GetExtendedError ( ) directly after this method has been called. GetExtendedError ( ) can be called in callback functions of this class as well.
					/// </remarks>
					/// <returns>One of the error codes in <see cref="Enums::WBT_STATUS_CODE">WBT_STATUS_CODE</see>.</returns>
					Enums::WBT_STATUS_CODE GetExtendedError();


					/// <summary>
					/// This function sets the last-error code for the object of this class. SetExtendedError() is intended to localize the place where exactly an error occurs in the code. It can be called to reset the last-error code for an object of this class to WBT_SUCCESS before any other class method is called. After a class method has been called, GetExtendedError ( ) can be invoked to read the error information. If GetExtendedError ( ) reports WBT_SUCCESS, then the error occurs somewhere else in the p rogram.
					/// </summary>
					/// <remarks>
					/// The last-error code is kept in a local variable of the object so that multiple objects of this class do not overwrite each other's values.
					/// </remarks>
					/// <param name="code">One of the error codes in <see cref="Enums::WBT_STATUS_CODE">WBT_STATUS_CODE</see>.</param>
					void SetExtendedError(Enums::WBT_STATUS_CODE code);


					/// <summary>
					/// This function retrieves the local device name to the caller’s buffer. The name is obtained from the Host Computer Interface the first time this function is called. Subsequent calls retrieve the name from an internal buffer.
					/// </summary>
					/// <param name="deviceName">The name of the device.</param>
					/// <returns><b>true</b> if the name was successfully retrieved; <b>false</b>, otherwise.</returns>
					bool GetLocalDeviceName([Out] System::String^% deviceName);


					/// <summary>
					/// This function queries the registry for information relating to previously discovered devices. You will have to call GetNextRemoteDeviceInfo ( ) to get next device info.
					/// </summary>
					/// <param name="deviceClassFilter">A DeviceClass class parameter. It determines which device classes are to be returned. ServiceClass is not used</param>
					/// <param name="deviceInfo">A DeviceInfo class where the remote device info is to be placed.</param>
					/// <returns>Return code</returns>
					Enums::eRemoteDeviceInfoReturnCode GetRemoteDeviceInfo(DeviceClass^ deviceClassFilter, [Out] DeviceInfo^% deviceInfo);


					/// <summary>
					/// This is called after calling GetRemoteDeviceInfo ( ) to read the next device in the registry.
					/// </summary>
					/// <param name="deviceInfo">A DeviceInfo class where the remote device info is to be placed.</param>
					/// <returns>Return code</returns>
					Enums::eRemoteDeviceInfoReturnCode GetNextRemoteDeviceInfo([Out] DeviceInfo^% deviceInfo);


					/// <summary>
					/// This function reads the values for the version information for the local Bluetooth device.
					/// </summary>
					/// <param name="deviceVersionInfo">A DeviceVersionInfo class where the infos are to be placed.</param>
					/// <returns>TRUE, if the information is returned; FALSE, otherwise.</returns>
					bool GetLocalDeviceVersionInfo([Out] DeviceVersionInfo^% deviceVersionInfo);


					/// <summary>
					/// This function will read the values for the version information of the remote Bluetooth device.
					/// </summary>
					/// <remarks>
					/// The connection has to be made before calling this function.
					/// </remarks>
					/// <param name="deviceAddress">The Bluetooth address of the remote device.</param>
					/// <param name="deviceVersionInfo">A DeviceVersionInfo class where the infos are to be placed.</param>
					/// <returns>TRUE, if the information is returned; FALSE, otherwise.</returns>
					bool GetRemoteDeviceVersionInfo(DeviceAddress^ deviceAddress, [Out] DeviceVersionInfo^% deviceVersionInfo);


					/// <summary>
					/// This method is used to get SDK version information.
					/// </summary>
					/// <param name="versionInfo">The version string.</param>
					/// <returns>FALSE – cannot get version info. TRUE – version info returned.</returns>
					bool GetDKVersionInfo([Out] System::String^% versionInfo);


					/// <summary>
					/// This method is used to get BTW version information.
					/// </summary>
					/// <param name="versionInfo">The version string.</param>
					/// <returns>FALSE – cannot get version info. TRUE – version info returned.</returns>
					bool GetBTWVersionInfo([Out] System::String^% versionInfo);


					/// <summary>
					/// This function is used to query to the local Bluetooth Stack for registered services. Call GetNextLocalSerivceName ( ) to get the  next re gistered service
					/// </summary>
					/// <remarks>
					/// This only returns native stack service records, not records created from SDK applications
					/// </remarks>
					/// <param name="serviceName">The local service name.</param>
					/// <returns>TRUE, if successful; FALSE, otherwise.</returns>
					bool GetLocalServiceName([Out] System::String^% serviceName);


					/// <summary>
					/// This function is used to get the next registered service. GetLocalServiceName ( ) must be called before calling this function
					/// </summary>
					/// <param name="serviceName">The local service name.</param>
					/// <returns>TRUE, if successful; FALSE, otherwise.</returns>
					bool GetNextLocalServiceName([Out] System::String^% serviceName);


					/// <summary>
					/// This function creates the HCRP port for a Bluetooth printer device and installs the printer attached to it.
					/// </summary>
					/// <param name="portName">The HCRP port name to be created.</param>
					/// <param name="deviceAddress">Printer Bluetooth Address.</param>
					/// <returns>TRUE if successful; FALSE, otherwise.</returns>
					bool Add_Printer(System::String^ portName, DeviceAddress^ deviceAddress);


					/// <summary>
					/// This function removes all of the printers attached to this Bluetooth device.
					/// </summary>
					/// <param name="deviceAddress">Printer Bluetooth Address.</param>
					/// <returns>TRUE if successful; FALSE, otherwise.</returns>
					bool Remove_Printer(DeviceAddress^ deviceAddress);


					/// <summary>
					/// This function requests that an association between a COM port and a service on the remote device be created. This method 
					/// will find an unused COM port or will create a new COM port, then associate that COM port with the indicated service on the 
					/// indicated remote device. This association will cause the Bluetooth stack to automatically establish a connection to the 
					/// indicated service on the remote device whenever an application opens the associated COM port. This association will be in 
					/// effect for all users that log on to the PC where the association is created.
					/// </summary>
					/// <remarks>
					/// Associations should be created only for the connections that require Bluetooth search and RFCOMM connection 
					/// establishment. They cannot be used for the server type connections when a COM port is opened to accept incoming 
					/// connections.
					/// If authentication or encryption is required for the connection, or may be required by the peer device, Bluetooth Bonding 
					/// should be performed before association is done.
					/// After association is performed, every time an application opens the COM port, the Bluetooth stack will attempt to discover 
					/// the specified service on the device and establish the RFCOMM connection.
					/// </remarks>
					/// <param name="deviceAddress">The server's Bluetooth device address.</param>
					/// <param name="serviceGuid">GUID of the service. If Undefined is specified BTW will search for the Bluetooth Serial Port Profile (SerialPort) on the remote device.</param>
					/// <param name="serviceName">The service name from the discovery record obtained for the SPP server.</param>
					/// <param name="mtu">Transmission unit to be used in the RFCOMM session. If 0 is specified, value of 660 is used.</param>
					/// <param name="securityId">Security identifier used for the connection. Default value is SerialPort.</param>
					/// <param name="securityLevel">Defines security procedures required during the connection. The value is a bit-wise combination of: OutAuthenticate, OutEncrypt. OutEncrypt cannot be set alone; have to have OutAuthenticate set.</param>
					/// <param name="uuidService">UUID of the service to be connected. You can set SerialPort value as default.</param>
					/// <param name="comPort">COM port assigned. If the value is zero, no empty COM port is available. BTW limits maximum of 127 ports.</param>
					/// <returns>TRUE - everything is OK; FALSE - No COM port is available.</returns>
					bool CreateCOMPortAssociation(DeviceAddress^ deviceAddress, Enums::eGuidServiceClass serviceGuid, System::String^ serviceName, System::UInt16 mtu, Enums::eSecurityId securityId, Enums::eSecurityLevel securityLevel, Enums::eUuidServiceClass uuidService, [Out] System::UInt16% comPort);


					/// <summary>
					/// This function requests the the existing association between a COM port and a remote device be removed.
					/// </summary>
					/// <param name="comPort">COM port to be removed.</param>
					/// <returns>TRUE - everything is OK; FALSE - COM port could not be removed.</returns>
					bool RemoveCOMPortAssociation(System::UInt16 comPort);




			ref class RemoteAssociationElem
			{
			public:
				DeviceAddress^ mDeviceAddress;
				Enums::eGuidServiceClass mServiceGuid;
				System::String^ mServiceName;
				System::Int16 mComPort;
			};

				bool ReadCOMPortAssociation([Out] array<RemoteAssociationElem^>^% listAssociations, System::UInt32 maxAssociations, [Out] System::UInt32% requiredMaxAssociations);





				private:
					// Reference to native BtIf class
					CNativeBtIf* _mWidcommStack;

					//Free native wdStack resources
					!CManagedBtIf();

					StackStatusChangeDelegate^ mStackStatusChange;

				internal:
					//These functions are called by native stack
					void OnDeviceResponded(::BD_ADDR _deviceAddress, ::DEV_CLASS _deviceClass, ::BD_NAME _deviceName, ::BOOL _connected);
					void OnInquiryComplete(::BOOL _success, ::SHORT _numResponses);
					void OnDiscoveryComplete();
					void OnDiscoveryComplete(::UINT16 _numRecs, ::LONG _resultCode);
					void OnStackStatusChange(::CBtIf::STACK_STATUS _newStatus);
			};
		}
	}
}

#endif