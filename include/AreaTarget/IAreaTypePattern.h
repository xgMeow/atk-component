#pragma once
#include "../IAtkObj.h"
class CLatLonAlt;

///
/// 区域边界坐标
///
class IATKOBJECT_API IAreaTypePattern
{
public:
    IAreaTypePattern(const IAreaTypePattern&) = delete;
    IAreaTypePattern& operator=(const IAreaTypePattern&) = delete;

	IAreaTypePattern(CLatLonAlt* pCLatLonAlt);
	~IAreaTypePattern();

	//********************************************************************
	/// 设置维度
	/// @author	Gan Shu Long
	/// @date	2026-01-16
	/// @param[in]	dLat 维度
	//********************************************************************
	void SetLat(double dLat);

	//********************************************************************
	/// 获取维度
	/// @author	Gan Shu Long
	/// @date	2026-01-16
	/// @return 维度
	//********************************************************************
	double GetLat();

	//********************************************************************
	/// 设置经度
	/// @author	Gan Shu Long
	/// @date	2026-01-16
	/// @param[in]	dLon 经度
	//********************************************************************
	void SetLon(double dLon);

	//********************************************************************
	/// 获取经度
	/// @author	Gan Shu Long
	/// @date	2026-01-16
	/// @return 经度
	//********************************************************************
	double GetLon();

private:
	CLatLonAlt*		m_pCLatLonAlt;
};
