#pragma once
#include "../../../IAtkObj.h"
#include "../../../IClassInfo.h"

///
/// 坐标类型
///
class IATKOBJECT_API IVAElement :public IClassInfo
{
public:
    IVAElement(const IVAElement&) = delete;
    IVAElement& operator=(const IVAElement&) = delete;

	IVAElement();
	virtual ~IVAElement();

};
