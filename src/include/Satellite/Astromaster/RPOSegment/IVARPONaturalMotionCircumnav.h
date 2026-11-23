#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPONaturalMotionCircumnav;

///
/// RPONaturalMotionCircumnav
///
class IATKOBJECT_API IVARPONaturalMotionCircumnav : public IVAMCSRPOSegment
{
public:
    IVARPONaturalMotionCircumnav(const IVARPONaturalMotionCircumnav&) = delete;
    IVARPONaturalMotionCircumnav& operator=(const IVARPONaturalMotionCircumnav&) = delete;

	IVARPONaturalMotionCircumnav(CSatellite* pSate, CRPONaturalMotionCircumnav* pcRPONaturalMotionCircumnav, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPONaturalMotionCircumnav();
};

