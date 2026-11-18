#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPOCoast;

///
/// RPOCoast
///
class IATKOBJECT_API IVARPOCoast : public IVAMCSRPOSegment
{
public:
    IVARPOCoast(const IVARPOCoast&) = delete;
    IVARPOCoast& operator=(const IVARPOCoast&) = delete;

	IVARPOCoast(CSatellite* pSate, CRPOCoast* pcRPOCoast, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPOCoast();
};


