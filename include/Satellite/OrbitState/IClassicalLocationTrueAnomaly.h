#pragma once
#include "IClassicalLocation.h"
class CSatellite;

///
/// 轨道根数真近点角
///
class IATKOBJECT_API IClassicalLocationTrueAnomaly : public IClassicalLocation
{
public:
    IClassicalLocationTrueAnomaly(const IClassicalLocationTrueAnomaly&) = delete;
    IClassicalLocationTrueAnomaly& operator=(const IClassicalLocationTrueAnomaly&) = delete;

	IClassicalLocationTrueAnomaly(CSatellite* pSate);
	~IClassicalLocationTrueAnomaly();

	//********************************************************************
	/// 设置真近点角
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dTrueAno 真近点角
	//********************************************************************
	void SetValue(double dTrueAno);
	//********************************************************************
	/// 获得真近点角
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	真近点角
	//********************************************************************
	double GetValue();

private:
	CSatellite*     m_pSate;

};
