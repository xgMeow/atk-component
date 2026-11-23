#pragma once
#include "../../IAtkObj.h"
struct GfxFOMGraphics;

///
/// 分级属性列表元素
///
class IATKOBJECT_API IFmGfxLevelAttributesElement
{
public:
    IFmGfxLevelAttributesElement(const IFmGfxLevelAttributesElement&) = delete;
    IFmGfxLevelAttributesElement& operator=(const IFmGfxLevelAttributesElement&) = delete;

	IFmGfxLevelAttributesElement(GfxFOMGraphics* pGfxFOMGraphics, double dLevel);
	~IFmGfxLevelAttributesElement();

	//********************************************************************
	/// 设置分级deg
	/// @author	Gan Shu Long
	/// @date	2026-05-12
	/// @param[in]	dLevel  分级
	//********************************************************************
	void SetLevel(double dLevel);

	//********************************************************************
	/// 获取分级deg
	/// @author	Gan Shu Long
	/// @date	2026-05-12
	/// @return 分级deg
	//********************************************************************
	double GetLevel();

	//********************************************************************
	/// 设置颜色
	/// @author	Gan Shu Long
	/// @date	2026-05-12
	/// @param[in]	nColor  颜色
	//********************************************************************
	void SetColor(int nColor);

	//********************************************************************
	/// 获取设置颜色
	/// @author	Gan Shu Long
	/// @date	2026-05-12
	/// @return 颜色
	//********************************************************************
	int GetColor();

private:
	GfxFOMGraphics*			m_pGfxFOMGraphics;

	double								m_dLevel;
};
