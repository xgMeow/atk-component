#pragma once
#include "ISnPattern.h"
class CSensor;

///
/// 模式类型：复杂圆锥
///
class IATKOBJECT_API ISnComplexConicPattern : public ISnPattern
{
public:
    ISnComplexConicPattern(const ISnComplexConicPattern&) = delete;
    ISnComplexConicPattern& operator=(const ISnComplexConicPattern&) = delete;

	ISnComplexConicPattern(CSensor* pCSensor);
	~ISnComplexConicPattern();

	//********************************************************************
	/// 设置 半锥角内部
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @param[in]	dInnerConeHalfAngle  半锥角内部
	//********************************************************************
	void SetInnerConeHalfAngle(double dInnerConeHalfAngle);

	//********************************************************************
	/// 获得 半锥角内部
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @return	半锥角内部	
	//********************************************************************
	double GetInnerConeHalfAngle();

	//********************************************************************
	/// 设置 半锥角外部
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @param[in]	dOuterConeHalfAngle  半锥角外部
	//********************************************************************
	void SetOuterConeHalfAngle(double dOuterConeHalfAngle);

	//********************************************************************
	/// 获得 半锥角外部
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @return	半锥角外部	
	//********************************************************************
	double GetOuterConeHalfAngle();

	//********************************************************************
	/// 设置 钟角最小值
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @param[in]	dMinimumClockAngle  钟角最小值
	//********************************************************************
	void SetMinimumClockAngle(double dMinimumClockAngle);

	//********************************************************************
	/// 获得 钟角最小值
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @return	钟角最小值	
	//********************************************************************
	double GetMinimumClockAngle();

	//********************************************************************
	/// 设置 钟角最大值
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @param[in]	dMaximumClockAngle  钟角最大值
	//********************************************************************
	void SetMaximumClockAngle(double dMaximumClockAngle);

	//********************************************************************
	/// 获得 钟角最大值
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @return	钟角最大值	
	//********************************************************************
	double GetMaximumClockAngle();

private:
	CSensor*			m_pCSensor;
};

