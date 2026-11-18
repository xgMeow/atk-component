#pragma once
#include "../../IAtkObj.h"
#include "../../IClassInfo.h"

///
/// 落点
///
class IATKOBJECT_API IVeImpact :public IClassInfo
{
public:
    IVeImpact(const IVeImpact&) = delete;
    IVeImpact& operator=(const IVeImpact&) = delete;

	IVeImpact();
	~IVeImpact();
};
