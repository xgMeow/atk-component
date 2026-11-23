#pragma once 
#include "../IVAMCSSegment.h"
#include "../../../ICEnum.h"
class CObjManage;
class CSatellite;
class CMCSManeuver;
class IVAManeuver;

///
/// 机动段
///
class IATKOBJECT_API IVAMCSManeuver : public IVAMCSSegment
{
public:
    IVAMCSManeuver(const IVAMCSManeuver&) = delete;
    IVAMCSManeuver& operator=(const IVAMCSManeuver&) = delete;

	IVAMCSManeuver(CSatellite* pSate, CMCSManeuver* pcManeuver, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVAMCSManeuver();

	//********************************************************************
	/// 移除控制变量
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eParam  控制变量属性  
	/// @Return	
	//********************************************************************
	void DisableControlParameter(EVAControlManeuver eParam);

	//********************************************************************
	/// 添加控制变量
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eParam  控制变量属性  
	/// @Return	
	//********************************************************************
	void EnableControlParameter(EVAControlManeuver eParam);

	//********************************************************************
	/// 查看控制变量是否添加
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eParam  控制变量属性  
	/// @Return	
	//********************************************************************
	bool IsControlParameterEnabled(EVAControlManeuver eParam);

	//********************************************************************
	/// 设置机动段的机动类型
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eManeuverType   机动类型
	/// @Return				
	//********************************************************************
	void SetManeuverType(EVAManeuverType eManeuverType);

	//********************************************************************
	/// 获得机动类型
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return 机动类型
	//********************************************************************
	EVAManeuverType GetManeuverType();

	//********************************************************************
	/// 获得机动属性，脉冲或有限推力
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	机动属性
	//********************************************************************
	IVAManeuver* GetManeuver();

	//********************************************************************
	/// 获得控制变量是否可得
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return 
	//********************************************************************
	bool GetControlParametersAvailable();


private:
	CObjManage*         m_IAsGObjManage;
	CSatellite*         m_pSate;
	CMCSManeuver*       m_pcManeuver;

	IVAManeuver*        m_Maneuver;                     //机动属性，脉冲或有限推力

	std::string eTypeToStrName(EVAControlManeuver eParam);

};
