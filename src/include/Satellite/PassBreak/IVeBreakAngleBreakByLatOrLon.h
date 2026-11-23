#pragma once
#include "IVeBreakAngle.h"
class CSatellite;

///
/// 轨道圈数定义纬度
///
class IATKOBJECT_API IVeBreakAngleBreakByLatitude : public IVeBreakAngle
{
public:
    IVeBreakAngleBreakByLatitude(const IVeBreakAngleBreakByLatitude&) = delete;
    IVeBreakAngleBreakByLatitude& operator=(const IVeBreakAngleBreakByLatitude&) = delete;

	IVeBreakAngleBreakByLatitude(CSatellite* pSate);
	~IVeBreakAngleBreakByLatitude();

	//********************************************************************
	/// 设置纬度
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dLat 纬度
	//********************************************************************
	void SetLatitude(double dLat);
	//********************************************************************
	/// 获得纬度
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	纬度
	//********************************************************************
	double GetLatitude();

private:
	CSatellite* m_pSate;

};

///
/// 轨道圈数定义经度
///
class IATKOBJECT_API IVeBreakAngleBreakByLongitude : public IVeBreakAngle
{
public:
	IVeBreakAngleBreakByLongitude(const IVeBreakAngleBreakByLongitude&) = delete;
	IVeBreakAngleBreakByLongitude& operator=(const IVeBreakAngleBreakByLongitude&) = delete;

	IVeBreakAngleBreakByLongitude(CSatellite* pSate);
	~IVeBreakAngleBreakByLongitude();

	//********************************************************************
	/// 设置经度
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dLon 经度
	//********************************************************************
	void SetLongitude(double dLon);
	//********************************************************************
	/// 获得经度
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	经度
	//********************************************************************
	double GetLongitude();

private:
	CSatellite* m_pSate;
};
