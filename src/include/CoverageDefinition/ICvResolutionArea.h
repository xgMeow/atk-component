#pragma once
#include "../IAtkObj.h"
#include "ICvResolution.h"
class CCoverageDefinition;

///
/// 网格定义：面积
///
class IATKOBJECT_API ICvResolutionArea :public ICvResolution
{
public:
    ICvResolutionArea(const ICvResolutionArea&) = delete;
    ICvResolutionArea& operator=(const ICvResolutionArea&) = delete;

	ICvResolutionArea(CCoverageDefinition* pCCoverageDefinition);
	~ICvResolutionArea();

	//********************************************************************
	/// 设置 面积网格分辨率
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @param[in]	area 新值
	//********************************************************************
	void SetArea(double area);

	//********************************************************************
	/// 获取 面积网格分辨率
	/// @author	Gan Shu Long
	/// @date	2023-12-11
	/// @return	 面积网格分辨率
	//********************************************************************
	double GetArea();

private:
	CCoverageDefinition* m_pCCoverageDefinition;
};
