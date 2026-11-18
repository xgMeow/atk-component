#pragma once
#include "../IAtkObj.h"
#include "IRFFilterModel.h" 
#include "../ICEnum.h"
struct CCRFilter;

///
/// 滤波器 GaussianWindows
///
class IATKOBJECT_API IRFFilterModelGaussianWindow :public IRFFilterModel
{
public:
    IRFFilterModelGaussianWindow(const IRFFilterModelGaussianWindow&) = delete;
    IRFFilterModelGaussianWindow& operator=(const IRFFilterModelGaussianWindow&) = delete;

	IRFFilterModelGaussianWindow(CCRFilter* pCCRFilter);
	virtual ~IRFFilterModelGaussianWindow();

	//********************************************************************
	/// 获得 滤波器名称
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	滤波器名称
	//********************************************************************
	std::string GetName() { return "GaussianWindows"; }

	//********************************************************************
	/// 获得 滤波器类型
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	滤波器类型
	//********************************************************************
	ERFFilterModelType GetType() { return eRFFilterModelTypeGaussianWindow; }													

	//********************************************************************
	/// 设置  次数
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @param[in]	iOrder 次数
	//********************************************************************
	void SetOrder(int iOrder);

	//********************************************************************
	/// 获得 次数
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	次数
	//********************************************************************
	int GetOrder();

	//********************************************************************
	/// 设置  采样频率
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @param[in]	dSamplingFrequency 采样频率
	//********************************************************************
	void SetSamplingFrequency(double dSamplingFrequency);

	//********************************************************************
	/// 获得 采样频率
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	采样频率
	//********************************************************************
	double GetSamplingFrequency();

private:
	CCRFilter*			 m_pCCRFilter;		//滤波器结构体
};
