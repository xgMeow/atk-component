#pragma once
#include <string>
#include "../IComponentInfo.h"
class CMCSSegment;
class CAsStateCalc;

///
/// 计算量SphVMag
///
class IATKOBJECT_API IVAStateCalcSphVMag : public IComponentInfo
{
public:
    IVAStateCalcSphVMag(const IVAStateCalcSphVMag&) = delete;
    IVAStateCalcSphVMag& operator=(const IVAStateCalcSphVMag&) = delete;

	IVAStateCalcSphVMag(CMCSSegment* pcSegment, CAsStateCalc* pcAsStateCalc);
	~IVAStateCalcSphVMag();

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
