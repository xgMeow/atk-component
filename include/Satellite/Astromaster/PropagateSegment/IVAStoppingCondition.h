#pragma once
#include <string> 
#include "IVAStoppingConditionComponent.h"
class CAsStopCondition;
class IComponentInfo;

///
/// 停止条件属性
///
class IATKOBJECT_API IVAStoppingCondition : public IVAStoppingConditionComponent
{
public:
    IVAStoppingCondition(const IVAStoppingCondition&) = delete;
    IVAStoppingCondition& operator=(const IVAStoppingCondition&) = delete;

	IVAStoppingCondition(CAsStopCondition* pStopCondition);
	~IVAStoppingCondition();

	//********************************************************************
	/// 设置中心天体名称属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strCBName 中心天体名称，Earth，Moon，Mars
	/// @Return	
	//********************************************************************
	void SetCentralBodyName(std::string strCBName);
	//********************************************************************
	/// 获得中心天体名称属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	中心天体名称
	//********************************************************************
	std::string GetCentralBodyName();

	//********************************************************************
	/// 设置坐标系属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strCoordSyatem 坐标系名称,"CentralBody/Earth J2000"
	/// @Return	
	//********************************************************************
	void SetCoordSystem(std::string strCoordSystem);
	//********************************************************************
	/// 获得坐标系属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	坐标系名称
	//********************************************************************
	std::string GetCoordSystem();

	//********************************************************************
	/// 设置触发条件属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eType 停止条件触发条件
	/// @Return	
	//********************************************************************
	void SetCriterion(EVACriterion eType);
	//********************************************************************
	/// 获得触发条件属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	停止条件触发条件
	//********************************************************************
	EVACriterion GetCriterion();

	//********************************************************************
	/// 设置重复次数属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dRepeatCount 重复次数
	/// @Return	
	//********************************************************************
	void SetRepeatCount(int dRepeatCount);

	//********************************************************************
	/// 获得重复次数属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	重复次数
	//********************************************************************
	int GetRepeatCount();

	//********************************************************************
	/// 设置误差值属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dTolerance 误差值
	/// @Return	
	//********************************************************************
	void SetTolerance(double dTolerance);
	//********************************************************************
	/// 获得误差值属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	误差值
	//********************************************************************
	double GetTolerance();

	//********************************************************************
	/// 设置触发值属性值/设置停止条件Epoch触发值属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dTrip/strEpochTrip 触发值
	/// @Return	
	//********************************************************************
	void SetTrip(double dTrip);
	void SetTrip(std::string strEpochTrip);
	//********************************************************************
	/// 获得触发值属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	触发值
	//********************************************************************
	std::string GetTrip();

	//********************************************************************
	/// 设置计算对象属性
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	pIComponentInfo 计算对象属性
	/// @Return	
	//********************************************************************
	void SetUserCalcObject(IComponentInfo* pIComponentInfo);
	//********************************************************************
	/// 获得计算对象属性
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	计算对象指针
	//********************************************************************
	IComponentInfo* GetUserCalcObject();

	//********************************************************************
	/// 设置计算对象名称属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strUCOName 计算对象名称
	/// @Return	
	//********************************************************************
	void SetUserCalcObjectName(std::string strUCOName);
	//********************************************************************
	/// 获得计算对象名称属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	计算对象名称
	//********************************************************************
	std::string GetUserCalcObjectName();

private:
	CAsStopCondition*     m_pStopCondition;

	IComponentInfo*       m_UserCalcObject;       //计算对象属性

};
