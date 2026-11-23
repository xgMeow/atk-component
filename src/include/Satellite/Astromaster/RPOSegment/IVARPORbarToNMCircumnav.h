#pragma once
#include "IVAMCSRPOSegment.h"
class CObjManage;
class CSatellite;
class CRPORbarToNMCircumnav;

///
/// RPORbarToNMCircumnav
///
class IATKOBJECT_API IVARPORbarToNMCircumnav : public IVAMCSRPOSegment
{
public:
    IVARPORbarToNMCircumnav(const IVARPORbarToNMCircumnav&) = delete;
    IVARPORbarToNMCircumnav& operator=(const IVARPORbarToNMCircumnav&) = delete;

	IVARPORbarToNMCircumnav(CSatellite* pSate, CRPORbarToNMCircumnav* pcRPORbarToNMCircumnav, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVARPORbarToNMCircumnav();
};

