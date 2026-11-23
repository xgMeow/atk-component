#pragma once
#include "../../IAtkObj.h"
#include "../../IClassInfo.h"

///
/// 姿态
///
class IATKOBJECT_API IVeAttitude : public IClassInfo
{
public:
    IVeAttitude(const IVeAttitude&) = delete;
    IVeAttitude& operator=(const IVeAttitude&) = delete;

	IVeAttitude();
	virtual ~IVeAttitude();
};
