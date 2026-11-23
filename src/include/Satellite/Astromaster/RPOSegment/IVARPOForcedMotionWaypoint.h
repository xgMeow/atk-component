#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPOForcedMotionWaypoint;

///
/// RPOForcedMotionWaypoint
///
class IATKOBJECT_API IVARPOForcedMotionWaypoint : public IVAMCSRPOSegment
{
public:
    IVARPOForcedMotionWaypoint(const IVARPOForcedMotionWaypoint&) = delete;
    IVARPOForcedMotionWaypoint& operator=(const IVARPOForcedMotionWaypoint&) = delete;

	IVARPOForcedMotionWaypoint(CSatellite* pSate, CRPOForcedMotionWaypoint* pcRPOForcedMotionWaypoint, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPOForcedMotionWaypoint();
};

