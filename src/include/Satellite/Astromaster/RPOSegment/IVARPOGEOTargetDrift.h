#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPOGEOTargetDrift;

///
/// RPOGEOTargetDrift
///
class IATKOBJECT_API IVARPOGEOTargetDrift : public IVAMCSRPOSegment
{
public:
    IVARPOGEOTargetDrift(const IVARPOGEOTargetDrift&) = delete;
    IVARPOGEOTargetDrift& operator=(const IVARPOGEOTargetDrift&) = delete;

	IVARPOGEOTargetDrift(CSatellite* pSate, CRPOGEOTargetDrift* pcRPOGEOTargetDrift, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPOGEOTargetDrift();
};

