#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPOHop;

///
/// RPOHop
///
class IATKOBJECT_API IVARPOHop : public IVAMCSRPOSegment
{
public:
    IVARPOHop(const IVARPOHop&) = delete;
    IVARPOHop& operator=(const IVARPOHop&) = delete;

	IVARPOHop(CSatellite* pSate, CRPOHop* pcRPOHop, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPOHop();
};

