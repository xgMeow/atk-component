#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPONMCircumnavToRbar;

///
/// RPONMCircumnavToRbar
///
class IATKOBJECT_API IVARPONMCircumnavToRbar : public IVAMCSRPOSegment
{
public:
    IVARPONMCircumnavToRbar(const IVARPONMCircumnavToRbar&) = delete;
    IVARPONMCircumnavToRbar& operator=(const IVARPONMCircumnavToRbar&) = delete;

	IVARPONMCircumnavToRbar(CSatellite* pSate, CRPONMCircumnavToRbar* pcRPONMCircumnavToRbar, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPONMCircumnavToRbar();
};

