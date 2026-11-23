#pragma once
#include <string>
#include "../IComponentInfo.h"
class CAsStateCalc;
class CSatellite;

///
/// 计算量FPA
///
class IATKOBJECT_API IVAStateCalcFPA : public IComponentInfo
{
public:
    IVAStateCalcFPA(const IVAStateCalcFPA&) = delete;
    IVAStateCalcFPA& operator=(const IVAStateCalcFPA&) = delete;

	IVAStateCalcFPA(CMCSSegment* pcSegment, CAsStateCalc* pcAsStateCalc);
	~IVAStateCalcFPA();

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
	//CSatellite*       m_pSate;
	CMCSSegment*      m_pcSegment;
	CAsStateCalc*     m_pcAsStateCalc;

};
