#pragma once
#include "../IVAMCSSegment.h"
class CSatellite;
class CMCSSegment;

///
/// 结束段
///
class IATKOBJECT_API IVAMCSEnd : public IVAMCSSegment
{
public:
    IVAMCSEnd(const IVAMCSEnd&) = delete;
    IVAMCSEnd& operator=(const IVAMCSEnd&) = delete;

	IVAMCSEnd(CSatellite* pSate, CMCSSegment* pSegment, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVAMCSEnd();

};
