#pragma once
#include "../../IAtkObj.h"
#include "../../IClassInfo.h"

///
/// 预报器球坐标设置
///
class IATKOBJECT_API IOrientationAscNode :public IClassInfo
{
public:
    IOrientationAscNode(const IOrientationAscNode&) = delete;
    IOrientationAscNode& operator=(const IOrientationAscNode&) = delete;

	IOrientationAscNode();
	virtual ~IOrientationAscNode();

};

