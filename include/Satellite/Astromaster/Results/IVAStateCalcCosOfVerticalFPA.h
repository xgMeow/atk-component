#pragma once
#include <string>
#include "../IComponentInfo.h"
class CMCSSegment;
class CAsStateCalc;

///
/// 计算量CosOfVerticalFPA
///
class IATKOBJECT_API IVAStateCalcCosOfVerticalFPA : public IComponentInfo
{
public:
    IVAStateCalcCosOfVerticalFPA(const IVAStateCalcCosOfVerticalFPA&) = delete;
    IVAStateCalcCosOfVerticalFPA& operator=(const IVAStateCalcCosOfVerticalFPA&) = delete;

	IVAStateCalcCosOfVerticalFPA(CMCSSegment* pcSegment, CAsStateCalc* pcAsStateCalc);
	~IVAStateCalcCosOfVerticalFPA();

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

private:
	CMCSSegment*      m_pcSegment;
	CAsStateCalc*     m_pcAsStateCalc;
};
