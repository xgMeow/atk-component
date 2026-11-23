#pragma once
#include "../../../ICEnum.h"
#include "../IVAMCSSegment.h"
class CObjManage;
class CSatellite;
class CMCSUpdate;

///
/// 基本属性
///
class IATKOBJECT_API IVAMCSUpdate : public IVAMCSSegment
{
public:
    IVAMCSUpdate(const IVAMCSUpdate&) = delete;
    IVAMCSUpdate& operator=(const IVAMCSUpdate&) = delete;

	IVAMCSUpdate(CSatellite* pSate, CMCSUpdate* pcUpdate, IVAMCSSegmentCollection* pISegColl, CObjManage* IAsGObjManage);
	~IVAMCSUpdate();

	//********************************************************************
	/// 移除控制变量
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eParam  控制变量属性  
	/// @Return	
	//********************************************************************
	void DisableControlParameter(EVAControlUpdate eParam);

	//********************************************************************
	/// 添加控制变量
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eParam  控制变量属性  
	/// @Return	
	//********************************************************************
	void EnableControlParameter(EVAControlUpdate eParam);

	//********************************************************************
	/// 获得属性操作类型
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eParameterType  属性类型  
	/// @Return	属性操作类型
	//********************************************************************
	EVAUpdateAction GetAction(EVAUpdateParam eParameterType);

	//********************************************************************
	/// 获得属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eParameterType  属性类型  
	/// @Return	属性值
	//********************************************************************
	double GetValue(EVAUpdateParam eParameterType);

	//********************************************************************
	/// 查看控制变量是否添加
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eParam  控制变量属性  
	/// @Return	true-控制变量已添加
	//********************************************************************
	bool IsControlParameterEnabled(EVAControlUpdate eParam);

	//********************************************************************
	/// 设置属性操作类型
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eParameterName  属性类型  
	/// @Param	eActionType     属性操作类型  
	/// @Return	
	//********************************************************************
	void SetAction(EVAUpdateParam eParameterName, EVAUpdateAction eActionType);

	//********************************************************************
	/// 设置属性操作类型和属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eParameterName  属性类型  
	/// @Param	eActionType     属性操作类型    
	/// @Param	dValue          属性值 
	/// @Return	
	//********************************************************************
	void SetActionAndValue(EVAUpdateParam eParameterType, EVAUpdateAction eActionType, double dValue);

	//********************************************************************
	/// 设置属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eParameterName  属性类型     
	/// @Param	dValue          属性值  
	/// @Return	
	//********************************************************************
	void SetValue(EVAUpdateParam eParameterName, double dValue);

	//********************************************************************
	/// 获得控制变量是否可得
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	控制变量是否可得
	//********************************************************************
	bool GetControlParametersAvailable();

public:
	//bool                                 ControlParametersAvailable;   //控制变量是否可得
	//IVAUserVariableUpdateCollection*     UserVariables;

private:
	CObjManage* m_IAsGObjManage;
	CMCSUpdate* m_pcUpdate;

	std::string eTypeToStrName(EVAControlUpdate eParam);

};
