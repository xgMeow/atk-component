#pragma once
#include "../IAtkObj.h"
#include "IPolarizationLinear.h"
struct CCRAntenna;

///
/// 线极化
///
class IATKOBJECT_API IReceivePolarizationLinear :public IPolarizationLinear
{
public:
    IReceivePolarizationLinear(const IReceivePolarizationLinear&) = delete;
    IReceivePolarizationLinear& operator=(const IReceivePolarizationLinear&) = delete;

	IReceivePolarizationLinear(CCRAntenna* pCCRAntenna);
	~IReceivePolarizationLinear();

	//********************************************************************
	/// 设置  交叉极化泄露阈值
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @param[in]	dCrossPolLeakage 交叉极化泄露阈值
	//********************************************************************
	void SetCrossPolLeakage(double dCrossPolLeakage);
	
	//********************************************************************
	/// 获得 交叉极化泄露阈值
	/// @author	Gan Shu Long
	/// @date	2026-03-10
	/// @return	交叉极化泄露阈值
	//********************************************************************
	double GetCrossPolLeakage();

private:
	CCRAntenna*			 m_pCCRAntenna;		//天线结构体
};
