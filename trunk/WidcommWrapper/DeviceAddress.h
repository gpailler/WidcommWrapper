#ifndef _DeviceAddress
#define _DeviceAddress

#include <BtIfDefinitions.h>

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
				/// This class is used to manage Bluetooth device address.
				/// </summary>
				public ref class DeviceAddress
				{
				private:
					//Internal bluetooth address
					array<System::Byte>^ mAddress;


				internal:
					/// <summary>
					/// Convert an unmanaged Bluetooth address to managed Bluetooth address instance
					/// </summary>
					/// <param name="_address">Unamanaged 6-length array</param>
					/// <returns>A managed Bluetooth address instance</returns>
					static DeviceAddress^ ConvertFrom(::BD_ADDR _address)
					{
						//Marshal::Copy is 2-time faster than Marshal::PtrToStructure
						DeviceAddress^ deviceAddress = gcnew DeviceAddress();
						Marshal::Copy((IntPtr)_address, deviceAddress->Address, 0, BD_ADDR_LEN);
						return deviceAddress;
					}


				public:
					/// <summary>
					/// Default constructor
					/// </summary>
					DeviceAddress()
					{
						this->mAddress = gcnew array<System::Byte>(BD_ADDR_LEN);
					}


					/// <summary>
					/// Constructor from Bluetooth address array
					/// </summary>
					/// <param name="address">A 6-length array.</param>
					/// <exception cref="System::FormatException">Input argument has incorrect format. Device address must be a 6-length array</exception>
					/// <exception cref="System::ArgumentNullException">Input argument is null</exception>
					DeviceAddress(array<System::Byte>^ address)
					{
						if (address == nullptr)
						{
							throw gcnew System::ArgumentNullException("Argument can't be null");
						}

						if (address->Length != 6)
						{
							throw gcnew System::FormatException("Device address must be a 6-length array");
						}

						DeviceAddress();
						this->mAddress = address;
					}


					/// <summary>
					/// This property expose device address as 6-length array
					/// </summary>
					property array<System::Byte>^ Address
					{
						array<System::Byte>^ get()
						{
							return this->mAddress;
						}
					}


					/// <summary>
					/// This function return device address in human-readable format
					/// </summary>
					/// <returns>Device address as hexadecimal string like 00:11:22:33:44:55</returns>
					virtual System::String^ ToString() override
					{
						return String::Format("{0:X2}:{1:X2}:{2:X2}:{3:X2}:{4:X2}:{5:X2}",
							this->mAddress[0], this->mAddress[1], this->mAddress[2], this->mAddress[3], this->mAddress[4], this->mAddress[5]);
					}


					/// <summary>
					/// Equals method is overided
					/// </summary>
					/// <param name="obj">A DeviceAddress instance to compare to</param>
					/// <returns>true if Bluetooth addresses match, false otherwise</returns>
					/// <exception cref="System::FormatException">Input argument has incorrect format. Argument must be a 6-length array</exception>
					virtual bool Equals(System::Object^ obj) override
					{
						if (obj == nullptr)
							return false;

						DeviceAddress^ deviceAddress = safe_cast<DeviceAddress^>(obj);
						
						if(deviceAddress->Address->Length != BD_ADDR_LEN)
							return false;

						for (int i = 0; i < BD_ADDR_LEN; i++)
						{
							if (this->mAddress[i] != deviceAddress->Address[i])
								return false;
						}

						return true;
					}
					

					/// <summary>
					/// This function create a new DeviceAddress instance from bluetooth address string
					/// </summary>
					/// <param name="addressString">Device address in 00:11:22:33:44:55 format</param>
					/// <returns>A managed Bluetooth address instance</returns>
					/// <exception cref="System::FormatException">Input argument has incorrect format. Device address must match 00:11:22:33:44:55 format</exception>
					/// <exception cref="System::ArgumentNullException">Input argument is null</exception>
					static DeviceAddress^ ConvertFrom(System::String^ addressString)
					{
						if (addressString == nullptr)
						{
							throw gcnew System::ArgumentNullException("Argument can't be null");
						}


						//Check input and split
						array<System::String^>^ addressArrayString = addressString->Split(':');
						if (addressArrayString->Length != BD_ADDR_LEN)
						{
							throw gcnew System::FormatException("Device address must match 00:11:22:33:44:55 format");
						}


						array<System::Byte>^ addressArray = gcnew array<System::Byte>(BD_ADDR_LEN);
						try
						{
							for (int i = 0; i < BD_ADDR_LEN; i++)
							{
								//Convert to 16-base values
								addressArray[i] = System::Convert::ToByte(addressArrayString[i], 16);
							}
						}
						catch (System::Exception^)
						{
							throw gcnew System::FormatException("Device address must match 00:11:22:33:44:55 format");
						}


						return gcnew DeviceAddress(addressArray);
					}
				};
			}
		}
	}
}

#endif