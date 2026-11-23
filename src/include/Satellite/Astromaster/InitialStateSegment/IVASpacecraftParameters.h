#pragma once
#include "../../../IAtkObj.h"
class CMCSSegment;
class CMCSInitialState;
class CMCSFollow;

///
/// 航天器参数
///
class IATKOBJECT_API IVASpacecraftParameters
{
public:
    IVASpacecraftParameters(const IVASpacecraftParameters&) = delete;
    IVASpacecraftParameters& operator=(const IVASpacecraftParameters&) = delete;

	IVASpacecraftParameters(CMCSSegment* pcSegment);
	~IVASpacecraftParameters();

	//********************************************************************
	/// 设置阻力系数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dCd 阻力系数
	/// @Return	
	//********************************************************************
	void SetCd(double dCd);
	//********************************************************************
	/// 获得阻力系数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	阻力系数
	//********************************************************************
	double GetCd();

	//********************************************************************
	/// 设置光压系数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dCr 光压系数
	/// @Return	
	//********************************************************************
	void SetCr(double dCr);
	//********************************************************************
	/// 获得光压系数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	光压系数
	//********************************************************************
	double GetCr();

	//********************************************************************
	/// 设置阻力面积
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dDragArea 阻力面积，默认单位m^2
	/// @Return	
	//********************************************************************
	void SetDragArea(double dDragArea);
	//********************************************************************
	/// 获得阻力面积
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	阻力面积，默认单位m^2
	//********************************************************************
	double GetDragArea();

	//********************************************************************
	/// 设置干重
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dDryMass 干重，默认单位kg
	/// @Return	
	//********************************************************************
	void SetDryMass(double dDryMass);
	//********************************************************************
	/// 获得干重
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	干重，默认单位kg
	//********************************************************************
	double GetDryMass();

	//********************************************************************
	/// 设置光压面积
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dSRPArea 光压面积，默认单位m^2
	/// @Return	
	//********************************************************************
	void SetSolarRadiationPressureArea(double dSRPArea);
	//********************************************************************
	/// 获得光压面积
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	光压面积，默认单位m^2
	//********************************************************************
	double GetSolarRadiationPressureArea();


private:
	CMCSInitialState*     m_pcInitialState;
	CMCSFollow*           m_pcFollow;

};
