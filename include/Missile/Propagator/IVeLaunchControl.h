#pragma once
#include "../../IAtkObj.h"
#include "../../IClassInfo.h"

///
/// 增量基类
///
class IATKOBJECT_API IVeLaunchControl :public IClassInfo
{
public:
    IVeLaunchControl(const IVeLaunchControl&) = delete;
    IVeLaunchControl& operator=(const IVeLaunchControl&) = delete;

	IVeLaunchControl();
	~IVeLaunchControl();
};
