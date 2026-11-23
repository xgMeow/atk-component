#pragma once
#include <string>
#include "../../../IAtkObj.h"
#include "../../../IClassInfo.h"
#include "../../../ICEnum.h"
class CMCSSegment;
class CAsShooterControl;
class IVADCControlCollection;

///
/// 属性页控制变量属性
///
class IATKOBJECT_API IVADCControl : public IClassInfo
{
public:
    IVADCControl(const IVADCControl&) = delete;
    IVADCControl& operator=(const IVADCControl&) = delete;

	IVADCControl(CAsShooterControl* pctrls, CMCSSegment* pMCSSegment, IVADCControlCollection* pIDCCtrlColl);
	~IVADCControl();

	//********************************************************************
	/// 设置累计校正量属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dCorrection 累计校正量
	/// @Return	
	//********************************************************************
	void SetCorrection(double dCorrection);
	//********************************************************************
	/// 获得累计校正量属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	累计校正量
	//********************************************************************
	double GetCorrection();

	////********************************************************************
	///// 设置显示的单位属性值
	///// @Author	Dong Min
	///// @Date	2023-11-3
	///// @Input
	///// @Param	strCDUnit 显示的单位
	///// @Return	
	////********************************************************************
	//void SetCustomDisplayUnit(std::string strCDUnit);
	////********************************************************************
	///// 获得显示的单位属性值
	///// @Author	Dong Min
	///// @Date	2023-11-3
	///// @Return	显示的单位
	////********************************************************************
	//std::string GetCustomDisplayUnit() { return m_CustomDisplayUnit; }

	//********************************************************************
	/// 获得单位类型属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	单位类型
	//********************************************************************
	std::string GetDimension();

	//********************************************************************
	/// 设置是否应用（true为应用）属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	bEnable 是否应用属性值
	/// @Return	
	//********************************************************************
	void SetEnable(bool bEnable);
	//********************************************************************
	/// 获得是否应用属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	是否应用属性值
	//********************************************************************
	bool GetEnable();

	//********************************************************************
	/// 获得最终值属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	最终值
	//********************************************************************
	double GetFinalValue();

	//********************************************************************
	/// 获得初始值属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	初始值
	//********************************************************************
	double GetInitialValue();

	//********************************************************************
	/// 设置最大步长属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dMaxStep 最大步长
	/// @Return	
	//********************************************************************
	void SetMaxStep(double dMaxStep);
	//********************************************************************
	/// 获得最大步长属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	最大步长
	//********************************************************************
	double GetMaxStep();

	//********************************************************************
	/// 获得控制变量名称属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	控制变量名称
	//********************************************************************
	std::string GetName();

	//********************************************************************
	/// 获得段名属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	段名
	//********************************************************************
	std::string GetParentName();

	//********************************************************************
	/// 设置摄动量属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dPerturbation 摄动量
	/// @Return	
	//********************************************************************
	void SetPerturbation(double dPerturbation);
	//********************************************************************
	/// 获得摄动量属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	摄动量
	//********************************************************************
	double GetPerturbation();

	//********************************************************************
	/// 设置归一化方式
	/// @Author	Dong Min
	/// @Date	2025-12-26
	/// @Input
	/// @Param	dScaleMethod 归一化方式
	/// @Return	
	//********************************************************************
	void SetScalingMethod(EVADCScalingMethod eScaleMethod);
	//********************************************************************
	/// 获得归一化方式属性值
	/// @Author	Dong Min
	/// @Date	2025-12-26
	/// @Return	归一化方式
	//********************************************************************
	EVADCScalingMethod GetScalingMethod();

	//********************************************************************
	/// 设置归一化参数属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dScale 归一化参数
	/// @Return	
	//********************************************************************
	void SetScalingValue(double dScale);
	//********************************************************************
	/// 获得归一化参数属性值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	归一化参数
	//********************************************************************
	double GetScalingValue();

private:
	CAsShooterControl*                           m_pctrls;
	CMCSSegment*                                 m_pMCSSegment;
	IVADCControlCollection*                      m_pIDCCtrlColl;

	static void HandleDCControl(IVADCControl* self, const AsTEvent& event_);
};
