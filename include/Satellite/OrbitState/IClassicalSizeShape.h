#pragma once
#include "../../IAtkObj.h"
#include "../../IClassInfo.h"
class CSatellite;

///
/// 轨道根数SizeShape
///
class IATKOBJECT_API IClassicalSizeShape :public IClassInfo
{
public:
    IClassicalSizeShape(const IClassicalSizeShape&) = delete;
    IClassicalSizeShape& operator=(const IClassicalSizeShape&) = delete;

	IClassicalSizeShape(CSatellite* pSate);
	virtual ~IClassicalSizeShape();

};
