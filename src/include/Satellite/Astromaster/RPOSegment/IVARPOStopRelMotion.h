#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPOStopRelMotion;
///
/// RPOStopRelMotion
///
class IATKOBJECT_API IVARPOStopRelMotion : public IVAMCSRPOSegment
{
public:
    IVARPOStopRelMotion(const IVARPOStopRelMotion&) = delete;
    IVARPOStopRelMotion& operator=(const IVARPOStopRelMotion&) = delete;

	IVARPOStopRelMotion(CSatellite* pSate, CRPOStopRelMotion* pcRPOStopRelMotion, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPOStopRelMotion();
};

