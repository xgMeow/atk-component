#pragma once
#include <string>
#include "../../../ICEnum.h"
#include "../IComponentInfo.h"
class CMCSSegment;
class CAsStateCalc;

///
/// 计算量Dec
///
class IATKOBJECT_API IVAStateCalcDec : public IComponentInfo
{
public:
    IVAStateCalcDec(const IVAStateCalcDec&) = delete;
    IVAStateCalcDec& operator=(const IVAStateCalcDec&) = delete;

	IVAStateCalcDec(CSatellite* pSate, CMCSSegment* pcSegment, CAsStateCalc* pcAsStateCalc);
	~IVAStateCalcDec();

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
	CMCSSegment*          m_pcSegment;
	CAsStateCalc*         m_pcAsStateCalc;

	EVACalcObjectElem     m_ElementType;
};
