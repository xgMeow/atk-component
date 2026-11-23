#pragma once
#include "../../IAtkObj.h"
#include "../../IClassInfo.h"

///
/// 发射点
///
class IATKOBJECT_API IVeLaunch :public IClassInfo
{
public:
    IVeLaunch(const IVeLaunch&) = delete;
    IVeLaunch& operator=(const IVeLaunch&) = delete;

	IVeLaunch();
	~IVeLaunch();
};
