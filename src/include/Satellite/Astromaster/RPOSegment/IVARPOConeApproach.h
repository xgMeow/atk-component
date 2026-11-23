#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPOConeApproach;

///
/// RPOConeApproach
///
class IATKOBJECT_API IVARPOConeApproach : public IVAMCSRPOSegment
{
public:
    IVARPOConeApproach(const IVARPOConeApproach&) = delete;
    IVARPOConeApproach& operator=(const IVARPOConeApproach&) = delete;

	IVARPOConeApproach(CSatellite* pSate, CRPOConeApproach* pcRPOConeApproach, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPOConeApproach();
};

