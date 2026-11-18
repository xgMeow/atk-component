#pragma once
#include "../../IAtkObj.h"
#include "IVeLaunch.h"
class CLatLonAl;

///
/// 纬经高发射点
///
class IATKOBJECT_API IVeLaunchLLA : public IVeLaunch
{
public:
    IVeLaunchLLA(const IVeLaunchLLA&) = delete;
    IVeLaunchLLA& operator=(const IVeLaunchLLA&) = delete;

	IVeLaunchLLA(CLatLonAlt* pCLatLonAlt);
	~IVeLaunchLLA();

	//********************************************************************
	/// 获得纬度
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @return	纬度
	//********************************************************************
	double GetLat();

	//********************************************************************
	/// 设置纬度
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @param[in]	dLat 纬度
	//********************************************************************
	void SetLat(double dLat);

	//********************************************************************
	/// 获得经度
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @return	经度
	//********************************************************************
	double GetLon();

	//********************************************************************
	/// 设置经度
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @param[in]	dLon 经度
	//********************************************************************
	void SetLon(double dLon);

	//********************************************************************
	/// 获得高度
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @return	高度
	//********************************************************************
	double GetAlt();

	//********************************************************************
	/// 设置高度
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @param[in]	dAlt 高度
	//********************************************************************
	void SetAlt(double dAlt);

private:
	CLatLonAlt*			m_pCLatLonAlt;
};
