#pragma once
#include "../IVAMCSSegment.h"
class CObjManage;
class CSatellite;
class CMCSHold;
class IVAStoppingConditionCollection;

///
/// 保持段
///
class IATKOBJECT_API IVAMCSHold : public IVAMCSSegment
{
public:
    IVAMCSHold(const IVAMCSHold&) = delete;
    IVAMCSHold& operator=(const IVAMCSHold&) = delete;

	IVAMCSHold(CSatellite* pSate, CMCSHold* pcHold, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVAMCSHold();

	//********************************************************************
	/// 设置步长
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dStepSize  步长，默认单位Sec
	/// @Return	
	//********************************************************************
	void SetStepSize(double dStepSize);
	//********************************************************************
	/// 获得步长
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	步长，默认单位Sec
	//********************************************************************
	double GetStepSize();

	//********************************************************************
	/// 设置最大预报时间
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dPropTime  预报时间，默认单位Sec
	/// @Return	
	//********************************************************************
	void SetMaxPropagationTime(double dPropTime);
	//********************************************************************
	/// 获得最大预报时间
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	预报时间，默认单位Sec
	//********************************************************************
	double GetMaxPropagationTime();

	//********************************************************************
	/// 设置保持段坐标系名称
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strHoldFrameName  保持段坐标系名称，例:"CentralBody/Earth ICRF" 
	///										或 "Satellite/Satellite2 J2000"
	/// @Return	
	//********************************************************************
	void SetHoldFrameName(std::string strHoldFrameName);
	//********************************************************************
	/// 获得保持段坐标系名称
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	保持段坐标系名称
	//********************************************************************
	std::string GetHoldFrameName();

	//********************************************************************
	/// 获得停止条件属性
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	停止条件指针
	//********************************************************************
	IVAStoppingConditionCollection* GetStoppingConditions();

private:
	CObjManage*                         m_IAsGObjManage;
	CMCSHold*                           m_pcHold;

	IVAStoppingConditionCollection*     m_StoppingConditions;   //停止条件属性

};
