#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPOFollowSunMotion;

///
/// RPOFollowSunMotion
///
class IATKOBJECT_API IVARPOFollowSunMotion : public IVAMCSRPOSegment
{
public:
    IVARPOFollowSunMotion(const IVARPOFollowSunMotion&) = delete;
    IVARPOFollowSunMotion& operator=(const IVARPOFollowSunMotion&) = delete;

	IVARPOFollowSunMotion(CSatellite* pSate, CRPOFollowSunMotion* pcRPOFollowSunMotion, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPOFollowSunMotion();
};

