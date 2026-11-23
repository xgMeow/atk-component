#pragma once
#include <string>
#include "../../../ICEnum.h"
#include "../../../IAtkObj.h"
#include "../../../IClassInfo.h"
struct AsTEvent;
class CMCSTargetSequence;
class CAsShooterProfile;
class IVADCControlCollection;
class IVADCResultCollection;
class IVAProfileCollection;

///
/// 属性页参数
///
class IATKOBJECT_API IVAProfile :public IClassInfo
{
public:
    IVAProfile(const IVAProfile&) = delete;
    IVAProfile& operator=(const IVAProfile&) = delete;

	IVAProfile(CMCSTargetSequence* pcTargetSequence, CAsShooterProfile* pCAsShoProf, IVAProfileCollection* pIProfileColl);
	virtual ~IVAProfile();

	//********************************************************************
	/// 设置属性页模式类型
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	eProfMode   属性页模式类型
	/// @Return			
	//********************************************************************
	void SetMode(EVAProfileMode eProfMode);
	//********************************************************************
	/// 获得属性页模式类型
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	属性页模式类型	
	//********************************************************************
	EVAProfileMode GetMode();

	//********************************************************************
	/// 设置属性页名称
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strName   属性页名称
	/// @Return			
	//********************************************************************
	void SetName(std::string strName);
	//********************************************************************
	/// 获得属性页名称
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return 属性页名称	
	//********************************************************************
	std::string GetName();

	//********************************************************************
	/// 获得属性页类型
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	属性页类型	
	//********************************************************************
	EVAProfile GetType();

	//********************************************************************
	/// 设置属性页注释
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	strUserComment   属性页注释
	/// @Return			
	//********************************************************************
	void SetUserComment(std::string strUserComment);
	//********************************************************************
	/// 获得属性页注释
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	属性页注释	
	//********************************************************************
	std::string GetUserComment();

	//********************************************************************
	/// 获得控制变量属性
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	控制变量指针
	//********************************************************************
	IVADCControlCollection* GetControlParameters();

	//********************************************************************
	/// 获得约束条件属性
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	约束条件指针
	//********************************************************************
	IVADCResultCollection* GetResults();


private:
	CMCSTargetSequence*         m_pcTargetSequence;
	CAsShooterProfile*          m_pCAsShoProf;
	IVAProfileCollection*       m_pIProfileColl;

	IVADCControlCollection*     m_ControlParameters;           //控制变量属性
	IVADCResultCollection*      m_Results;                     //约束属性

	static void HandleProfile(IVAProfile* self, const AsTEvent& event_);

};
