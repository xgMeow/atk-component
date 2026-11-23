#pragma once
#include "../IAtkObj.h"
#include "../IClassInfo.h" 
#include "../ICEnum.h"
struct CCRFilter;

///
/// 滤波器
///
class IATKOBJECT_API IRFFilterModel :public IClassInfo
{
public:
    IRFFilterModel(const IRFFilterModel&) = delete;
    IRFFilterModel& operator=(const IRFFilterModel&) = delete;

	IRFFilterModel(CCRFilter* pCCRFilter);
	virtual ~IRFFilterModel();

	//********************************************************************
	/// 获得 滤波器名称
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	滤波器名称
	//********************************************************************
	std::string GetName() { return ""; }

	//********************************************************************
	/// 获得 滤波器类型
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	滤波器类型
	//********************************************************************
	ERFFilterModelType GetType() { return eRFFilterModelTypeUnknown; }

	//********************************************************************
	/// 设置  高频段截至频率
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @param[in]	dUpperBandwidthLimit 高频段截至频率
	//********************************************************************
	void SetUpperBandwidthLimit	(double dUpperBandwidthLimit);

	//********************************************************************
	/// 获得 高频段截至频率
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	高频段截至频率
	//********************************************************************
	double GetUpperBandwidthLimit();

	//********************************************************************
	/// 设置  低频段截至频率
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @param[in]	dLowerBandwidthLimit 低频段截至频率
	//********************************************************************
	void SetLowerBandwidthLimit(double dLowerBandwidthLimit);

	//********************************************************************
	/// 获得 低频段截至频率
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	低频段截至频率
	//********************************************************************
	double GetLowerBandwidthLimit();

	//********************************************************************
	/// 设置  带宽
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @param[in]	dBandwidth 带宽
	//********************************************************************
	void SetBandwidth(double dBandwidth);

	//********************************************************************
	/// 获得 带宽
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	带宽
	//********************************************************************
	double GetBandwidth();

	//********************************************************************
	/// 设置 插入损耗
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @param[in]	dInsertionLoss 插入损耗
	//********************************************************************
	void SetInsertionLoss(double dInsertionLoss);

	//********************************************************************
	/// 获得 插入损耗
	/// @author	Gan Shu Long
	/// @date	2026-03-11
	/// @return	插入损耗
	//********************************************************************
	double GetInsertionLoss();

private:
	CCRFilter*			 m_pCCRFilter;		//滤波器结构体
};
