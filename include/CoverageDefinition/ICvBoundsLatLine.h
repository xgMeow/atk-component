#pragma once
#include "../IAtkObj.h"
#include "ICvBounds.h"
class CCoverageDefinition;

///
/// 纬度线
///
class IATKOBJECT_API ICvBoundsLatLine :public ICvBounds
{
public:
    ICvBoundsLatLine(const ICvBoundsLatLine&) = delete;
    ICvBoundsLatLine& operator=(const ICvBoundsLatLine&) = delete;

	ICvBoundsLatLine(CCoverageDefinition* pCCoverageDefinition);
	~ICvBoundsLatLine();

	//********************************************************************
	/// 设置 纬度
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @param[in]	latitude 新值
	//********************************************************************
	void SetLatitude(double latitude);

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
	/// 获取 纬度
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @return	 纬度
	//********************************************************************
	double GetLatitude();

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
