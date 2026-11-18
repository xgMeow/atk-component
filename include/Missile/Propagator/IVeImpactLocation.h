#pragma once
#include "../../IAtkObj.h"
#include "../../IClassInfo.h"

///
/// 发射落点
///
class IATKOBJECT_API IVeImpactLocation :public IClassInfo
{
public:
    IVeImpactLocation(const IVeImpactLocation&) = delete;
    IVeImpactLocation& operator=(const IVeImpactLocation&) = delete;

	IVeImpactLocation();
	~IVeImpactLocation();
};
