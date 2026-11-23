#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPOGEORendezvousDrifting;

///
/// RPOGEORendezvousDrifting
///
class IATKOBJECT_API IVARPOGEORendezvousDrifting : public IVAMCSRPOSegment
{
public:
    IVARPOGEORendezvousDrifting(const IVARPOGEORendezvousDrifting&) = delete;
    IVARPOGEORendezvousDrifting& operator=(const IVARPOGEORendezvousDrifting&) = delete;

	IVARPOGEORendezvousDrifting(CSatellite* pSate, CRPOGEORendezvousDrifting* pcRPOGEORendezvousDrifting, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPOGEORendezvousDrifting();
};

