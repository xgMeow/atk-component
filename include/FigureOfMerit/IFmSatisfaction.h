#pragma once
#include "../IAtkObj.h" 
#include "../ICEnum.h"
struct AsCvFmDefn;

///
/// 品质因子有效条件
///
class IATKOBJECT_API IFmSatisfaction
{
public:
    IFmSatisfaction(const IFmSatisfaction&) = delete;
    IFmSatisfaction& operator=(const IFmSatisfaction&) = delete;

	IFmSatisfaction(AsCvFmDefn* pAsCvFmDefn);
	~IFmSatisfaction();
	
	//********************************************************************
	/// 设置 是否使用有效条件
	/// @author	Gan Shu Long
	/// @date	2026-05-07
	/// @param[in]	bEnableSatisfaction  是否使用有效条件
	//********************************************************************
	void SetEnableSatisfaction(bool bEnableSatisfaction);

	//********************************************************************
	/// 获得 是否使用有效条件
	/// @author	Gan Shu Long
	/// @date	2026-05-07
	/// @return	是否使用有效条件
	//********************************************************************
	bool GetEnableSatisfaction();

	//********************************************************************
	/// 设置 有效条件类型
	/// @author	Gan Shu Long
	/// @date	2026-05-07
	/// @param[in]	eFmSatisfactionType  有效条件类型
	//********************************************************************
	void SetSatisfactionType(EFmSatisfactionType eFmSatisfactionType);

	//********************************************************************
	/// 获得 有效条件类型
	/// @author	Gan Shu Long
	/// @date	2026-05-07
	/// @return	有效条件类型
	//********************************************************************
	EFmSatisfactionType GetSatisfactionType();

	//********************************************************************
	/// 设置  阈值
	/// @author	Gan Shu Long
	/// @date	2026-05-07
	/// @param[in]	dSatisfactionThreshold 阈值
	//********************************************************************
	void SetSatisfactionThreshold(double dSatisfactionThreshold);

	//********************************************************************
	/// 获得 阈值
	/// @author	Gan Shu Long
	/// @date	2026-05-07
	/// @return	阈值
	//********************************************************************
	double GetSatisfactionThreshold();

	//********************************************************************
	/// 设置  无效数据指标
	/// @author	Gan Shu Long
	/// @date	2026-05-07
	/// @param[in]	dInvalidDataIndicator 无效数据指标
	//********************************************************************
	void SetInvalidDataIndicator(double dInvalidDataIndicator);

	//********************************************************************
	/// 获得 无效数据指标
	/// @author	Gan Shu Long
	/// @date	2026-05-07
	/// @return	无效数据指标
	//********************************************************************
	double GetInvalidDataIndicator();

	//********************************************************************
	/// 设置 是否使用范围内的值
	/// @author	Gan Shu Long
	/// @date	2026-05-07
	/// @param[in]	bUseValueRangeCheck  是否使用范围内的值
	//********************************************************************
	void SetUseValueRangeCheck(bool bUseValueRangeCheck);

	//********************************************************************
	/// 获得 是否使用范围内的值
	/// @author	Gan Shu Long
	/// @date	2026-05-07
	/// @return	是否使用范围内的值
	//********************************************************************
	bool GetUseValueRangeCheck();

	//********************************************************************
	/// 设置  最小值
	/// @author	Gan Shu Long
	/// @date	2026-05-07
	/// @param[in]	dMinValueRange 最小值
	//********************************************************************
	void SetMinValueRange(double dMinValueRange);

	//********************************************************************
	/// 获得 最小值
	/// @author	Gan Shu Long
	/// @date	2026-05-07
	/// @return	最小值
	//********************************************************************
	double GetMinValueRange();

	//********************************************************************
	/// 设置  最大值
	/// @author	Gan Shu Long
	/// @date	2026-05-07
	/// @param[in]	dMaxValueRange 最大值
	//********************************************************************
	void SetMaxValueRange(double dMaxValueRange);

	//********************************************************************
	/// 获得 最大值
	/// @author	Gan Shu Long
	/// @date	2026-05-07
	/// @return	最大值
	//********************************************************************
	double GetMaxValueRange();

	//********************************************************************
	/// 设置 是否使用反向选择
	/// @author	Gan Shu Long
	/// @date	2026-05-07
	/// @param[in]	bExcludeValueRange  是否使用反向选择
	//********************************************************************
	void SetExcludeValueRange(bool bExcludeValueRange);

	//********************************************************************
	/// 获得 是否使用反向选择
	/// @author	Gan Shu Long
	/// @date	2026-05-07
	/// @return	是否使用反向选择
	//********************************************************************
	bool GetExcludeValueRange();

private:
	AsCvFmDefn*		m_pAsCvFmDefn;
};
