#pragma once
#include "../../IAtkObj.h"
#include "../../IClassInfo.h"
class CSatellite;

///
/// 太阳光压
///
class IATKOBJECT_API ISRPModelBase :public IClassInfo
{
public:
    ISRPModelBase(const ISRPModelBase&) = delete;
    ISRPModelBase& operator=(const ISRPModelBase&) = delete;

	ISRPModelBase(CSatellite* pSate);
	virtual ~ISRPModelBase();

};
