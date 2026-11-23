#pragma once
#include "../IAtkObj.h"
#include "ICvBounds.h"
class CCoverageDefinition;

///
/// 纬度线
///
class IATKOBJECT_API ICvBoundsLonLine :public ICvBounds
{
public:
    ICvBoundsLonLine(const ICvBoundsLonLine&) = delete;
    ICvBoundsLonLine& operator=(const ICvBoundsLonLine&) = delete;

	ICvBoundsLonLine(CCoverageDefinition* pCCoverageDefinition);
	~ICvBoundsLonLine();

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
	/// 设置 经度
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @param[in]	longitude 新值
	//********************************************************************
	void SetLongitude(double longitude);
	
	//********************************************************************
	/// 获取 最大纬度
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @return	 最大纬度
	//********************************************************************
	double GetMinLatitude();

	//********************************************************************
	/// 获取 最小纬度
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @return	 最小纬度
	//********************************************************************
	double GetMaxLatitude();

	//********************************************************************
	/// 获取 经度
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @return	 经度
	//********************************************************************
	double GetLongitude();

private:
	CCoverageDefinition* m_pCCoverageDefinition;
};
