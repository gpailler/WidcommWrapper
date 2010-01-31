// This is the main DLL file.

#include "CManagedBtIf.h"

namespace CG
{
	namespace Wrappers
	{
		namespace Widcomm
		{
			CManagedBtIf::CManagedBtIf()
			{
				//Check if btwapi.dll is present
				if (!CManagedBtIf::IsDllPresent())
				{
					throw gcnew ApplicationException("Unable to load 'btwapi.dll' library. Unable to continue");
				}

				_mWidcommStack = new CNativeBtIf(this);
			}


			CManagedBtIf::~CManagedBtIf()
			{
				this->!CManagedBtIf();
			}

			
			CManagedBtIf::!CManagedBtIf()
			{
				delete (_mWidcommStack);
			}


			bool CManagedBtIf::IsDllPresent()
			{
				//Check if btwapi.dll is present
				HMODULE _h = LoadLibrary(L"btwapi.dll");
				if (_h == NULL)
				{
					return false;
				}
				else
				{
					FreeLibrary(_h);
					return true;
				}
			}


			bool CManagedBtIf::StartInquiry()
			{
				return _mWidcommStack->StartInquiry() != 0; // BOOL -> bool;
			}

			
			void CManagedBtIf::StopInquiry()
			{
				_mWidcommStack->StopInquiry();
			}


			void CManagedBtIf::OnDeviceResponded(::BD_ADDR _deviceAddress, ::DEV_CLASS _deviceClass, ::BD_NAME _deviceName, ::BOOL _connected)
			{
				//Retrieve device address
				DeviceAddress^ deviceAddress = DeviceAddress::ConvertFrom(_deviceAddress);

				//Retrieve device name
				System::String^ deviceName = gcnew System::String((const char*)_deviceName);

				//Retrieve device classes
				DeviceClass^ deviceClass = DeviceClass::ConvertFrom(_deviceClass);

				this->DeviceResponded(deviceAddress, deviceClass, deviceName, (_connected != 0));
			}


			void CManagedBtIf::OnInquiryComplete(::BOOL _success, ::SHORT _numResponses)
			{
				this->InquiryComplete((_success != 0), _numResponses);
			}


			bool CManagedBtIf::StartDiscovery(DeviceAddress^ deviceAddress, Enums::eGuidServiceClass serviceGuid)
			{
				pin_ptr<System::Byte> pDeviceAddress = &(deviceAddress->Address[0]);

				if (serviceGuid == Enums::eGuidServiceClass::Undefined)
				{
					return _mWidcommStack->StartDiscovery(pDeviceAddress, NULL) != 0;
				}
				else
				{
					::GUID _nativeGuid = ServiceClass::ToNativeGUID(serviceGuid);
					return _mWidcommStack->StartDiscovery(pDeviceAddress, &_nativeGuid) != 0;
				}
			}


			void CManagedBtIf::OnDiscoveryComplete()
			{
				this->DiscoveryComplete();
			}


			void CManagedBtIf::OnDiscoveryComplete(::UINT16 _numRecs, ::LONG _resultCode)
			{
				this->DiscoveryCompleteWithInfos(_numRecs, (Enums::WBT_STATUS_CODE)_resultCode);
			}


			bool CManagedBtIf::SwitchRole(DeviceAddress^ deviceAddress, Enums::eRole newRole)
			{
				pin_ptr<System::Byte> pDeviceAddress = &(deviceAddress->Address[0]);
				return ::CBtIf::SwitchRole(pDeviceAddress, (::MASTER_SLAVE_ROLE)newRole) != 0;
			}


			Enums::eDiscoveryResult CManagedBtIf::GetLastDiscoveryResult(DeviceAddress^ deviceAddress, [Out] System::UInt16% numRecs)
			{
				pin_ptr<System::Byte> pDeviceAddress = &(deviceAddress->Address[0]);

				::UINT16 _numRecs;
				::CBtIf::DISCOVERY_RESULT _ret = _mWidcommStack->GetLastDiscoveryResult(pDeviceAddress, &_numRecs);
				numRecs = _numRecs;

				return (Enums::eDiscoveryResult)_ret;
			}
			
			
			int CManagedBtIf::ReadDiscoveryRecords(DeviceAddress^ deviceAddress, int maxRecords, [Out] array<CManagedSdpDiscoveryRec^>^% listRecords, Enums::eGuidServiceClass guidFilter)
			{
				pin_ptr<System::Byte> pDeviceAddress = &(deviceAddress->Address[0]);

				::CSdpDiscoveryRec* _recs = new ::CSdpDiscoveryRec[maxRecords];

				int ret; 
				if (guidFilter == Enums::eGuidServiceClass::Undefined)
				{
					ret = _mWidcommStack->ReadDiscoveryRecords(pDeviceAddress, maxRecords, _recs);
				}
				else
				{
					::GUID _nativeGuid = ServiceClass::ToNativeGUID(guidFilter);
					ret = _mWidcommStack->ReadDiscoveryRecords(pDeviceAddress, maxRecords, _recs, &_nativeGuid);
				}


				if (ret)
				{
					listRecords = gcnew array<CManagedSdpDiscoveryRec^>(ret);
					for (int i = 0; i < ret; i++)
					{
						listRecords[i] = gcnew CManagedSdpDiscoveryRec(_recs, i, listRecords);
					}
				}
				else
				{
					listRecords = nullptr;
				}

				//Delete is performed in managed CSdpDiscoveryRec class
				//delete[] recs;

				return ret;
			}


			Enums::eBondReturnCode CManagedBtIf::Bond(DeviceAddress^ deviceAddress, System::String^ pinCode)
			{
				pin_ptr<System::Byte> pDeviceAddress = &(deviceAddress->Address[0]);
				char* _pPinCode = (char*)Marshal::StringToHGlobalAnsi(pinCode).ToPointer();
				try
				{
					return (Enums::eBondReturnCode)_mWidcommStack->Bond(pDeviceAddress, _pPinCode);
				}
				finally
				{
					Marshal::FreeHGlobal((IntPtr)_pPinCode);
				}
			}



			bool CManagedBtIf::BondQuery(DeviceAddress^ deviceAddress)
			{
				pin_ptr<System::Byte> pDeviceAddress = &(deviceAddress->Address[0]);
				return _mWidcommStack->BondQuery(pDeviceAddress) != 0;
			}

			
			bool CManagedBtIf::UnBond(DeviceAddress^ deviceAddress)
			{
				pin_ptr<System::Byte> pDeviceAddress = &(deviceAddress->Address[0]);
				return _mWidcommStack->UnBond(pDeviceAddress) != 0;
			}


			bool CManagedBtIf::IsDeviceReady()
			{
				return _mWidcommStack->IsDeviceReady() != 0;
			}


			bool CManagedBtIf::IsStackServerUp()
			{
				return _mWidcommStack->IsStackServerUp() != 0;
			}


			void CManagedBtIf::StackStatusChange::add(CManagedBtIf::StackStatusChangeDelegate^ d)
			{
				if (this->mStackStatusChange == nullptr)
				{
					//Call IsDeviceReady() method to receive callback from native class. Maybe a bug
					this->IsDeviceReady();
				}

				this->mStackStatusChange += d;
			}

			void CManagedBtIf::StackStatusChange::remove(CManagedBtIf::StackStatusChangeDelegate^ d)
			{
				this->mStackStatusChange -= d;
			}

			void CManagedBtIf::StackStatusChange::raise(Enums::eStackStatus newStatus)
			{
				if (this->mStackStatusChange != nullptr)
					this->mStackStatusChange(newStatus);
			}


			void CManagedBtIf::OnStackStatusChange(::CBtIf::STACK_STATUS _newStatus)
			{
				StackStatusChange((Enums::eStackStatus)_newStatus);
			}


			Enums::WBT_STATUS_CODE CManagedBtIf::GetExtendedError()
			{
				return (Enums::WBT_STATUS_CODE)_mWidcommStack->GetExtendedError();
			}


			void CManagedBtIf::SetExtendedError(Enums::WBT_STATUS_CODE code)
			{
				_mWidcommStack->SetExtendedError((::WBtRc)code);
			}


			bool CManagedBtIf::GetLocalDeviceName([Out] System::String^% deviceName)
			{
				::BD_NAME _deviceName;
				bool ret = _mWidcommStack->GetLocalDeviceName(&_deviceName) != 0;

				deviceName = (ret) ? gcnew System::String((const char*)_deviceName) : nullptr;
				return ret;
			}


			Enums::eRemoteDeviceInfoReturnCode CManagedBtIf::GetRemoteDeviceInfo(DeviceClass^ deviceClassFilter, [Out] DeviceInfo^% deviceInfo)
			{
				::DEV_CLASS _deviceClassFilter;
				DeviceClass::ConvertTo(deviceClassFilter, _deviceClassFilter);

				::CBtIf::REM_DEV_INFO* _deviceInfo = new ::CBtIf::REM_DEV_INFO();
				Enums::eRemoteDeviceInfoReturnCode ret;
				
				ret = (Enums::eRemoteDeviceInfoReturnCode)_mWidcommStack->GetRemoteDeviceInfo(_deviceClassFilter, _deviceInfo);


				deviceInfo = (ret == Enums::eRemoteDeviceInfoReturnCode::Success) ? DeviceInfo::ConvertFrom(_deviceInfo) : nullptr;
				delete _deviceInfo;

				return ret;
			}


			Enums::eRemoteDeviceInfoReturnCode CManagedBtIf::GetNextRemoteDeviceInfo([Out] DeviceInfo^% deviceInfo)
			{
				::CBtIf::REM_DEV_INFO* _deviceInfo = new ::CBtIf::REM_DEV_INFO();
				Enums::eRemoteDeviceInfoReturnCode ret;

				ret = (Enums::eRemoteDeviceInfoReturnCode)_mWidcommStack->GetNextRemoteDeviceInfo(_deviceInfo);


				deviceInfo = (ret == Enums::eRemoteDeviceInfoReturnCode::Success) ? DeviceInfo::ConvertFrom(_deviceInfo) : nullptr;
				delete _deviceInfo;

				return ret;
			}


			bool CManagedBtIf::GetLocalDeviceVersionInfo([Out] DeviceVersionInfo^% deviceVersionInfo)
			{
				::CBtIf::DEV_VER_INFO* _deviceVersionInfo = new ::CBtIf::DEV_VER_INFO();
				bool ret = _mWidcommStack->GetLocalDeviceVersionInfo(_deviceVersionInfo) != 0;

				if (ret)
				{
					deviceVersionInfo = gcnew Datatypes::DeviceVersionInfo(
						DeviceAddress::ConvertFrom(_deviceVersionInfo->bd_addr),
						(Enums::eHCIVersion)_deviceVersionInfo->hci_version,
						_deviceVersionInfo->hci_revision,
						(Enums::eManufacturer)_deviceVersionInfo->manufacturer,
						_deviceVersionInfo->lmp_version,
						_deviceVersionInfo->lmp_sub_version);
				}
				else
				{
					deviceVersionInfo = nullptr;
				}

				delete _deviceVersionInfo;

				return ret;
			}

			bool CManagedBtIf::GetRemoteDeviceVersionInfo(DeviceAddress^ deviceAddress, [Out] DeviceVersionInfo^% deviceVersionInfo)
			{
				pin_ptr<System::Byte> pDeviceAddress = &(deviceAddress->Address[0]);

				::CBtIf::DEV_VER_INFO* _deviceVersionInfo = new ::CBtIf::DEV_VER_INFO();
				bool ret = _mWidcommStack->GetRemoteDeviceVersionInfo(pDeviceAddress, _deviceVersionInfo) != 0;

				if (ret)
				{
					deviceVersionInfo = gcnew Datatypes::DeviceVersionInfo(
						DeviceAddress::ConvertFrom(_deviceVersionInfo->bd_addr),
						(Enums::eHCIVersion)_deviceVersionInfo->hci_version,
						_deviceVersionInfo->hci_revision,
						(Enums::eManufacturer)_deviceVersionInfo->manufacturer,
						_deviceVersionInfo->lmp_version,
						_deviceVersionInfo->lmp_sub_version);
				}
				else
				{
					deviceVersionInfo = nullptr;
				}

				delete _deviceVersionInfo;

				return ret;
			}


			bool CManagedBtIf::GetDKVersionInfo([Out] System::String^% versionInfo)
			{
				BT_CHAR _versionInfo[MAX_PATH];
				bool ret = _mWidcommStack->GetDKVersionInfo(_versionInfo, MAX_PATH) != 0;

				versionInfo = (ret) ? gcnew System::String((const char*)_versionInfo) : nullptr;
				return ret;
			}


			bool CManagedBtIf::GetBTWVersionInfo([Out] System::String^% versionInfo)
			{
				BT_CHAR _versionInfo[MAX_PATH];
				bool ret = _mWidcommStack->GetBTWVersionInfo(_versionInfo, MAX_PATH) != 0;

				versionInfo = (ret) ? gcnew System::String((const char*)_versionInfo) : nullptr;
				return ret;
			}


			bool CManagedBtIf::GetLocalServiceName([Out] System::String^% serviceName)
			{
				BT_CHAR _serviceName[MAX_PATH];
				bool ret = _mWidcommStack->GetLocalServiceName(_serviceName, MAX_PATH) != 0;

				serviceName = (ret) ? gcnew System::String((const char*)_serviceName) : nullptr;
				return ret;
			}


			bool CManagedBtIf::GetNextLocalServiceName([Out] System::String^% serviceName)
			{
				BT_CHAR _serviceName[MAX_PATH];
				bool ret = _mWidcommStack->GetNextLocalServiceName(_serviceName, MAX_PATH) != 0;

				serviceName = (ret) ? gcnew System::String((const char*)_serviceName) : nullptr;
				return ret;
			}

			
			bool CManagedBtIf::Add_Printer(System::String^ portName, DeviceAddress^ deviceAddress)
			{
				pin_ptr<System::Byte> pDeviceAddress = &(deviceAddress->Address[0]);

				char* _pPortName = (char*)Marshal::StringToHGlobalAnsi(portName).ToPointer();
				try
				{
					return _mWidcommStack->Add_Printer(_pPortName, pDeviceAddress) != 0;
				}
				finally
				{
					Marshal::FreeHGlobal((IntPtr)_pPortName);
				}
			}


			bool CManagedBtIf::Remove_Printer(DeviceAddress^ deviceAddress)
			{
				pin_ptr<System::Byte> pDeviceAddress = &(deviceAddress->Address[0]);
				bool ret = _mWidcommStack->Remove_Printer(pDeviceAddress) != 0;

				return ret;
			}


			bool CManagedBtIf::CreateCOMPortAssociation(DeviceAddress^ deviceAddress, Enums::eGuidServiceClass serviceGuid, System::String^ serviceName, System::UInt16 mtu, Enums::eSecurityId securityId, Enums::eSecurityLevel securityLevel, Enums::eUuidServiceClass uuidService, [Out] System::UInt16% comPort)
			{
				bool ret = false;

				pin_ptr<System::Byte> pDeviceAddress = &(deviceAddress->Address[0]);
				char* _pServiceName = (char*)Marshal::StringToHGlobalAnsi(serviceName).ToPointer();
				::GUID _nativeGuid = ServiceClass::ToNativeGUID(serviceGuid);
				USHORT _comPort = 0;
				
				mtu = (mtu == 0) ? 660 : mtu;

				try
				{
					ret = _mWidcommStack->CreateCOMPortAssociation(pDeviceAddress, &_nativeGuid, _pServiceName, mtu, (::BYTE)securityId, (::BYTE)securityLevel, (::USHORT)uuidService, &_comPort) != 0;
				}
				finally
				{
					Marshal::FreeHGlobal((IntPtr)_pServiceName);
				}

				comPort = (ret) ? _comPort : 0;
				return ret;
			}


			bool CManagedBtIf::RemoveCOMPortAssociation(System::UInt16 comPort)
			{
				return _mWidcommStack->RemoveCOMPortAssociation(comPort) != 0;
			}


			bool CManagedBtIf::ReadCOMPortAssociation([Out] array<RemoteAssociationElem^>^% listAssociations, System::UInt32 maxAssociations, [Out] System::UInt32% requiredMaxAssociations)
			{
				::tBT_REM_ASSOC_REC* _recs = new ::tBT_REM_ASSOC_REC[maxAssociations];
				::DWORD _requiredSize;

				bool ret = _mWidcommStack->ReadCOMPortAssociation(_recs, (::DWORD)maxAssociations, &_requiredSize) != 0;

				if (ret)
				{
					listAssociations = gcnew array<RemoteAssociationElem^>(maxAssociations);
					for (UInt32 i = 0; i < maxAssociations; i++)
					{
						listAssociations[i] = gcnew RemoteAssociationElem();
						listAssociations[i]->mDeviceAddress = Datatypes::DeviceAddress::ConvertFrom(_recs[i].bda);
						listAssociations[i]->mServiceGuid = Datatypes::ServiceClass::ToEnum(_recs[i].guid);
						listAssociations[i]->mServiceName = gcnew System::String(_recs[i].szServiceName);
						listAssociations[i]->mComPort = _recs[i].com_port;
					}
				}
				else
				{
					listAssociations = nullptr;
				}

				delete[] _recs;

				return ret;
			}
		}
	}
}
