#pragma once
#include "../IAtkObj.h"
#include "ICvResolution.h"
class CCoverageDefinition;

///
/// 网格定义：距离
///
class IATKOBJECT_API ICvResolutionDistance :public ICvResolution
{
public:
    ICvResolutionDistance(const ICvResolutionDistance&) = delete;
    ICvResolutionDistance& operator=(const ICvResolutionDistance&) = delete;

	ICvResolutionDistance(CCoverageDefinition* pCCoverageDefinition);
	~ICvResolutionDistance();

	//********************************************************************
	/// 设置 距离网格分辨率
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @param[in]	distance 新值
	//********************************************************************
	void SetDistance(double distance);
	
	//********************************************************************
	/// 获取 距离网格分辨率
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @return	 距离网格分辨率
	//********************************************************************
	double GetDistance();

private:
	CCoverageDefinition* m_pCCoverageDefinition;
};
