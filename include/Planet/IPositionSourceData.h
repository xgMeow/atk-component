#pragma once
#include "../IAtkObj.h"
#include "../IClassInfo.h"


///
/// 行星位置资源类型基类
///
class IATKOBJECT_API IPositionSourceData :public IClassInfo
{
public:
    IPositionSourceData(const IPositionSourceData&) = delete;
    IPositionSourceData& operator=(const IPositionSourceData&) = delete;

	IPositionSourceData();
	virtual ~IPositionSourceData();
};

