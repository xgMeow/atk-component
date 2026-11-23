#pragma once
#include "IVeSolarFluxGeoMag.h"
class CSatellite;

///
/// 太阳辐射通量/地磁指数设置
///
class IATKOBJECT_API IVeSolarFluxGeoMagEnterManually : public IVeSolarFluxGeoMag
{
public:
    IVeSolarFluxGeoMagEnterManually(const IVeSolarFluxGeoMagEnterManually&) = delete;
    IVeSolarFluxGeoMagEnterManually& operator=(const IVeSolarFluxGeoMagEnterManually&) = delete;

	IVeSolarFluxGeoMagEnterManually(CSatellite* pSate);
	~IVeSolarFluxGeoMagEnterManually();

	//********************************************************************
	/// 设置HPOP轨道力模型中大气阻力摄动的平均F10.7
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dAF107 平均F10.7
	//********************************************************************
	void SetAverageF107(double dAF107);
	//********************************************************************
	/// 获得HPOP轨道力模型中大气阻力摄动的平均F10.7
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	平均F10.7
	//********************************************************************
	double GetAverageF107();

	//********************************************************************
	/// 设置HPOP轨道力模型中大气阻力摄动的F10.7
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dDF107 F10.7
	//********************************************************************
	void SetDailyF107(double dDF107);
	//********************************************************************
	/// 获得HPOP轨道力模型中大气阻力摄动的F10.7
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	F10.7
	//********************************************************************
	double GetDailyF107();

	//********************************************************************
	/// 设置HPOP轨道力模型中大气阻力摄动的地磁指数
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dGIndex 地磁指数
	//********************************************************************
	void SetGeomagneticIndex(double dGIndex);
	//********************************************************************
	/// 获得HPOP轨道力模型中大气阻力摄动的地磁指数
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	地磁指数
	//********************************************************************
	double GetGeomagneticIndex();

private:
	CSatellite* m_pSate;

};
