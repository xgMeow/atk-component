#pragma once
#include "../../IAtkObj.h"
class CSatellite;
class IVeHPOPSRPModel;

///
/// 太阳光压
///
class IATKOBJECT_API IVeHPOPSolarRadiationPressure
{
public:
    IVeHPOPSolarRadiationPressure(const IVeHPOPSolarRadiationPressure&) = delete;
    IVeHPOPSolarRadiationPressure& operator=(const IVeHPOPSolarRadiationPressure&) = delete;

	IVeHPOPSolarRadiationPressure(CSatellite* pSate);
	~IVeHPOPSolarRadiationPressure();

	//********************************************************************
	/// 设置HPOP轨道力模型中太阳光压是否使用
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	bUse 太阳光压是否使用
	//********************************************************************
	void SetUse(bool bUse);
	//********************************************************************
	/// 获得HPOP轨道力模型中太阳光压是否使用
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	太阳光压是否使用
	//********************************************************************
	bool GetUse();

	//********************************************************************
	/// 获得HPOP轨道力模型中太阳光压模型属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	太阳光压模型属性指针
	//********************************************************************
	IVeHPOPSRPModel* GetSRPModel();

private:
	CSatellite*          m_pSate;

	IVeHPOPSRPModel*     m_SRPModel;   //太阳光压模型属性

};
