#pragma once
#include "../IAtkObj.h"
#include "../IClassInfo.h"

///
/// 模式类型：基类
///
class IATKOBJECT_API ISnPattern :public IClassInfo
{
public:
    ISnPattern(const ISnPattern&) = delete;
    ISnPattern& operator=(const ISnPattern&) = delete;

	ISnPattern();
	virtual ~ISnPattern();
};

