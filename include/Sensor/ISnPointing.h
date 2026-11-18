#pragma once
#include "../IAtkObj.h"
#include "../IClassInfo.h"

///
/// 指向：基类
///
class IATKOBJECT_API ISnPointing :public IClassInfo
{
public:
    ISnPointing(const ISnPointing&) = delete;
    ISnPointing& operator=(const ISnPointing&) = delete;

	ISnPointing();
	virtual ~ISnPointing();
};

