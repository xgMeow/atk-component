#pragma once
#include "../IAtkObj.h"
#include "ICvBounds.h"
class CCoverageDefinition;

///
/// 纬度边界
///
class IATKOBJECT_API ICvBoundsLat :public ICvBounds
{
public:
    ICvBoundsLat(const ICvBoundsLat&) = delete;
    ICvBoundsLat& operator=(const ICvBoundsLat&) = delete;

	ICvBoundsLat(CCoverageDefinition* pCCoverageDefinition);
	~ICvBoundsLat();

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
	/// @return	最大纬度
	//********************************************************************
	double GetMaxLatitude();
	
private:
	CCoverageDefinition* m_pCCoverageDefinition;

};
