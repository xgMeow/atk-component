#pragma once
#include "../IAtkObj.h"
#include "ICvBounds.h"
class CCoverageDefinition;

///
/// 经纬度区域
///
class IATKOBJECT_API ICvBoundsLatLonRegion :public ICvBounds
{
public:
    ICvBoundsLatLonRegion(const ICvBoundsLatLonRegion&) = delete;
    ICvBoundsLatLonRegion& operator=(const ICvBoundsLatLonRegion&) = delete;

	ICvBoundsLatLonRegion(CCoverageDefinition* pCCoverageDefinition);
	~ICvBoundsLatLonRegion();

	//********************************************************************
	/// 设置 最小纬度
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @param[in]	minLatitude 新值
	//********************************************************************
	void SetMinLatitude(double minLatitude);

	//********************************************************************
	/// 设置 最大纬度
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @param[in]	maxLatitude 新值
	//********************************************************************
	void SetMaxLatitude(double maxLatitude);

	//********************************************************************
	/// 设置 最小经度
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @param[in]	minLongitude 新值
	//********************************************************************
	void SetMinLongitude(double minLongitude);

	//********************************************************************
	/// 设置 最大经度
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @param[in]	maxLongitude 新值
	//********************************************************************
	void SetMaxLongitude(double maxLongitude);

	//********************************************************************
	/// 获取 最小纬度
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @return	 最小纬度
	//********************************************************************
	double GetMinLatitude();

	//********************************************************************
	/// 获取 最大纬度
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @return	 最大纬度
	//********************************************************************
	double GetMaxLatitude();

	//********************************************************************
	/// 获取 最小经度
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @return	 最小经度
	//********************************************************************
	double GetMinLongitude();

	//********************************************************************
	/// 获取 最大经度
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @return	 最大经度
	//********************************************************************
	double GetMaxLongitude();

private:
	CCoverageDefinition* m_pCCoverageDefinition;
};
