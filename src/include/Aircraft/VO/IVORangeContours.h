#pragma once
#include "../../IAtkObj.h"
struct CObjData;
struct CGfxRange;

///
/// 二维范围
///
class IATKOBJECT_API IVORangeContours
{
public:
    IVORangeContours(const IVORangeContours&) = delete;
    IVORangeContours& operator=(const IVORangeContours&) = delete;

	IVORangeContours(CGfxRange* pCGfxRange);
	~IVORangeContours();

	//********************************************************************
	/// 设置是否显示
	/// @author	Gan Shu Long
	/// @date	2026-01-09
	/// @param[in]	bIsVisible  是否显示
	//********************************************************************
	void SetIsVisible(bool bIsVisible);

	//********************************************************************
	/// 获得是否显示
	/// @author	Gan Shu Long
	/// @date	2026-01-09
	/// @return	是否显示
	//********************************************************************
	bool GetIsVisible();

	//********************************************************************
	/// 设置是否显示半透明线条
	/// @author	Gan Shu Long
	/// @date	2026-01-09
	/// @param[in]	bTranslucentLines  是否显示半透明线条
	//********************************************************************
	void SetTranslucentLines(bool bTranslucentLines);

	//********************************************************************
	/// 获得是否显示半透明线条
	/// @author	Gan Shu Long
	/// @date	2026-01-09
	/// @return	是否显示半透明线条
	//********************************************************************
	bool GetTranslucentLines();

	//********************************************************************
	/// 设置填充透明度
	/// @author	Gan Shu Long
	/// @date	2026-01-09
	/// @param[in]	dPercentTranslucency  填充透明度
	//********************************************************************
	void SetPercentTranslucency(double dPercentTranslucency);

	//********************************************************************
	/// 获得填充透明度
	/// @author	Gan Shu Long
	/// @date	2026-01-09
	/// @return	填充透明度
	//********************************************************************
	double GetPercentTranslucency();

private:
	CGfxRange*							m_pCGfxRange;			//C对象范围指针
};

