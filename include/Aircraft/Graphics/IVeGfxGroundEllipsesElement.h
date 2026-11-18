#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
struct CVehEllipseSet;

///
/// 二维地面椭圆设置元素
///
class IATKOBJECT_API IVeGfxGroundEllipsesElement
{
public:
    IVeGfxGroundEllipsesElement(const IVeGfxGroundEllipsesElement&) = delete;
    IVeGfxGroundEllipsesElement& operator=(const IVeGfxGroundEllipsesElement&) = delete;

	IVeGfxGroundEllipsesElement(CVehEllipseSet* pCVehEllipseSet);
	~IVeGfxGroundEllipsesElement();

	//********************************************************************
	/// 设置是否显示名称
	/// @author	Gan Shu Long
	/// @date	2026-01-09
	/// @param[in]	bIsNameVisible  是否显示名称
	//********************************************************************
	void SetIsNameVisible(bool bIsNameVisible);

	//********************************************************************
	/// 获取是否显示名称
	/// @author	Gan Shu Long
	/// @date	2026-01-09
	/// @return 是否显示名称
	//********************************************************************
	bool GetIsNameVisible();

	//********************************************************************
	/// 设置是否显示中心点
	/// @author	Gan Shu Long
	/// @date	2026-01-09
	/// @param[in]	bIsCenterVisible  是否显示中心点
	//********************************************************************
	void SetIsCenterVisible(bool bIsCenterVisible);

	//********************************************************************
	/// 获取是否显示中心点
	/// @author	Gan Shu Long
	/// @date	2026-01-09
	/// @return 是否显示中心点
	//********************************************************************
	bool GetIsCenterVisible();

	//********************************************************************
	/// 设置颜色
	/// @author	Gan Shu Long
	/// @date	2026-01-09
	/// @param[in]	nColor  颜色
	//********************************************************************
	void SetColor(int nColor);

	//********************************************************************
	/// 获取设置颜色
	/// @author	Gan Shu Long
	/// @date	2026-01-09
	/// @return 颜色
	//********************************************************************
	int GetColor();

	//********************************************************************
	/// 设置线型
	/// @author	Gan Shu Long
	/// @date	2026-01-09
	/// @param[in]	eLineStyle  线型
	//********************************************************************
	void SetLineStyle(ELineStyle eLineStyle);

	//********************************************************************
	/// 获得线型
	/// @author	Gan Shu Long
	/// @date	2026-01-09
	/// @return	线型	
	//********************************************************************
	ELineStyle GetLineStyle();

	//********************************************************************
	/// 设置线宽
	/// @author	Gan Shu Long
	/// @date	2026-01-09
	/// @param[in]	eLineWidth  线宽
	//********************************************************************
	void SetLineWidth(ELineWidth eLineWidth);

	//********************************************************************
	/// 获得线宽
	/// @author	Gan Shu Long
	/// @date	2026-01-09
	/// @return	线宽	
	//********************************************************************
	ELineWidth GetLineWidth();

private:
	CVehEllipseSet*			m_pCVehEllipseSet;
};
