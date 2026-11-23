#pragma once
#include <string>
#include "../IComponentInfo.h"
class CMCSSegment;
class CAsStateCalc;

///
/// 计算量GeodeticElem
///
class IATKOBJECT_API IVAStateCalcGeodeticElem : public IComponentInfo
{
public:
    IVAStateCalcGeodeticElem(const IVAStateCalcGeodeticElem&) = delete;
    IVAStateCalcGeodeticElem& operator=(const IVAStateCalcGeodeticElem&) = delete;

	IVAStateCalcGeodeticElem(CMCSSegment* pcSegment, CAsStateCalc* pcAsStateCalc);
	~IVAStateCalcGeodeticElem();

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
