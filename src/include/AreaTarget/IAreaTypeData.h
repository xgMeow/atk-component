#pragma once
#include "../IAtkObj.h"
#include "../IClassInfo.h"


///
/// 区域
///
class IATKOBJECT_API IAreaTypeData :public IClassInfo
{
public:
    IAreaTypeData(const IAreaTypeData&) = delete;
    IAreaTypeData& operator=(const IAreaTypeData&) = delete;

	IAreaTypeData();
	~IAreaTypeData();
};
