#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPOGEORendezvousNolead;

///
/// RPOGEORendezvousNolead
///
class IATKOBJECT_API IVARPOGEORendezvousNolead : public IVAMCSRPOSegment
{
public:
    IVARPOGEORendezvousNolead(const IVARPOGEORendezvousNolead&) = delete;
    IVARPOGEORendezvousNolead& operator=(const IVARPOGEORendezvousNolead&) = delete;

	IVARPOGEORendezvousNolead(CSatellite* pSate, CRPOGEORendezvousNolead* pcRPOGEORendezvousNolead, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPOGEORendezvousNolead();
};

