#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPOTearDrop;

///
/// RPOTearDrop
///
class IATKOBJECT_API IVARPOTearDrop : public IVAMCSRPOSegment
{
public:
    IVARPOTearDrop(const IVARPOTearDrop&) = delete;
    IVARPOTearDrop& operator=(const IVARPOTearDrop&) = delete;

	IVARPOTearDrop(CSatellite* pSate, CRPOTearDrop* pcRPOTearDrop, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPOTearDrop();
};

