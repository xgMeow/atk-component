#pragma once
#include "../../../IAtkObj.h"
class CMCSSegment;
class CMCSInitialState;
class CMCSFollow;

///
/// 航天器参数推进剂质量
///
class IATKOBJECT_API IVAFuelTank
{
public:
    IVAFuelTank(const IVAFuelTank&) = delete;
    IVAFuelTank& operator=(const IVAFuelTank&) = delete;

	IVAFuelTank(CMCSSegment* pcSegment);
	~IVAFuelTank();

	//********************************************************************
	/// 设置推进剂质量
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dFuelMass  推进剂质量，默认单位kg
	/// @Return	
	//********************************************************************
	void SetFuelMass(double dFuelMass);
	//********************************************************************
	/// 获得推进剂质量
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	推进剂质量，默认单位kg
	//********************************************************************
	double GetFuelMass();

private:
	CMCSInitialState*     m_pcInitialState;
	CMCSFollow*           m_pcFollow;

};
