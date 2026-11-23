#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPOFastRendezvous;

///
/// RPOFastRendezvous
///
class IATKOBJECT_API IVARPOFastRendezvous : public IVAMCSRPOSegment
{
public:
    IVARPOFastRendezvous(const IVARPOFastRendezvous&) = delete;
    IVARPOFastRendezvous& operator=(const IVARPOFastRendezvous&) = delete;

	IVARPOFastRendezvous(CSatellite* pSate, CRPOFastRendezvous* pcRPOFastRendezvous, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPOFastRendezvous();
};

