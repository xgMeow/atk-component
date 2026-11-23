#pragma once
#include "../IVAMCSSegment.h"
class CObjManage;
class CSatellite;
class CMCSFollow;
class IVAStoppingConditionCollection;
class IVAFuelTank;
class IVASpacecraftParameters;

///
/// 跟随段
///
class IATKOBJECT_API IVAMCSFollow : public IVAMCSSegment
{
public:
    IVAMCSFollow(const IVAMCSFollow&) = delete;
    IVAMCSFollow& operator=(const IVAMCSFollow&) = delete;

	IVAMCSFollow(CSatellite* pSate, CMCSFollow* pcFollow, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVAMCSFollow();

	//********************************************************************
	/// 移除控制变量
	/// @Author	Dong Min
	/// @Date	2025-09-02
	/// @Input
	/// @Param	eParam  控制变量属性  
	/// @Return	
	//********************************************************************
	void DisableControlParameter(EVAControlFollow eParam);

	//********************************************************************
	/// 添加控制变量
	/// @Author	Dong Min
	/// @Date	2025-09-02
	/// @Input
	/// @Param	eParam  控制变量属性  
	/// @Return	
	//********************************************************************
	void EnableControlParameter(EVAControlFollow eParam);

	//********************************************************************
	/// 查看控制变量是否添加
	/// @Author	Dong Min
	/// @Date	2025-09-02
	/// @Input
	/// @Param	eParam  控制变量属性  
	/// @Return	true-控制变量已添加
	//********************************************************************
	bool IsControlParameterEnabled(EVAControlFollow eParam);

	//********************************************************************
	/// 获得控制变量是否可得
	/// @Author	Dong Min
	/// @Date  2025-09-02
	/// @Return 
	//********************************************************************
	bool GetControlParametersAvailable();

	//********************************************************************
	/// 设置跟随类型
	/// @Author	Dong Min
	/// @Date	2025-09-02
	/// @Input
	/// @Param	eJoinType 跟随类型
	/// @Return				
	//********************************************************************
	void SetJoiningType(EVAFollowJoin eJoinType);
	//********************************************************************
	/// 获得跟随类型
	/// @Author	Dong Min
	/// @Date	2025-09-02
	/// @Return	跟随类型
	//********************************************************************
	EVAFollowJoin GetJoiningType();

	//********************************************************************
	/// 设置分离类型
	/// @Author	Dong Min
	/// @Date	2025-09-02
	/// @Input
	/// @Param	eSeparaType 分离类型
	/// @Return				
	//********************************************************************
	void SetSeparationType(EVAFollowSeparation eSeparaType);
	//********************************************************************
	/// 获得分离类型
	/// @Author	Dong Min
	/// @Date	2025-09-02
	/// @Return	分离类型
	//********************************************************************
	EVAFollowSeparation GetSeparationType();

	//********************************************************************
	/// 设置航天器参数设置方式
	/// @Author	Dong Min
	/// @Date	2025-09-02
	/// @Input
	/// @Param	eSpaAndFuel 航天器参数设置方式
	/// @Return				
	//********************************************************************
	void SetSpacecraftAndFuelTankType(EVAFollowSpacecraftAndFuelTank eSpaAndFuel);
	//********************************************************************
	/// 获得航天器参数设置方式
	/// @Author	Dong Min
	/// @Date	2025-09-02
	/// @Return	航天器参数设置方式
	//********************************************************************
	EVAFollowSpacecraftAndFuelTank GetSpacecraftAndFuelTankType();

	//********************************************************************
	/// 设置位置X
	/// @Author	Dong Min
	/// @Date	2025-09-02
	/// @Input
	/// @Param	dXOff 位置X
	/// @Return				
	//********************************************************************
	void SetXOffset(double dXOff);
	//********************************************************************
	/// 获得位置X
	/// @Author	Dong Min
	/// @Date	2025-09-02
	/// @Return	位置X
	//********************************************************************
	double GetXOffset();

	//********************************************************************
	/// 设置位置Y
	/// @Author	Dong Min
	/// @Date	2025-09-02
	/// @Input
	/// @Param	dYOff 位置Y
	/// @Return				
	//********************************************************************
	void SetYOffset(double dYOff);
	//********************************************************************
	/// 获得位置Y
	/// @Author	Dong Min
	/// @Date	2025-09-02
	/// @Return	位置Y
	//********************************************************************
	double GetYOffset();

	//********************************************************************
	/// 设置位置Z
	/// @Author	Dong Min
	/// @Date	2025-09-02
	/// @Input
	/// @Param	dZOff 位置Z
	/// @Return				
	//********************************************************************
	void SetZOffset(double dZOff);
	//********************************************************************
	/// 获得位置Z
	/// @Author	Dong Min
	/// @Date	2025-09-02
	/// @Return	位置Z
	//********************************************************************
	double GetZOffset();

	//********************************************************************
	/// 获得跟随属性操作指针
	/// @Author	Dong Min
	/// @Date	2025-09-02
	/// @Return	跟随属性操作指针
	//********************************************************************
	IVAStoppingConditionCollection* GetJoiningConditions();

	//********************************************************************
	/// 获得分离属性操作指针
	/// @Author	Dong Min
	/// @Date	2025-09-02
	/// @Return	分离属性操作指针
	//********************************************************************
	IVAStoppingConditionCollection* GetSeparationConditions();

	//********************************************************************
	/// 设置参考航天器
	/// @Author	Dong Min
	/// @Date	2025-09-02
	/// @Input
	/// @Param	strObjPath 对象路径，例"Satellite/Satellite1"
	/// @Return	
	//********************************************************************
	void SetLeader(std::string strObjPath);
	//********************************************************************
	/// 获得参考航天器
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	对象路径
	//********************************************************************
	std::string GetLeader();

	//********************************************************************
	/// 获得推进剂参数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	推进剂参数
	//********************************************************************
	IVAFuelTank* GetFuelTank();

	//********************************************************************
	/// 获得航天器参数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	航天器参数
	//********************************************************************
	IVASpacecraftParameters* GetSpacecraftParameters();


private:
	CObjManage*                           m_IAsGObjManage;
	CSatellite*							  m_pSate;
	CMCSFollow*                           m_pcFollow;

private:
	IVAFuelTank*                                     m_FuelTank;                     //推进剂参数
	IVASpacecraftParameters*                         m_SpacecraftParameters;         //航天器参数
	IVAStoppingConditionCollection*                  m_JoiningConditions;            //跟随参数
	IVAStoppingConditionCollection*                  m_SeparationConditions;         //分离参数


	std::string eTypeToStrName(EVAControlFollow eParam);
	 
};
