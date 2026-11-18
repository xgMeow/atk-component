#pragma once
#include <vector>
#include "../IVAMCSSegment.h"
#include "../../../ICEnum.h"
class CObjManage;
class CSatellite;
class CMCSInitialState;
class IVAElement;
class IVAFuelTank;
class IVASpacecraftParameters;

///
/// 初始段
///
class IATKOBJECT_API IVAMCSInitialState : public IVAMCSSegment
{
public:
    IVAMCSInitialState(const IVAMCSInitialState&) = delete;
    IVAMCSInitialState& operator=(const IVAMCSInitialState&) = delete;

	IVAMCSInitialState(CSatellite* pSate, CMCSInitialState* pcInitialState, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVAMCSInitialState();

	//********************************************************************
	/// 移除控制变量
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eParam  控制变量属性  
	/// @Return	
	//********************************************************************
	void DisableControlParameter(EVAControlInitState eParam);

	//********************************************************************
	/// 添加控制变量
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eParam  控制变量属性  
	/// @Return	
	//********************************************************************
	void EnableControlParameter(EVAControlInitState eParam);

	//********************************************************************
	/// 查看控制变量是否添加
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eParam  控制变量属性  
	/// @Return	true-控制变量已添加
	//********************************************************************
	bool IsControlParameterEnabled(EVAControlInitState eParam);

	//********************************************************************
	/// 设置段的坐标类型
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eElementType   坐标类型
	/// @Return				
	//********************************************************************
	void SetElementType(EVAElementType eElementType);

	//********************************************************************
	/// 设置轨道历元
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strOrbitEpoch UTCG格式，例如"1 Jul 2009 15:00:00.000"
	/// @Return				
	//********************************************************************
	void SetOrbitEpoch(std::string strOrbitEpoch);
	//********************************************************************
	/// 获得轨道历元
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	UTCG格式，例如"1 Jul 2009 15:00:00.000"
	//********************************************************************
	std::string GetOrbitEpoch();

	//********************************************************************
	/// 设置坐标系名称
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strCoordSysName 例如"CentralBody/Earth J2000"
	/// @Return				
	//********************************************************************
	void SetCoordSystemName(std::string strCoordSysName);
	//********************************************************************
	/// 获得坐标系名称
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	例如"CentralBody/Earth J2000"
	//********************************************************************
	std::string GetCoordSystemName();

	//********************************************************************
	/// 获得坐标属性
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	坐标指针
	//********************************************************************
	IVAElement* GetElement();

	//********************************************************************
	/// 获得坐标类型
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	坐标类型
	//********************************************************************
	EVAElementType GetElementType();

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

	//********************************************************************
	/// 获得控制变量是否可得
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return 
	//********************************************************************
	bool GetControlParametersAvailable();

private:
	CObjManage*                m_IAsGObjManage;
	CSatellite*                m_pSate;
	CMCSInitialState*          m_pcInitialState;

	IVAElement*                m_Element;                      //坐标属性
	IVAFuelTank*               m_FuelTank;                     //推进剂参数
	IVASpacecraftParameters*   m_SpacecraftParameters;         //航天器参数

	std::string eTypeToStrName(EVAControlInitState eParam);

};
