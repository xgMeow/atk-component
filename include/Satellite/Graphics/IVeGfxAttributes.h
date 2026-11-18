#pragma once
#include "../../IAtkObj.h"
#include "../../IClassInfo.h"
struct CGfxVeh2D;

///
/// 二维显示属性
///
class IATKOBJECT_API IVeGfxAttributes :public IClassInfo
{
public:
    IVeGfxAttributes(const IVeGfxAttributes&) = delete;
    IVeGfxAttributes& operator=(const IVeGfxAttributes&) = delete;

	IVeGfxAttributes(CGfxVeh2D* pCGfxVeh2D);
	virtual ~IVeGfxAttributes();

private:

};
