#ifndef _DeviceClass
#define _DeviceClass

#include <BtIfDefinitions.h>
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
				/// This class is used to managed device classes informations.
				/// </summary>
				public ref class DeviceClass
				{
				private:
					Enums::eServiceClass mServiceClass;
					Enums::eMajorDeviceClass mMajorDeviceClass;
					Enums::eMinorDeviceClass mMinorDeviceClass;


					bool findMatchingMinorDeviceClass(System::String^ val)
					{
						//Function used in overrided ToString() method
						return ((Enums::eMinorDeviceClass)System::Enum::Parse(Enums::eMinorDeviceClass::typeid, val, false) == mMinorDeviceClass) ? true : false;
					}


				internal:
					/// <summary>
					/// Convert an unmanaged Bluetooth DeviceClass to managed Bluetooth DeviceClass
					/// </summary>
					/// <param name="_deviceClass">Unamanaged 3-length array</param>
					/// <returns>A managed DeviceClass instance</returns>
					static DeviceClass^ ConvertFrom(const ::DEV_CLASS _deviceClass)
					{
						return gcnew DeviceClass(
							safe_cast<Enums::eServiceClass>(_deviceClass[0]),
							safe_cast<Enums::eMajorDeviceClass>(_deviceClass[1] & MAJOR_DEV_CLASS_MASK),
							safe_cast<Enums::eMinorDeviceClass>(_deviceClass[2] & MINOR_DEV_CLASS_MASK)
							);
					}


					/// <summary>
					/// Convert a managed Bluetooth DeviceClass to unmanaged Bluetooth DeviceClass
					/// </summary>
					/// <param name="deviceClass">Managed DeviceClass</param>
					/// <param name="_deviceClass">Unamanaged 3-length array</param>
					/// <exception cref="System::ArgumentNullException">Argument is null</exception>
					static void ConvertTo(DeviceClass^ deviceClass, ::DEV_CLASS _deviceClass)
					{
						if (deviceClass == nullptr)
						{
							throw gcnew System::ArgumentNullException("deviceClass argument can't be null");
						}

						if (_deviceClass == NULL)
						{
							throw gcnew System::ArgumentNullException("_deviceClass argument can't be null");
						}

						//throw gcnew Exception("test");
						//MASK?
						_deviceClass[0] = (UINT8)deviceClass->ServiceClass;
						_deviceClass[1] = (UINT8)deviceClass->MajorDeviceClass;
						_deviceClass[2] = (UINT8)deviceClass->MinorDeviceClass;

						_deviceClass[0] = (UINT8)deviceClass->ServiceClass;
						_deviceClass[1] = (UINT8)deviceClass->MajorDeviceClass | MAJOR_DEV_CLASS_MASK;
						_deviceClass[2] = (UINT8)deviceClass->MinorDeviceClass | MINOR_DEV_CLASS_MASK;

					}


					DeviceClass(Enums::eServiceClass serviceClass, Enums::eMajorDeviceClass majorDeviceClass, Enums::eMinorDeviceClass minorDeviceClass)
						: mServiceClass(serviceClass),
						mMajorDeviceClass(majorDeviceClass),
						mMinorDeviceClass(minorDeviceClass)
					{
					}


				public:
					DeviceClass()
					{
					}

					/// <summary>
					/// Contains device service class(es)
					/// </summary>
					property Enums::eServiceClass ServiceClass
					{
						Enums::eServiceClass get()
						{
							 return this->mServiceClass;
						}
						void set(Enums::eServiceClass serviceClass)
						{
							this->mServiceClass = serviceClass;
						}
					}


					/// <summary>
					/// Contains device major class
					/// </summary>
					property Enums::eMajorDeviceClass MajorDeviceClass
					{
						Enums::eMajorDeviceClass get()
						{
							return this->mMajorDeviceClass;
						}
						void set(Enums::eMajorDeviceClass majorDeviceClass)
						{
							this->mMajorDeviceClass = majorDeviceClass;
						}
					}


					/// <summary>
					/// Contains device minor class depending device major class
					/// </summary>
					property Enums::eMinorDeviceClass MinorDeviceClass
					{
						Enums::eMinorDeviceClass get()
						{
							return this->mMinorDeviceClass;
						}
						void set(Enums::eMinorDeviceClass minorDeviceClass)
						{
							this->mMinorDeviceClass = minorDeviceClass;
						}
					}


					/// <summary>
					/// This function return device class infos in human-readable format
					/// </summary>
					/// <returns>Device class with ServiceClass, MajorDeviceClass and MinorDeviceClass</returns>
					virtual System::String^ ToString() override
					{
						//Better solution to display Enum names with same value?
						cli::array<String^>^ minorDeviceClassArray = System::Enum::GetNames(Enums::eMinorDeviceClass::typeid);
						cli::array<String^>^ matchingMinorDeviceClassArray = Array::FindAll(minorDeviceClassArray, gcnew Predicate<String^>(this, &DeviceClass::findMatchingMinorDeviceClass));

						return String::Format("Service class: {0}, MajorDeviceClass: {1}, MinorDeviceClass: {2}", this->mServiceClass, this->mMajorDeviceClass, System::String::Join(" or ", matchingMinorDeviceClassArray));
					}
				};
			}
		}
	}
}

#endif