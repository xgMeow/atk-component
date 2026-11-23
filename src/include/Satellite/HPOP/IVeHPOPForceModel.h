#pragma once
#include "../../IAtkObj.h"
class CSatellite;
class ISatellite;
class IVeHPOPCentralBodyGravity;
class IVeHPOPForceModelDrag;
class IVeThirdBodyGravityCollection;
class IVeHPOPSolarRadiationPressure;

///
/// 轨道模型
///
class IATKOBJECT_API IVeHPOPForceModel
{
public:
    IVeHPOPForceModel(const IVeHPOPForceModel&) = delete;
    IVeHPOPForceModel& operator=(const IVeHPOPForceModel&) = delete;

	IVeHPOPForceModel(CSatellite* pSate, ISatellite* pISate);
	~IVeHPOPForceModel();

	//********************************************************************
	/// 获得HPOP轨道力模型中地球引力属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	地球引力属性指针
	//********************************************************************
	IVeHPOPCentralBodyGravity* GetCentralBodyGravity();

	//********************************************************************
	/// 获得HPOP轨道力模型中大气阻力摄动属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	大气阻力摄动属性指针
	//********************************************************************
	IVeHPOPForceModelDrag* GetDrag();

	//********************************************************************
	/// 获得HPOP轨道力模型中三体引力属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	三体引力属性指针
	//********************************************************************
	IVeThirdBodyGravityCollection* GetThirdBodyGravity();

	//********************************************************************
	/// 获得HPOP轨道力模型中太阳光压属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	太阳光压属性指针
	//********************************************************************
	IVeHPOPSolarRadiationPressure* GetSolarRadiationPressure();

private:
	CSatellite*                         m_pSate; 
	ISatellite*                         m_pISate;

	IVeHPOPCentralBodyGravity*          m_CentralBodyGravity;       //HPOP轨道力模型中地球引力属性
	IVeHPOPForceModelDrag*              m_Drag;                     //HPOP轨道力模型中大气阻力摄动属性
	IVeThirdBodyGravityCollection*      m_ThirdBodyGravity;         //HPOP轨道力模型中三体引力属性
	IVeHPOPSolarRadiationPressure*      m_SolarRadiationPressure;   //HPOP轨道力模型中太阳光压属性

};
