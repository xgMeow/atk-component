#pragma once
#include "../../IAtkObj.h"
#include "../../IClassInfo.h"

///
/// 轨道圈数定义经纬度
///
class IATKOBJECT_API IVeBreakAngle :public IClassInfo
{
public:
    IVeBreakAngle(const IVeBreakAngle&) = delete;
    IVeBreakAngle& operator=(const IVeBreakAngle&) = delete;

	IVeBreakAngle();
	virtual ~IVeBreakAngle();

};

