#pragma once
#include "../../IAtkObj.h"
#include "../../IClassInfo.h"
class CSatellite;

///
/// 力模型
///
class IATKOBJECT_API IVeHPOPDragModel :public IClassInfo
{
public:
    IVeHPOPDragModel(const IVeHPOPDragModel&) = delete;
    IVeHPOPDragModel& operator=(const IVeHPOPDragModel&) = delete;

	IVeHPOPDragModel(CSatellite* pSate);
	virtual ~IVeHPOPDragModel();

};
