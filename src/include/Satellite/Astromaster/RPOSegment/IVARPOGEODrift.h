#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPOGEODrift;

///
/// RPOGEODrift
///
class IATKOBJECT_API IVARPOGEODrift : public IVAMCSRPOSegment
{
public:
    IVARPOGEODrift(const IVARPOGEODrift&) = delete;
    IVARPOGEODrift& operator=(const IVARPOGEODrift&) = delete;

	IVARPOGEODrift(CSatellite* pSate, CRPOGEODrift* pcRPOGEODrift, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPOGEODrift();
};

