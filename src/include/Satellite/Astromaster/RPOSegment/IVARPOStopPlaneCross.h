#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPOStopPlaneCross;

///
/// RPOStopPlaneCross
///
class IATKOBJECT_API IVARPOStopPlaneCross : public IVAMCSRPOSegment
{
public:
    IVARPOStopPlaneCross(const IVARPOStopPlaneCross&) = delete;
    IVARPOStopPlaneCross& operator=(const IVARPOStopPlaneCross&) = delete;

	IVARPOStopPlaneCross(CSatellite* pSate, CRPOStopPlaneCross* pcRPOStopPlaneCross, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPOStopPlaneCross();
};

