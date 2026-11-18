#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPOCorridorApproach;

///
/// RPOCorridorApproach
///
class IATKOBJECT_API IVARPOCorridorApproach : public IVAMCSRPOSegment
{
public:
    IVARPOCorridorApproach(const IVARPOCorridorApproach&) = delete;
    IVARPOCorridorApproach& operator=(const IVARPOCorridorApproach&) = delete;

	IVARPOCorridorApproach(CSatellite* pSate, CRPOCorridorApproach* pcRPOCorridorApproach, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPOCorridorApproach();
};

