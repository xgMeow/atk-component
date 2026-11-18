#pragma once
#include "../../IAtkObj.h"
#include "../../IClassInfo.h"
struct CGfxVehPass;

///
/// 二维轨迹基类
///
class IATKOBJECT_API IVeLeadTrailData :public IClassInfo
{
public:
    IVeLeadTrailData(const IVeLeadTrailData&) = delete;
    IVeLeadTrailData& operator=(const IVeLeadTrailData&) = delete;

	IVeLeadTrailData(CGfxVehPass* pCGfxVehPass);
	virtual ~IVeLeadTrailData();

private:

};

