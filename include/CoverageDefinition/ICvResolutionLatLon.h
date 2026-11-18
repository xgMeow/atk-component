#pragma once
#include "../IAtkObj.h"
#include "ICvResolution.h"
class CCoverageDefinition;

///
/// 网格定义：经纬度
///
class IATKOBJECT_API ICvResolutionLatLon :public ICvResolution
{
public:
    ICvResolutionLatLon(const ICvResolutionLatLon&) = delete;
    ICvResolutionLatLon& operator=(const ICvResolutionLatLon&) = delete;

	ICvResolutionLatLon(CCoverageDefinition* pCCoverageDefinition);
	~ICvResolutionLatLon();

	//********************************************************************
	/// 设置 经纬度网格分辨率
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @param[in]	latLon 新值
	//********************************************************************
	void SetLatLon(double latLon);
	
	//********************************************************************
	/// 获取 经纬度网格分辨率
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @return	 经纬度网格分辨率
	//********************************************************************
	double GetLatLon();

private:
	CCoverageDefinition* m_pCCoverageDefinition;
};
