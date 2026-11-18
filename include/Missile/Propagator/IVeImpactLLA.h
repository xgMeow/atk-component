#pragma once
#include "../../IAtkObj.h"
#include "IVeImpact.h"
class CLatLonAl;

///
/// 纬经高落点
///
class IATKOBJECT_API IVeImpactLLA : public IVeImpact
{
public:
    IVeImpactLLA(const IVeImpactLLA&) = delete;
    IVeImpactLLA& operator=(const IVeImpactLLA&) = delete;

	IVeImpactLLA(CLatLonAlt* pCLatLonAlt);
	~IVeImpactLLA();

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
