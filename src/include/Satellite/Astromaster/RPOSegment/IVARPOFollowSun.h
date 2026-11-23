#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPOFollowSun;

///
/// RPOFollowSun
///
class IATKOBJECT_API IVARPOFollowSun : public IVAMCSRPOSegment
{
public:
    IVARPOFollowSun(const IVARPOFollowSun&) = delete;
    IVARPOFollowSun& operator=(const IVARPOFollowSun&) = delete;

	IVARPOFollowSun(CSatellite* pSate, CRPOFollowSun* pcRPOFollowSun, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPOFollowSun();
};

