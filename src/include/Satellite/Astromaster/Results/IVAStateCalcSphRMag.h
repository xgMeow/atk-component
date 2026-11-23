#pragma once
#include <string>
#include "../IComponentInfo.h"
class CMCSSegment;
class CAsStateCalc;

///
/// 计算量SphRMag
///
class IATKOBJECT_API IVAStateCalcSphRMag : public IComponentInfo
{
public:
    IVAStateCalcSphRMag(const IVAStateCalcSphRMag&) = delete;
    IVAStateCalcSphRMag& operator=(const IVAStateCalcSphRMag&) = delete;

	IVAStateCalcSphRMag(CMCSSegment* pcSegment, CAsStateCalc* pcAsStateCalc);
	~IVAStateCalcSphRMag();

	//********************************************************************
	/// 设置坐标系
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strCBName   坐标系，例:"CentralBody/Earth ICRF" 
	///										或 "Satellite/Satellite2 J2000"
	/// @Return	
	//********************************************************************
	void SetCoordSystemName(std::string strCSName);
	//********************************************************************
	/// 获得坐标系名称
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	坐标系名称
	//********************************************************************
	std::string GetCoordSystemName();

private:
	CMCSSegment*      m_pcSegment;
	CAsStateCalc*     m_pcAsStateCalc;
};

