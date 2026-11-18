#pragma once
#include <string> 
#include "../../../ICEnum.h"
#include "../IComponentInfo.h"
class CMCSSegment;
class CAsStateCalc;

///
/// 计算量ArgOfLat
///
class IATKOBJECT_API IVAStateCalcArgOfLat : public IComponentInfo
{
public:
    IVAStateCalcArgOfLat(const IVAStateCalcArgOfLat&) = delete;
    IVAStateCalcArgOfLat& operator=(const IVAStateCalcArgOfLat&) = delete;

	IVAStateCalcArgOfLat(CMCSSegment* pcSegment, CAsStateCalc* pcAsStateCalc);
	~IVAStateCalcArgOfLat();

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
	/// 获得坐标系
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	坐标系
	//********************************************************************
	std::string GetCoordSystemName();

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
	EVACalcObjectElem GetElementType();

private:
	CMCSSegment*          m_pcSegment;
	CAsStateCalc*         m_pcAsStateCalc;

	EVACalcObjectElem     m_ElementType;

};
