#pragma once
#include "../IAtkObj.h"
#include "../IClassInfo.h"

///
/// 瞄准类型：基类
///
class IATKOBJECT_API ISnPtTrgtBsight :public IClassInfo
{
public:
    ISnPtTrgtBsight(const ISnPtTrgtBsight&) = delete;
    ISnPtTrgtBsight& operator=(const ISnPtTrgtBsight&) = delete;

	ISnPtTrgtBsight();
	virtual ~ISnPtTrgtBsight();
};

