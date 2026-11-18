#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPOSetDeltaV;

///
/// RPOSetDeltaV
///
class IATKOBJECT_API IVARPOSetDeltaV : public IVAMCSRPOSegment
{
public:
    IVARPOSetDeltaV(const IVARPOSetDeltaV&) = delete;
    IVARPOSetDeltaV& operator=(const IVARPOSetDeltaV&) = delete;

	IVARPOSetDeltaV(CSatellite* pSate, CRPOSetDeltaV* pcRPOSetDeltaV, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPOSetDeltaV();
};

