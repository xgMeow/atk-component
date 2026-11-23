#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPOExitGEO;

///
/// RPOExitGEO
///
class IATKOBJECT_API IVARPOExitGEO : public IVAMCSRPOSegment
{
public:
    IVARPOExitGEO(const IVARPOExitGEO&) = delete;
    IVARPOExitGEO& operator=(const IVARPOExitGEO&) = delete;

	IVARPOExitGEO(CSatellite* pSate, CRPOExitGEO* pcRPOExitGEO, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPOExitGEO();
};

