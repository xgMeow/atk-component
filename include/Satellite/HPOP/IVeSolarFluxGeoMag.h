#pragma once
#include "../../IAtkObj.h"
#include "../../IClassInfo.h"

///
/// 太阳辐射通量/地磁指数
///
class IATKOBJECT_API IVeSolarFluxGeoMag :public IClassInfo
{
public:
    IVeSolarFluxGeoMag(const IVeSolarFluxGeoMag&) = delete;
    IVeSolarFluxGeoMag& operator=(const IVeSolarFluxGeoMag&) = delete;

	IVeSolarFluxGeoMag();
	virtual ~IVeSolarFluxGeoMag();

};
