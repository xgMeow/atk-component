#pragma once
#include "ISnPattern.h"
class CSensor;

///
/// 模式类型：半功率
///
class IATKOBJECT_API ISnHalfPowerPattern : public ISnPattern
{
public:
    ISnHalfPowerPattern(const ISnHalfPowerPattern&) = delete;
    ISnHalfPowerPattern& operator=(const ISnHalfPowerPattern&) = delete;

	ISnHalfPowerPattern(CSensor* pCSensor);
	~ISnHalfPowerPattern();

	//********************************************************************
	/// 设置 频率
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @param[in]	dFrequency  频率
	//********************************************************************
	void SetFrequency(double dFrequency);

	//********************************************************************
	/// 获得 频率
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @return	double 频率	
	//********************************************************************
	double GetFrequency();

	//********************************************************************
	/// 设置 直径
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @param[in]	dAntennaDiameter  直径
	//********************************************************************
	void SetAntennaDiameter(double dAntennaDiameter);

	//********************************************************************
	/// 获得 直径
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @return	double 直径
	//********************************************************************
	double GetAntennaDiameter();

private:
	CSensor*			m_pCSensor;
};

