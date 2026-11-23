#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPOGEOAltDrift;

///
/// RPOGEOAltDrift
///
class IATKOBJECT_API IVARPOGEOAltDrift : public IVAMCSRPOSegment
{
public:
    IVARPOGEOAltDrift(const IVARPOGEOAltDrift&) = delete;
    IVARPOGEOAltDrift& operator=(const IVARPOGEOAltDrift&) = delete;

	IVARPOGEOAltDrift(CSatellite* pSate, CRPOGEOAltDrift* pcRPOGEOAltDrift, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPOGEOAltDrift();
};

