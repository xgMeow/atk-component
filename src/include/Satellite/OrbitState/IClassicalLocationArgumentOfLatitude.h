#pragma once
#include "IClassicalLocation.h"
class CSatellite;

///
/// 轨道根数纬度辐角
///
class IATKOBJECT_API IClassicalLocationArgumentOfLatitude : public IClassicalLocation
{
public:
    IClassicalLocationArgumentOfLatitude(const IClassicalLocationArgumentOfLatitude&) = delete;
    IClassicalLocationArgumentOfLatitude& operator=(const IClassicalLocationArgumentOfLatitude&) = delete;

	IClassicalLocationArgumentOfLatitude(CSatellite* pSate);
	~IClassicalLocationArgumentOfLatitude();

	//********************************************************************
	/// 设置纬度辐角
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dArgOfLat 纬度辐角
	//********************************************************************
	void SetValue(double dArgOfLat);
	//********************************************************************
	/// 获得纬度辐角
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	纬度辐角
	//********************************************************************
	double GetValue();

private:
	CSatellite*     m_pSate;

};
