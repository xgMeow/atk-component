#pragma once
#include "IClassicalLocation.h"
class CSatellite;

///
/// 轨道根数平近点角
///
class IATKOBJECT_API IClassicalLocationMeanAnomaly : public IClassicalLocation
{
public:
    IClassicalLocationMeanAnomaly(const IClassicalLocationMeanAnomaly&) = delete;
    IClassicalLocationMeanAnomaly& operator=(const IClassicalLocationMeanAnomaly&) = delete;

	IClassicalLocationMeanAnomaly(CSatellite* pSate);
	~IClassicalLocationMeanAnomaly();

	//********************************************************************
	/// 设置平近点角
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dMeanAno 平近点角
	//********************************************************************
	void SetValue(double dMeanAno);
	//********************************************************************
	/// 获得平近点角
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	平近点角
	//********************************************************************
	double GetValue();

public:
	CSatellite*     m_pSate;
};
