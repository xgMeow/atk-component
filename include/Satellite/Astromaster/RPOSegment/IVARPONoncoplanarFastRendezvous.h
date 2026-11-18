#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPONoncoplanarFastRendezvous;

///
/// RPONoncoplanarFastRendezvous
///
class IATKOBJECT_API IVARPONoncoplanarFastRendezvous : public IVAMCSRPOSegment
{
public:
    IVARPONoncoplanarFastRendezvous(const IVARPONoncoplanarFastRendezvous&) = delete;
    IVARPONoncoplanarFastRendezvous& operator=(const IVARPONoncoplanarFastRendezvous&) = delete;

	IVARPONoncoplanarFastRendezvous(CSatellite* pSate, CRPONoncoplanarFastRendezvous* pcRPONoncoplanarFastRendezvous, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPONoncoplanarFastRendezvous();
};

