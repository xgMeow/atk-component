#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPOHopAndStop;

///
/// RPOHopAndStop
///
class IATKOBJECT_API IVARPOHopAndStop : public IVAMCSRPOSegment
{
public:
    IVARPOHopAndStop(const IVARPOHopAndStop&) = delete;
    IVARPOHopAndStop& operator=(const IVARPOHopAndStop&) = delete;

	IVARPOHopAndStop(CSatellite* pSate, CRPOHopAndStop* pcRPOHopAndStop, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPOHopAndStop();
};

