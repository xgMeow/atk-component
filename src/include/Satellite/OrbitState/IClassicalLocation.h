#pragma once
#include "../../IAtkObj.h"
#include "../../IClassInfo.h"
class CSatellite;

///
/// 轨道根数Location
///
class IATKOBJECT_API IClassicalLocation :public IClassInfo
{
public:
    IClassicalLocation(const IClassicalLocation&) = delete;
    IClassicalLocation& operator=(const IClassicalLocation&) = delete;

	IClassicalLocation(CSatellite* pSate);
	virtual ~IClassicalLocation();

};
