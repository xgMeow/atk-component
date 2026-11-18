#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPOForcedMotionCircumnav;

///
/// RPOForcedMotionCircumna
///
class IATKOBJECT_API IVARPOForcedMotionCircumnav : public IVAMCSRPOSegment
{
public:
    IVARPOForcedMotionCircumnav(const IVARPOForcedMotionCircumnav&) = delete;
    IVARPOForcedMotionCircumnav& operator=(const IVARPOForcedMotionCircumnav&) = delete;

	IVARPOForcedMotionCircumnav(CSatellite* pSate, CRPOForcedMotionCircumnav* pcRPOForcedMotionCircumnav, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPOForcedMotionCircumnav();
};

