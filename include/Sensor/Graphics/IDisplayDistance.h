#pragma once
#include "../../IAtkObj.h"
#include "../../IClassInfo.h"

///
/// 投影距离基类
///
class IATKOBJECT_API IDisplayDistance :public IClassInfo
{
public:
    IDisplayDistance(const IDisplayDistance&) = delete;
    IDisplayDistance& operator=(const IDisplayDistance&) = delete;

	IDisplayDistance();
	virtual ~IDisplayDistance();
};

