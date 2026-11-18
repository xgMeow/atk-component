#pragma once
#include <string>
#include "../../../ICEnum.h"
#include "../IComponentInfo.h"
class CSatellite;
class CMCSSegment;
class CAsStateCalc;

///
/// 计算量PosVelDifferenceOtherSegment
///
class IATKOBJECT_API IVAStateCalcPosVelDifferenceOtherSegment : public IComponentInfo
{
public:
    IVAStateCalcPosVelDifferenceOtherSegment(const IVAStateCalcPosVelDifferenceOtherSegment&) = delete;
    IVAStateCalcPosVelDifferenceOtherSegment& operator=(const IVAStateCalcPosVelDifferenceOtherSegment&) = delete;

	IVAStateCalcPosVelDifferenceOtherSegment(CSatellite* pSate, CMCSSegment* pcSegment, CAsStateCalc* pcAsStateCalc);
	~IVAStateCalcPosVelDifferenceOtherSegment();


	//********************************************************************
	/// 设置段对象
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strOtherSegmentName   段对象名称，例：Target_Sequence.Maneuver
	/// @Return	
	//********************************************************************
	void SetOtherSegmentName(std::string strOtherSegmentName);
	//********************************************************************
	/// 获得段对象
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	段对象名称
	//********************************************************************
	std::string GetOtherSegmentName();

	//********************************************************************
	/// 设置计算量段采用状态
	/// @Author	Dong Min
	/// @Date	2023-12-11
	/// @Input
	/// @Param	eType   段采用状态
	/// @Return	
	//********************************************************************
	void SetSegmentStateToUse(EVASegmentState eType);
	//********************************************************************
	/// 获得计算量段采用状态
	/// @Author	Dong Min
	/// @Date	2023-12-11
	/// @Return	段采用状态
	//********************************************************************
	EVASegmentState GetSegmentStateToUse();

private:
	CSatellite*       m_pSate;
	CMCSSegment*      m_pcSegment;
	CAsStateCalc*     m_pcAsStateCalc;

};
