#pragma once
#include "../../../IAtkObj.h"
#include "../../../IClassInfo.h"

///
/// 机动段姿态控制
///
class IATKOBJECT_API IVAAttitudeControl :public IClassInfo
{
public:
    IVAAttitudeControl(const IVAAttitudeControl&) = delete;
    IVAAttitudeControl& operator=(const IVAAttitudeControl&) = delete;

	IVAAttitudeControl();
	virtual ~IVAAttitudeControl();

};
