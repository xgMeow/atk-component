#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPONoncoplanarRendezvous;

///
/// RPONoncoplanarRendezvous
///
class IATKOBJECT_API IVARPONoncoplanarRendezvous : public IVAMCSRPOSegment
{
public:
    IVARPONoncoplanarRendezvous(const IVARPONoncoplanarRendezvous&) = delete;
    IVARPONoncoplanarRendezvous& operator=(const IVARPONoncoplanarRendezvous&) = delete;

	IVARPONoncoplanarRendezvous(CSatellite* pSate, CRPONoncoplanarRendezvous* pcRPONoncoplanarRendezvous, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPONoncoplanarRendezvous();
};

