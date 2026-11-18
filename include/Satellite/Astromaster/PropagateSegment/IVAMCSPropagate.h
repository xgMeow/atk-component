#pragma once
#include "../IVAMCSSegment.h"
class CObjManage;
class CSatellite;
class CMCSPropagate;
class IVAPropagator;
class IVAStoppingConditionCollection;

///
/// 预报段
///
class IATKOBJECT_API IVAMCSPropagate : public IVAMCSSegment
{
public:
    IVAMCSPropagate(const IVAMCSPropagate&) = delete;
    IVAMCSPropagate& operator=(const IVAMCSPropagate&) = delete;

	IVAMCSPropagate(CSatellite* pSate, CMCSPropagate* pcPropagate, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVAMCSPropagate();

	//********************************************************************
	/// 设置最大预报时间
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dMaxPropTime   最大预报时间
	/// @Return				
	//********************************************************************
	void SetMaxPropagationTime(double dMaxPropTime);
	//********************************************************************
	/// 获得最大预报时间
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	最大预报时间
	//********************************************************************
	double GetMaxPropagationTime();

	////********************************************************************
	///// 设置轨道预报中心天体名称
	///// @Author	Dong Min
	///// @Date	2023-11-3
	///// @Input
	///// @Param	strPropName   轨道预报中心天体名称，Earth，Moon，Mars
	///// @Return				
	////********************************************************************
	//void SetPropagatorName(std::string strPropName);
	////********************************************************************
	///// 获得轨道预报中心天体名称
	///// @Author	Dong Min
	///// @Date	2023-11-3
	///// @Return	轨道预报中心天体名称
	////********************************************************************
	//std::string GetPropagatorName() { return m_PropagatorName; }

	//********************************************************************
	/// 获得停止条件属性
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	停止条件指针
	//********************************************************************
	IVAStoppingConditionCollection* GetStoppingConditions();

	//********************************************************************
	/// 获得轨道预报属性
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	轨道预报属性指针
	//********************************************************************
	IVAPropagator* GetPropagator();

private:
	CObjManage*                         m_IAsGObjManage;
	CMCSPropagate*                      m_pcPropagate;

	IVAStoppingConditionCollection*     m_StoppingConditions;   //停止条件属性
	IVAPropagator*                      m_Propagator;           //轨道预报属性指针

};
