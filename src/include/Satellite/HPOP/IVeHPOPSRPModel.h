#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
class CSatellite;
class ISRPModelBase;

///
/// 太阳光压模型
///
class IATKOBJECT_API IVeHPOPSRPModel
{
public:
    IVeHPOPSRPModel(const IVeHPOPSRPModel&) = delete;
    IVeHPOPSRPModel& operator=(const IVeHPOPSRPModel&) = delete;

	IVeHPOPSRPModel(CSatellite* pSate);
	~IVeHPOPSRPModel();

	//********************************************************************
	/// 设置HPOP轨道力模型中太阳光压模型类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	eSRPModel 太阳光压模型类型
	//********************************************************************
	void SetModelType(ESRPModel eSRPModel);

	//********************************************************************
	/// 获得HPOP轨道力模型中太阳光压模型属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	太阳光压模型属性指针
	//********************************************************************
	ISRPModelBase* GetModel();

	//********************************************************************
	/// 获得HPOP轨道力模型中太阳光压模型类型
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	太阳光压模型类型
	//********************************************************************
	ESRPModel GetModelType();

private:
	CSatellite*        m_pSate;

	ISRPModelBase*     m_Model;       //太阳光压模型属性

};
