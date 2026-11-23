#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
class CAreaTarget;

///
/// 二维
///
class IATKOBJECT_API IATGraphics
{
public:
    IATGraphics(const IATGraphics&) = delete;
    IATGraphics& operator=(const IATGraphics&) = delete;

	IATGraphics(CAreaTarget* pCAreaTarget);
	~IATGraphics();
	
	//********************************************************************
	/// 设置是否显示
	/// @author	Gan Shu Long
	/// @date	2026-01-09
	/// @param[in]	bIsObjectGraphicsVisible  是否显示
	//********************************************************************
	void SetIsObjectGraphicsVisible(bool bIsObjectGraphicsVisible);

	//********************************************************************
	/// 获取是否显示
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @return 是否显示
	//********************************************************************
	bool GetIsObjectGraphicsVisible();

	//********************************************************************
	/// 设置颜色
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @param[in]	nColor  颜色
	//********************************************************************
	void SetColor(int nColor);

	//********************************************************************
	/// 获取设置颜色
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @return 颜色
	//********************************************************************
	int GetColor();

	//********************************************************************
	/// 设置线型
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @param[in]	eBoundaryStyle  线型
	//********************************************************************
	void SetBoundaryStyle(ELineStyle eBoundaryStyle);

	//********************************************************************
	/// 获得线型
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @return	线型	
	//********************************************************************
	ELineStyle GetBoundaryStyle();

	//********************************************************************
	/// 设置线宽
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @param[in]	eLineWidth  线宽
	//********************************************************************
	void SetBoundaryWidth(ELineWidth eLineWidth);

	//********************************************************************
	/// 获得线宽
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @return	线宽	
	//********************************************************************
	ELineWidth GetBoundaryWidth();

	//********************************************************************
	/// 设置是否显示标签
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @param[in]	bLabelVisible  是否显示标签
	//********************************************************************
	void SetLabelVisible(bool bLabelVisible);

	//********************************************************************
	/// 获取是否显示标签
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @return 是否显示标签
	//********************************************************************
	bool GetLabelVisible();

	//********************************************************************
	/// 设置是否显示中心点
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @param[in]	bCentroidVisible  是否显示中心点
	//********************************************************************
	void SetCentroidVisible(bool bCentroidVisible);

	//********************************************************************
	/// 获取是否显示中心点
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @return 是否显示中心点
	//********************************************************************
	bool GetCentroidVisible();

	//********************************************************************
	/// 设置是否显示边界点
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @param[in]	bBoundaryPtsVisible  是否显示边界点
	//********************************************************************
	void SetBoundaryPtsVisible(bool bBoundaryPtsVisible);

	//********************************************************************
	/// 获取是否显示边界点
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @return 是否显示边界点
	//********************************************************************
	bool GetBoundaryPtsVisible();

	//********************************************************************
	/// 设置是否填充
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @param[in]	bBoundaryPtsFill  是否填充
	//********************************************************************
	void SetBoundaryFill(bool bBoundaryPtsFill);

	//********************************************************************
	/// 获取是否填充
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @return 是否填充
	//********************************************************************
	bool GetBoundaryFill();
	
	//********************************************************************
	/// 设置透明度
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @param[in]	dBoundaryFillPercentTranslucency  透明度
	//********************************************************************
	void SetBoundaryFillPercentTranslucency(double dBoundaryFillPercentTranslucency);

	//********************************************************************
	/// 获取透明度
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @return 透明度
	//********************************************************************
	double GetBoundaryFillPercentTranslucency();

private:
	CAreaTarget*				m_pCAreaTarget;
}; 
