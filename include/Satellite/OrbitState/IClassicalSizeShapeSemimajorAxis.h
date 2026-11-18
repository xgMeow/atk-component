#pragma once
#include "../../IAtkObj.h"
#include "IClassicalSizeShape.h"
class CSatellite;

///
/// 轨道根数半长轴和偏心率
///
class IATKOBJECT_API IClassicalSizeShapeSemimajorAxis : public IClassicalSizeShape
{
public:
    IClassicalSizeShapeSemimajorAxis(const IClassicalSizeShapeSemimajorAxis&) = delete;
    IClassicalSizeShapeSemimajorAxis& operator=(const IClassicalSizeShapeSemimajorAxis&) = delete;

	IClassicalSizeShapeSemimajorAxis(CSatellite* pSate);
	~IClassicalSizeShapeSemimajorAxis();

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
	/// 设置半长轴
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dSma 半长轴
	//********************************************************************
	void SetSemiMajorAxis(double dSma);
	//********************************************************************
	/// 获得半长轴
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	半长轴
	//********************************************************************
	double GetSemiMajorAxis();

private:
	CSatellite* m_pSate;
};
