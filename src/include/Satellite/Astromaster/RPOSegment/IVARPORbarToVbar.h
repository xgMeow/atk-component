#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPORbarToVbar;

///
/// RPORbarToVbar
///
class IATKOBJECT_API IVARPORbarToVbar : public IVAMCSRPOSegment
{
public:
    IVARPORbarToVbar(const IVARPORbarToVbar&) = delete;
    IVARPORbarToVbar& operator=(const IVARPORbarToVbar&) = delete;

	IVARPORbarToVbar(CSatellite* pSate, CRPORbarToVbar* pcRPORbarToVbar, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPORbarToVbar();
};

