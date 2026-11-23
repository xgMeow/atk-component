#pragma once
#include <string>
#include "../../../ICEnum.h"
#include "../IComponentInfo.h"
class CMCSSegment;
class CAsStateCalc;

///
/// 计算量DeltaRA
///
class IATKOBJECT_API IVAStateCalcDeltaRA : public IComponentInfo
{
public:
    IVAStateCalcDeltaRA(const IVAStateCalcDeltaRA&) = delete;
    IVAStateCalcDeltaRA& operator=(const IVAStateCalcDeltaRA&) = delete;

	IVAStateCalcDeltaRA(CMCSSegment* pcSegment, CAsStateCalc* pcAsStateCalc);
	~IVAStateCalcDeltaRA();

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
	CMCSSegment*          m_pcSegment;
	CAsStateCalc*         m_pcAsStateCalc;

	EVACalcObjectElem     m_ElementType;

	//std::string     ReferenceBody;
	//EVACalcObjectCentralBodyReference ReferenceType;

};
