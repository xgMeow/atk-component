#pragma once
#include "../IAtkObj.h"
#include "IPolarizationHorizontal.h"
struct CCRAntenna;

///
/// 水平极化
///
class IATKOBJECT_API IReceivePolarizationHorizontal :public IPolarizationHorizontal
{
public:
    IReceivePolarizationHorizontal(const IReceivePolarizationHorizontal&) = delete;
    IReceivePolarizationHorizontal& operator=(const IReceivePolarizationHorizontal&) = delete;

	IReceivePolarizationHorizontal(CCRAntenna* pCCRAntenna);
	~IReceivePolarizationHorizontal();

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
