#pragma once
#include <string>
#include "../IComponentInfo.h"
class CMCSSegment;
class CAsStateCalc;

///
/// 计算量MeanEarthLon
///
class IATKOBJECT_API IVAStateCalcMeanEarthLon : public IComponentInfo
{
public:
    IVAStateCalcMeanEarthLon(const IVAStateCalcMeanEarthLon&) = delete;
    IVAStateCalcMeanEarthLon& operator=(const IVAStateCalcMeanEarthLon&) = delete;

	IVAStateCalcMeanEarthLon(CMCSSegment* pcSegment, CAsStateCalc* pcAsStateCalc);
	~IVAStateCalcMeanEarthLon();

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
