#pragma once
#include "../../../ICEnum.h"
#include "../IComponentInfo.h"
class CObjManage;
class CMCSPropagate;
class CMCSHold;
class CAsStopCondition;
class IVAMCSSegment;
class IVAMCSPropagate;
class IVAMCSManeuver;
class IVAMCSHold;
class IVAStoppingConditionComponent;
class IVAStoppingConditionCollection;

///
/// 停止条件元素
///
class IATKOBJECT_API IVAStoppingConditionElement : public IComponentInfo
{
public:
    IVAStoppingConditionElement(const IVAStoppingConditionElement&) = delete;
    IVAStoppingConditionElement& operator=(const IVAStoppingConditionElement&) = delete;

	IVAStoppingConditionElement(CMCSPropagate* pcPropagate, 
		IVAMCSSegment* pIVAMCSSegment, 
		CAsStopCondition* pcStopCondition,
		IVAStoppingConditionCollection* pISCColl,
		int nType);
	IVAStoppingConditionElement(CMCSHold* pcHold,
		IVAMCSSegment* pIVAMCSSegment,
		CAsStopCondition* pcStopCondition,
		IVAStoppingConditionCollection* pISCColl,
		int nType);
	~IVAStoppingConditionElement();

	//********************************************************************
	/// 移除停止条件控制变量
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eParam  停止条件控制变量属性  
	/// @Return	
	//********************************************************************
	void DisableControlParameter(EVAControlStoppingCondition eParam);

	//********************************************************************
	/// 添加停止条件控制变量
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eParam  停止条件控制变量属性  
	/// @Return	
	//********************************************************************
	void EnableControlParameter(EVAControlStoppingCondition eParam);

	//********************************************************************
	/// 查看停止条件控制变量是否添加
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eParam  停止条件控制变量属性  
	/// @Return	
	//********************************************************************
	bool IsControlParameterEnabled(EVAControlStoppingCondition eParam);

	//********************************************************************
	/// 查看停止条件选中状态
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	bActive  停止条件选中状态
	/// @Return	
	//********************************************************************
	void SetActive(bool bActive);
	//********************************************************************
	/// 获得停止条件选中状态
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	停止条件选中状态
	//********************************************************************
	bool GetActive();

	//********************************************************************
	/// 获得停止条件控制变量是否可设置
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	停止条件控制变量是否可设置
	//********************************************************************
	bool GetControlParametersAvailable();

	//********************************************************************
	/// 获得停止条件控制变量属性
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	停止条件控制变量属性
	//********************************************************************
	IVAStoppingConditionComponent* GetProperties();

private:
	CMCSPropagate*                     m_pcPropagate;
	CMCSHold*                          m_pcHold;
	CAsStopCondition*                  m_pcStopCondition; 
	IVAMCSSegment*                     m_pIVAMCSSegment;
	IVAStoppingConditionCollection*    m_pISCColl;
	int                                m_nType;

	//bool                               m_Active;                       //停止条件选中状态，true-选中
	//bool                               m_ControlParametersAvailable;   //停止条件控制变量是否可设置
	IVAStoppingConditionComponent*     m_Properties;                   //停止条件控制变量属性


	static void HandleStoppingCondition(IVAStoppingConditionElement* self, const AsTEvent& event_);

};
