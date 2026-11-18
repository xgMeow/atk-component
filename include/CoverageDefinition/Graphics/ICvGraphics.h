#pragma once
#include "../../IAtkObj.h"
class CCoverageDefinition;

///
/// 二维
///
class IATKOBJECT_API ICvGraphics
{
public:
    ICvGraphics(const ICvGraphics&) = delete;
    ICvGraphics& operator=(const ICvGraphics&) = delete;

	ICvGraphics(CCoverageDefinition* pCCoverageDefinition);
	~ICvGraphics();

	//********************************************************************
	/// 设置对象是否在二维显示
	/// @author	Gan Shu Long
	/// @date	2024-06-12
	/// @param[in]	bIsObjectGraphicsVisible  是否显示
	//********************************************************************
	void SetIsObjectGraphicsVisible(bool bIsObjectGraphicsVisible);

	//********************************************************************
	/// 获得对象是否在二维显示
	/// @author	Gan Shu Long
	/// @date	2024-06-12
	/// @return	true-显示
	//********************************************************************
	bool GetIsObjectGraphicsVisible();

	//********************************************************************
	/// 设置是否显示区域
	/// @author	Gan Shu Long
	/// @date	2024-06-11
	/// @param[in]	bIsRegionVisible  是否显示区域
	//********************************************************************
	void SetIsRegionVisible(bool bIsRegionVisible);

	//********************************************************************
	/// 获得是否显示区域
	/// @author	Gan Shu Long
	/// @date	2024-06-11
	/// @return	是否显示区域
	//********************************************************************
	bool GetIsRegionVisible();

	//********************************************************************
	/// 设置是否显示点
	/// @author	Gan Shu Long
	/// @date	2024-06-11
	/// @param[in]	bIsPointsVisible  是否显示点
	//********************************************************************
	void SetIsPointsVisible(bool bIsPointsVisible);

	//********************************************************************
	/// 获得是否显示点
	/// @author	Gan Shu Long
	/// @date	2024-06-11
	/// @return	是否显示点
	//********************************************************************
	bool GetIsPointsVisible();

	//********************************************************************
	/// 设置二维显示颜色
	/// @author	Gan Shu Long
	/// @date	2024-06-11
	/// @param[in]	nColor  二维显示颜色，例绿色-65280
	//********************************************************************
	void SetColor(int nColor);

	//********************************************************************
	/// 获得二维显示颜色
	/// @author	Gan Shu Long
	/// @date	2024-06-11
	/// @return	二维显示颜色
	//********************************************************************
	int GetColor();

	//********************************************************************
	/// 设置点大小
	/// @author	Gan Shu Long
	/// @date	2024-06-11
	/// @param[in]	dPointSize  点大小
	//********************************************************************
	void SetPointSize(double dPointSize);

	//********************************************************************
	/// 获得点大小
	/// @author	Gan Shu Long
	/// @date	2024-06-11
	/// @return	点大小
	//********************************************************************
	double GetPointSize();

	//********************************************************************
	/// 设置是否填充
	/// @author	Gan Shu Long
	/// @date	2024-06-11
	/// @param[in]	bFillPoints  是否填充
	//********************************************************************
	void SetFillPoints(bool bFillPoints);

	//********************************************************************
	/// 获得是否填充
	/// @author	Gan Shu Long
	/// @date	2024-06-11
	/// @return	是否填充
	//********************************************************************
	bool GetFillPoints();

private:
	CCoverageDefinition*	m_pCCoverageDefinition;
};

