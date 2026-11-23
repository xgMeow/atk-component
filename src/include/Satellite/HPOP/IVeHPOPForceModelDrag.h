#pragma once
#include "../../ICEnum.h"
#include "../../IAtkObj.h"
class CSatellite;
class IVeHPOPDragModel;
class IVeSolarFluxGeoMag;      

///
/// 大气阻力摄动
///
class IATKOBJECT_API IVeHPOPForceModelDrag
{
public:
    IVeHPOPForceModelDrag(const IVeHPOPForceModelDrag&) = delete;
    IVeHPOPForceModelDrag& operator=(const IVeHPOPForceModelDrag&) = delete;

	IVeHPOPForceModelDrag(CSatellite* pSate);
	~IVeHPOPForceModelDrag();

	//********************************************************************
	/// 设置HPOP轨道力模型中大气阻力摄动的大气模型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eADModel 大气阻力摄动的大气模型
	//********************************************************************
	void SetAtmosphericDensityModel(EAtmosphericDensityModel eADModel);
	//********************************************************************
	/// 获得HPOP轨道力模型中大气阻力摄动的大气模型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	大气模型
	//********************************************************************
	EAtmosphericDensityModel GetAtmosphericDensityModel();

	//********************************************************************
	/// 获得HPOP轨道力模型中大气阻力摄动的大气阻力系数和阻力面积属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	大气阻力摄动属性指针
	//********************************************************************
	IVeHPOPDragModel* GetDragModel();

	//********************************************************************
	/// 获得HPOP轨道力模型中大气阻力摄动的太阳辐射通量/地磁指数属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	太阳辐射通量/地磁指数属性指针
	//********************************************************************
	IVeSolarFluxGeoMag* GetSolarFluxGeoMag();

private:
	CSatellite*                  m_pSate;

	IVeHPOPDragModel*            m_DragModel;                 //HPOP轨道力模型中大气阻力摄动的大气阻力系数和阻力面积属性
	IVeSolarFluxGeoMag*          m_SolarFluxGeoMag;           //HPOP轨道力模型中大气阻力摄动的太阳辐射通量/地磁指数属性

};
