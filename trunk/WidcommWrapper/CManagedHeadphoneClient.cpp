#include "CManagedHeadphoneClient.h"
#include <BtIfClasses.h>

namespace CG
{
	namespace Wrappers
	{
		namespace Widcomm 
		{
			CManagedHeadphoneClient::CManagedHeadphoneClient()
			{
				this->_mHeadphoneClient = new CNativeHeadphoneClient(this);
			}

			CManagedHeadphoneClient::~CManagedHeadphoneClient()
			{
				this->!CManagedHeadphoneClient();
			}

			CManagedHeadphoneClient::!CManagedHeadphoneClient()
			{
				delete this->_mHeadphoneClient;
			}

			Enums::eHeadphoneReturnCode CManagedHeadphoneClient::ConnectHeadphone(DeviceAddress^ deviceAddress, System::String^ serviceName)
			{
				if (serviceName == nullptr)
				{
					throw gcnew System::ArgumentNullException("serviceName can't be null");
				}

				pin_ptr<System::Byte> pDeviceAddress = &(deviceAddress->Address[0]);
				char* _pServiceName = (char*)Marshal::StringToHGlobalAnsi(serviceName).ToPointer();

				try
				{
					return (Enums::eHeadphoneReturnCode)this->_mHeadphoneClient->ConnectHeadphone(pDeviceAddress, _pServiceName);
				}
				finally
				{
					Marshal::FreeHGlobal((IntPtr)_pServiceName);
				}
			}

			Enums::eHeadphoneReturnCode CManagedHeadphoneClient::DisconnectHeadphone(long handle)
			{
				return (Enums::eHeadphoneReturnCode)this->_mHeadphoneClient->DisconnectHeadphone(handle);
			}

			void CManagedHeadphoneClient::OnHeadphoneStatusChanged(::BD_ADDR bda, ::DEV_CLASS dev_class, ::BD_NAME bd_name, long lHandle, long lStatus)
			{
				DeviceAddress^ deviceAddress = DeviceAddress::ConvertFrom(bda);
				System::String^ deviceName = gcnew System::String((const char*)bd_name);
				DeviceClass^ deviceClass = DeviceClass::ConvertFrom(dev_class);

				this->HeadphoneStatusChanged(deviceAddress, deviceClass, deviceName, lHandle, (Enums::eHeadphoneStatus)lStatus);
			}
		}
	}
}