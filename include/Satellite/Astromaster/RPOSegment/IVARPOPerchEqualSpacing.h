#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPOPerchEqualSpacing;

///
/// RPOPerchEqualSpacing
///
class IATKOBJECT_API IVARPOPerchEqualSpacing : public IVAMCSRPOSegment
{
public:
    IVARPOPerchEqualSpacing(const IVARPOPerchEqualSpacing&) = delete;
    IVARPOPerchEqualSpacing& operator=(const IVARPOPerchEqualSpacing&) = delete;

	IVARPOPerchEqualSpacing(CSatellite* pSate, CRPOPerchEqualSpacing* pcRPOPerchEqualSpacing, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPOPerchEqualSpacing();
};

