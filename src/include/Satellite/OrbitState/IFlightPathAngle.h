#pragma once
#include "../../IAtkObj.h"
#include "../../IClassInfo.h"

///
/// 轨道根数偏心率
///
class IATKOBJECT_API IFlightPathAngle :public IClassInfo
{
public:
    IFlightPathAngle(const IFlightPathAngle&) = delete;
    IFlightPathAngle& operator=(const IFlightPathAngle&) = delete;

	IFlightPathAngle();
	virtual ~IFlightPathAngle();

};
