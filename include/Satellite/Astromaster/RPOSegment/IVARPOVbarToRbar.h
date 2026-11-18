#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPOVbarToRbar;

///
/// RPOVbarToRbar
///
class IATKOBJECT_API IVARPOVbarToRbar : public IVAMCSRPOSegment
{
public:
    IVARPOVbarToRbar(const IVARPOVbarToRbar&) = delete;
    IVARPOVbarToRbar& operator=(const IVARPOVbarToRbar&) = delete;

	IVARPOVbarToRbar(CSatellite* pSate, CRPOVbarToRbar* pcRPOVbarToRbar, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPOVbarToRbar();
};

