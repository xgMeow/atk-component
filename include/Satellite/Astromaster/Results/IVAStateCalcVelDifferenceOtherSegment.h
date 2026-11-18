#pragma once
#include <string>
#include "../../../ICEnum.h"
#include "../IComponentInfo.h"
class CSatellite;
class CMCSSegment;
class CAsStateCalc;

///
/// 计算量VelDifferenceOtherSegment
///
class IATKOBJECT_API IVAStateCalcVelDifferenceOtherSegment : public IComponentInfo
{
public:
    IVAStateCalcVelDifferenceOtherSegment(const IVAStateCalcVelDifferenceOtherSegment&) = delete;
    IVAStateCalcVelDifferenceOtherSegment& operator=(const IVAStateCalcVelDifferenceOtherSegment&) = delete;

	IVAStateCalcVelDifferenceOtherSegment(CSatellite* pSate, CMCSSegment* pcSegment, CAsStateCalc* pcAsStateCalc);
	~IVAStateCalcVelDifferenceOtherSegment();

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
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eType   段采用状态
	/// @Return	
	//********************************************************************
	void SetSegmentStateToUse(EVASegmentState eType);
	//********************************************************************
	/// 获得计算量段采用状态
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	段采用状态
	//********************************************************************
	EVASegmentState GetSegmentStateToUse();

private:
	CSatellite*       m_pSate;
	CMCSSegment*      m_pcSegment;
	CAsStateCalc*     m_pcAsStateCalc;
};
