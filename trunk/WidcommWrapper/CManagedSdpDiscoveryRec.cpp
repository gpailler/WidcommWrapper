#include "CManagedSdpDiscoveryRec.h"

namespace CG
{
	namespace Wrappers
	{
		namespace Widcomm
		{
			CManagedSdpDiscoveryRec::CManagedSdpDiscoveryRec(::CSdpDiscoveryRec* _recs, int idx, array<CManagedSdpDiscoveryRec^>^ listRecs)
				: _mRecs(_recs), mIdx(idx), mListRecs(listRecs), mDisposed(false)
			{
			}


			CManagedSdpDiscoveryRec::~CManagedSdpDiscoveryRec()
			{
				mDisposed = true;
				this->!CManagedSdpDiscoveryRec();
			}


			CManagedSdpDiscoveryRec::!CManagedSdpDiscoveryRec()
			{
				mListRecs[mIdx] = nullptr;

				bool deleteNativeResource = true;
				for each(CManagedSdpDiscoveryRec^ rec in mListRecs)
				{
					if (rec != nullptr)
					{
						deleteNativeResource = false;
						break;
					}
				}

				if (deleteNativeResource)
				{
					delete[] _mRecs;
				}
			}


			System::String^ CManagedSdpDiscoveryRec::ServiceName::get()
			{
				if (mDisposed)
					throw gcnew ObjectDisposedException(this->GetType()->FullName);

				return gcnew System::String((&_mRecs[mIdx])->m_service_name);
			}


			Enums::eGuidServiceClass CManagedSdpDiscoveryRec::ServiceClassEnum::get()
			{
				if (mDisposed)
					throw gcnew ObjectDisposedException(this->GetType()->FullName);

				return Datatypes::ServiceClass::ToEnum((&_mRecs[mIdx])->m_service_guid);
			}


			System::Guid CManagedSdpDiscoveryRec::ServiceClassGuid::get()
			{
				if (mDisposed)
					throw gcnew ObjectDisposedException(this->GetType()->FullName);

				return Datatypes::ServiceClass::ToManagedGUID((&_mRecs[mIdx])->m_service_guid);
			}


			bool CManagedSdpDiscoveryRec::FindProtocolListEnum(Enums::eUuidProtocol uuid, [Out] SdpProtocolElem^% elem)
			{
				if (mDisposed)
					throw gcnew ObjectDisposedException(this->GetType()->FullName);

				::tSDP_PROTOCOL_ELEM* _elem = new ::tSDP_PROTOCOL_ELEM;
				bool ret = (&_mRecs[mIdx])->FindProtocolListElem((UINT16)uuid, _elem) != 0;

				if (ret)
				{
					elem = gcnew SdpProtocolElem();
					elem->mUuidProtocol = (Enums::eUuidProtocol)_elem->protocol_uuid;
					elem->mNumParams = _elem->num_params;
					for (int i = 0; i < SDP_MAX_PROTOCOL_PARAMS; i++)
						elem->mParams[i] = _elem->params[i];
				}
				else
				{
					elem = nullptr;
				}

				delete _elem;

				return ret;
			}


			bool CManagedSdpDiscoveryRec::FindAdditionalProtocolListElem(Enums::eUuidProtocol uuid, [Out] SdpProtocolElem^% elem)
			{
				if (mDisposed)
					throw gcnew ObjectDisposedException(this->GetType()->FullName);

				::tSDP_PROTOCOL_ELEM* _elem = new ::tSDP_PROTOCOL_ELEM;
				bool ret = (&_mRecs[mIdx])->FindAdditionalProtocolListElem((UINT16)uuid, _elem) != 0;

				if (ret)
				{
					elem = gcnew SdpProtocolElem();
					elem->mUuidProtocol = (Enums::eUuidProtocol)_elem->protocol_uuid;
					elem->mNumParams = _elem->num_params;
					for (int i = 0; i < SDP_MAX_PROTOCOL_PARAMS; i++)
						elem->mParams[i] = _elem->params[i];
				}
				else
				{
					elem = nullptr;
				}

				delete _elem;

				return ret;
			}


			bool CManagedSdpDiscoveryRec::FindProfileVersion(Enums::eGuidServiceClass guid, [Out] System::UInt16% version)
			{
				if (mDisposed)
					throw gcnew ObjectDisposedException(this->GetType()->FullName);

				UINT16 _version;
				bool ret = (&_mRecs[mIdx])->FindProfileVersion(&Datatypes::ServiceClass::ToNativeGUID(guid), &_version) != 0;
				version = _version;

				return ret;
			}


				
			bool CManagedSdpDiscoveryRec::FindRFCommScn([Out] System::UInt16% scn)
			{
				if (mDisposed)
					throw gcnew ObjectDisposedException(this->GetType()->FullName);

				UINT8 _val;
				bool ret = (&_mRecs[mIdx])->FindRFCommScn(&_val) != 0;
				scn = _val;

				return ret;
			}


			bool CManagedSdpDiscoveryRec::FindL2CapPsm([Out] System::UInt16% psm)
			{
				if (mDisposed)
					throw gcnew ObjectDisposedException(this->GetType()->FullName);

				UINT16 _val;
				bool ret = (&_mRecs[mIdx])->FindL2CapPsm(&_val) != 0;
				psm = _val;

				return ret;
			}


			bool CManagedSdpDiscoveryRec::FindAttribute(Enums::eAttributeId attributeId, [Out] cli::array<System::Object^>^% output)
			{
				::SDP_DISC_ATTTR_VAL* _elems = new ::SDP_DISC_ATTTR_VAL[10];

				bool ret = (&_mRecs[mIdx])->FindAttribute((::UINT16)attributeId, _elems) != 0;
				if (ret)
				{
					output = gcnew cli::array<System::Object^>(_elems->num_elem);

					for (int i = 0; i < _elems->num_elem; i++)
					{
						switch (_elems->elem[i].type)
						{
						case ATTR_TYPE_INT:
							if (_elems->elem[i].val.u64 != _elems->elem[i].val.u32)
								throw gcnew NotImplementedException();

							output[i] = _elems->elem[i].val.u32;
							break;

						case ATTR_TYPE_TWO_COMP:
							throw gcnew NotImplementedException();

							output[i] = _elems->elem[i].val.u32;
							break;

						case ATTR_TYPE_UUID:
							if (attributeId == Enums::eAttributeId::ProtocolDescList)
							{
								output[i] = (Enums::eUuidProtocol)_elems[i].elem->val.u32;
							}
							else
							{
								output[i] = (Enums::eUuidServiceClass)_elems[i].elem->val.u32;
							}
							break;

						case ATTR_TYPE_BOOL:
							output[i] = _elems[i].elem->val.b != 0;
							break;

						case ATTR_TYPE_ARRAY:
							output[i] = gcnew String((char*)_elems[i].elem->val.array);
							break;
						}
					}
				}
				else
				{
					output = nullptr;
				}

				return ret;
			}
		}
	}
}


