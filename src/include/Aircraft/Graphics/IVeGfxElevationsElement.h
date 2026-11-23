#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
struct CGfxContourAttri;

///
/// 二维等高线分级元素
///
class IATKOBJECT_API IVeGfxElevationsElement
{
public:
    IVeGfxElevationsElement(const IVeGfxElevationsElement&) = delete;
    IVeGfxElevationsElement& operator=(const IVeGfxElevationsElement&) = delete;

	IVeGfxElevationsElement(CGfxContourAttri* pCGfxContourAttri);
	~IVeGfxElevationsElement();

	//********************************************************************
	/// 设置分级deg
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @param[in]	dElevation  分级deg
	//********************************************************************
	void SetElevation(double dElevation);

	//********************************************************************
	/// 获取分级deg
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @return 分级deg
	//********************************************************************
	double GetElevation();

	//********************************************************************
	/// 设置颜色
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @param[in]	nColor  颜色
	//********************************************************************
	void SetColor(int nColor);

	//********************************************************************
	/// 获取设置颜色
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @return 颜色
	//********************************************************************
	int GetColor();

	//********************************************************************
	/// 设置线型
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @param[in]	eLineStyle  线型
	//********************************************************************
	void SetLineStyle(ELineStyle eLineStyle);

	//********************************************************************
	/// 获得线型
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @return	线型	
	//********************************************************************
	ELineStyle GetLineStyle();

	//********************************************************************
	/// 设置线宽
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @param[in]	eLineWidth  线宽
	//********************************************************************
	void SetLineWidth(ELineWidth eLineWidth);

	//********************************************************************
	/// 获得线宽
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @return	线宽	
	//********************************************************************
	ELineWidth GetLineWidth();

	//********************************************************************
	/// 设置是否显示标签
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @param[in]	bUserTextVisible  是否显示标签
	//********************************************************************
	void SetUserTextVisible(bool bUserTextVisible);

	//********************************************************************
	/// 获得是否显示标签
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @return	是否显示标签
	//********************************************************************
	bool GetUserTextVisible();

private:
	CGfxContourAttri*			m_pCGfxContourAttri;	
};
