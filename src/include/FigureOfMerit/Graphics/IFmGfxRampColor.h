#pragma once
#include "../../IAtkObj.h"
struct GfxFOMGraphics;

///
/// 色阶
///
class IATKOBJECT_API IFmGfxRampColor
{
public:
    IFmGfxRampColor(const IFmGfxRampColor&) = delete;
    IFmGfxRampColor& operator=(const IFmGfxRampColor&) = delete;

	IFmGfxRampColor(GfxFOMGraphics* pGfxFOMGraphics);
	~IFmGfxRampColor();

	//********************************************************************
	/// 设置 起始颜色
	/// @author	Gan Shu Long
	/// @date	2026-05-12
	/// @param[in]	nStartColor  起始颜色
	//********************************************************************
	void SetStartColor(int nStartColor);

	//********************************************************************
	/// 获取 起始颜色
	/// @author	Gan Shu Long
	/// @date	2026-05-12
	/// @return 起始颜色
	//********************************************************************
	int GetStartColor();

	//********************************************************************
	/// 设置 结束颜色
	/// @author	Gan Shu Long
	/// @date	2026-05-12
	/// @param[in]	nEndColor  结束颜色
	//********************************************************************
	void SetEndColor(int nEndColor);

	//********************************************************************
	/// 获取 结束颜色
	/// @author	Gan Shu Long
	/// @date	2026-05-12
	/// @return 结束颜色
	//********************************************************************
	int GetEndColor();

private:
	GfxFOMGraphics*			m_pGfxFOMGraphics;
};
