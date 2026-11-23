#pragma once
#include <string>
#include "../../../IAtkObj.h"
#include "../../../IClassInfo.h"
#include "../../../ICEnum.h"
class CMCSSegment;
class CAsStateCalc;
class IVADCResultCollection;

///
/// 属性页约束属性
///
class IATKOBJECT_API IVADCResult : public IClassInfo
{
public:
    IVADCResult(const IVADCResult&) = delete;
    IVADCResult& operator=(const IVADCResult&) = delete;

	IVADCResult(CAsStateCalc* pcResults, CMCSSegment* pMCSSegment, IVADCResultCollection* pIResColl);
	~IVADCResult();

	//********************************************************************
	/// 获得当前值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	当前值
	//********************************************************************
	double GetCurrentValue();

	//********************************************************************
	/// 获得误差值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	误差值
	//********************************************************************
	double GetDifferenceValue();

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
	/// 设置期望值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dDesiredValue 期望值
	/// @Return	
	//********************************************************************
	void SetDesiredValue(double dDesiredValue);
	//********************************************************************
	/// 获得期望值
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	期望值
	//********************************************************************
	double GetDesiredValue();

	//********************************************************************
	/// 获得单位类型
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
	/// 获得约束名称
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	约束名称
	//********************************************************************
	std::string GetName();

	//********************************************************************
	/// 获得段名
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	段名
	//********************************************************************
	std::string GetParentName();
	 
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
	/// 设置归一化参数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dScale 归一化参数
	/// @Return	
	//********************************************************************
	void SetScalingValue(double dScale);
	//********************************************************************
	/// 获得归一化参数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	归一化参数
	//********************************************************************
	double GetScalingValue();

	//********************************************************************
	/// 设置收敛误差
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dTolerance 收敛误差
	/// @Return	
	//********************************************************************
	void SetTolerance(double dTolerance);
	//********************************************************************
	/// 获得收敛误差
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	收敛误差
	//********************************************************************
	double GetTolerance();

	//********************************************************************
	/// 设置权重系数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dWeight 权重系数
	/// @Return	
	//********************************************************************
	void SetWeight(double dWeight);
	//********************************************************************
	/// 获得权重系数
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	权重系数
	//********************************************************************
	double GetWeight();

	//********************************************************************
	/// 对象参数设置界面
	/// @Author	Dong Min
	/// @Date	2025-12-09
	/// @Input
	/// @Param	strObjPath   属性设置路径
	/// @Param	strValue   属性值
	/// @Return	
	//********************************************************************
	virtual bool	SetUiParameter() override;

private:
	CAsStateCalc*                          m_pcResults;
	CMCSSegment*                           m_pMCSSegment;
	IVADCResultCollection*                 m_pIResColl;

	static void HandleDCResult(IVADCResult* self, const AsTEvent& event_);
};
