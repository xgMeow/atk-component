#pragma once
#include <string>
#include "../IComponentInfo.h"
class CAsStateCalc;
class CMCSSegment;

///
/// 计算量VMag
///
class IATKOBJECT_API IVAStateCalcVMag : public IComponentInfo
{
public:
    IVAStateCalcVMag(const IVAStateCalcVMag&) = delete;
    IVAStateCalcVMag& operator=(const IVAStateCalcVMag&) = delete;

	IVAStateCalcVMag(CMCSSegment* pcSegment, CAsStateCalc* pcAsStateCalc);
	~IVAStateCalcVMag();

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
