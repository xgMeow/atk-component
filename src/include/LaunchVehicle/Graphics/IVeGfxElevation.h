#pragma once
#include "../../IAtkObj.h"
#include "../../IClassInfo.h"

///
/// 夹角
///
class IATKOBJECT_API IVeGfxElevation :public IClassInfo
{
public:
    IVeGfxElevation(const IVeGfxElevation&) = delete;
    IVeGfxElevation& operator=(const IVeGfxElevation&) = delete;

	IVeGfxElevation();
	virtual ~IVeGfxElevation();
};
