#pragma once
#include "ISRPModelBase.h"
class CSatellite;

///
/// 太阳光压
///
class IATKOBJECT_API ISRPModelSpherical : public ISRPModelBase
{
public:
    ISRPModelSpherical(const ISRPModelSpherical&) = delete;
    ISRPModelSpherical& operator=(const ISRPModelSpherical&) = delete;

	ISRPModelSpherical(CSatellite* pSate);
	~ISRPModelSpherical();

	//********************************************************************
	/// 设置HPOP轨道力模型中太阳光压的面积
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dAreaMassRatio 太阳光压面积
	//********************************************************************
	void SetAreaMassRatio(double dAreaMassRatio);
	//********************************************************************
	/// 获得HPOP轨道力模型中太阳光压的面积
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	太阳光压面积
	//********************************************************************
	double GetAreaMassRatio();

	//********************************************************************
	/// 设置HPOP轨道力模型中太阳光压的光压系数
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dCr 光压系数
	//********************************************************************
	void SetCr(double dCr);
	//********************************************************************
	/// 获得HPOP轨道力模型中太阳光压的光压系数
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	光压系数
	//********************************************************************
	double GetCr();

private:
	CSatellite*     m_pSate;

};
