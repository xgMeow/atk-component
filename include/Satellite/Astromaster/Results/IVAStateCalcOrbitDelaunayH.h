#pragma once
#include <string>
#include "../../../ICEnum.h"
#include "../IComponentInfo.h"
class CMCSSegment;
class CAsStateCalc;

///
/// 计算量OrbitDelaunayH
///
class IATKOBJECT_API IVAStateCalcOrbitDelaunayH : public IComponentInfo
{
public:
    IVAStateCalcOrbitDelaunayH(const IVAStateCalcOrbitDelaunayH&) = delete;
    IVAStateCalcOrbitDelaunayH& operator=(const IVAStateCalcOrbitDelaunayH&) = delete;

	IVAStateCalcOrbitDelaunayH(CMCSSegment* pcSegment, CAsStateCalc* pcAsStateCalc);
	~IVAStateCalcOrbitDelaunayH();

	//********************************************************************
	/// 设置中心天体名称
	/// @Author	Dong Min
	/// @Date	2023-12-11
	/// @Input
	/// @Param	strCBName   中心天体名称，例：Earth，Moon，Mars
	/// @Return	
	//********************************************************************
	void SetCentralBodyName(std::string strCBName);
	//********************************************************************
	/// 获得中心天体名称
	/// @Author	Dong Min
	/// @Date	2023-12-11
	/// @Return	中心天体名称
	//********************************************************************
	std::string GetCentralBodyName();

	//********************************************************************
	/// 设置名称相同计算量的类型
	/// @Author	Dong Min
	/// @Date	2023-12-11
	/// @Input
	/// @Param	eElementType   名称相同计算量的类型
	/// @Return	
	//********************************************************************
	void SetElementType(EVACalcObjectElem eElementType);
	//********************************************************************
	/// 获得名称相同计算量的类型
	/// @Author	Dong Min
	/// @Date	2023-12-11
	/// @Return	名称相同计算量的类型
	//********************************************************************
	EVACalcObjectElem GetElementType() { return m_ElementType; }

private:
	CMCSSegment*          m_pcSegment;
	CAsStateCalc*         m_pcAsStateCalc;

	EVACalcObjectElem     m_ElementType;

};
