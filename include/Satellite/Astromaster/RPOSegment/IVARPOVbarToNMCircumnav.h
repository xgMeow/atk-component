#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPOVbarToNMCircumnav;

///
/// RPOVbarToNMCircumnav
///
class IATKOBJECT_API IVARPOVbarToNMCircumnav : public IVAMCSRPOSegment
{
public:
    IVARPOVbarToNMCircumnav(const IVARPOVbarToNMCircumnav&) = delete;
    IVARPOVbarToNMCircumnav& operator=(const IVARPOVbarToNMCircumnav&) = delete;

	IVARPOVbarToNMCircumnav(CSatellite* pSate, CRPOVbarToNMCircumnav* pcRPOVbarToNMCircumnav, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPOVbarToNMCircumnav();
};

