#pragma once
#include "IClassicalSizeShape.h"
class CSatellite;

///
/// 轨道根数周期和偏心率
///
class IATKOBJECT_API IClassicalSizeShapePeriod : public IClassicalSizeShape
{
public:
    IClassicalSizeShapePeriod(const IClassicalSizeShapePeriod&) = delete;
    IClassicalSizeShapePeriod& operator=(const IClassicalSizeShapePeriod&) = delete;

	IClassicalSizeShapePeriod(CSatellite* pSate);
	~IClassicalSizeShapePeriod();

	//********************************************************************
	/// 设置偏心率
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dEcc 偏心率
	//********************************************************************
	void SetEccentricity(double dEcc);
	//********************************************************************
	/// 获得偏心率
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	偏心率
	//********************************************************************
	double GetEccentricity();

	//********************************************************************
	/// 设置周期
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dPeriod 周期
	//********************************************************************
	void SetPeriod(double dPeriod);
	//********************************************************************
	/// 获得周期
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	周期
	//********************************************************************
	double GetPeriod();

private:
	CSatellite* m_pSate;

};
