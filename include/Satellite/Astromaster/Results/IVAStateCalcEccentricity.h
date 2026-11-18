#pragma once
#include <string>
#include "../../../ICEnum.h"
#include "../IComponentInfo.h"
class CMCSSegment;
class CAsStateCalc;

///
/// 计算量Eccentricity
///
class IATKOBJECT_API IVAStateCalcEccentricity : public IComponentInfo
{
public:
    IVAStateCalcEccentricity(const IVAStateCalcEccentricity&) = delete;
    IVAStateCalcEccentricity& operator=(const IVAStateCalcEccentricity&) = delete;

	IVAStateCalcEccentricity(CMCSSegment* pcSegment, CAsStateCalc* pcAsStateCalc);
	~IVAStateCalcEccentricity();

	//********************************************************************
	/// 设置中心天体名称
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strCBName   中心天体名称，例：Earth，Moon，Mars
	/// @Return	
	//********************************************************************
	void SetCentralBodyName(std::string strCBName);
	//********************************************************************
	/// 获得中心天体名称
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	中心天体名称
	//********************************************************************
	std::string GetCentralBodyName();

	//********************************************************************
	/// 设置名称相同计算量的类型
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eElementType   名称相同计算量的类型
	/// @Return	
	//********************************************************************
	void SetElementType(EVACalcObjectElem eElementType);
	//********************************************************************
	/// 获得名称相同计算量的类型
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	名称相同计算量的类型
	//********************************************************************
	EVACalcObjectElem GetElementType() { return m_ElementType; }

private:
	CMCSSegment*          m_pcSegment;
	CAsStateCalc*         m_pcAsStateCalc;

	EVACalcObjectElem     m_ElementType;

};
