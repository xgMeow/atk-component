#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPOGEOTargetAltDrift;

///
/// RPOTargetAltDrift
///
class IATKOBJECT_API IVARPOGEOTargetAltDrift : public IVAMCSRPOSegment
{
public:
    IVARPOGEOTargetAltDrift(const IVARPOGEOTargetAltDrift&) = delete;
    IVARPOGEOTargetAltDrift& operator=(const IVARPOGEOTargetAltDrift&) = delete;

	IVARPOGEOTargetAltDrift(CSatellite* pSate, CRPOGEOTargetAltDrift* pcRPOGEOTargetAltDrift, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPOGEOTargetAltDrift();
};

