#pragma once
#include "../IAtkObj.h"
#include "IRFFilterModel.h" 
#include "../ICEnum.h"
struct CCRFilter;

///
/// 滤波器 Butterworth
///
class IATKOBJECT_API IRFFilterModelButterworth :public IRFFilterModel
{
public:
    IRFFilterModelButterworth(const IRFFilterModelButterworth&) = delete;
    IRFFilterModelButterworth& operator=(const IRFFilterModelButterworth&) = delete;

	IRFFilterModelButterworth(CCRFilter* pCCRFilter);
	virtual ~IRFFilterModelButterworth();

	//********************************************************************
	/// 获得 滤波器名称
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	滤波器名称
	//********************************************************************
	std::string GetName() { return "Butterworth"; }

	//********************************************************************
	/// 获得 滤波器类型
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	滤波器类型
	//********************************************************************
	ERFFilterModelType GetType() { return eRFFilterModelTypeButterworth; }

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
	/// 设置  截至频率
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @param[in]	dCutoffFrequency 截至频率
	//********************************************************************
	void SetCutoffFrequency(double dCutoffFrequency);

	//********************************************************************
	/// 获得 截至频率
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	截至频率
	//********************************************************************
	double GetCutoffFrequency();

private:
	CCRFilter*			 m_pCCRFilter;		//滤波器结构体
};
