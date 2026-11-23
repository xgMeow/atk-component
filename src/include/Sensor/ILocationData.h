#pragma once
#include "../IAtkObj.h"
#include "../IClassInfo.h"

///
/// 相对位置
///
class IATKOBJECT_API ILocationData :public IClassInfo
{
public:
    ILocationData(const ILocationData&) = delete;
    ILocationData& operator=(const ILocationData&) = delete;

	ILocationData();
	virtual ~ILocationData();
};

