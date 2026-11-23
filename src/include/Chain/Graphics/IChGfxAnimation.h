#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
class CChain;

///
/// 动态可视化属性
///
class IATKOBJECT_API IChGfxAnimation
{
public:
    IChGfxAnimation(const IChGfxAnimation&) = delete;
    IChGfxAnimation& operator=(const IChGfxAnimation&) = delete;

	IChGfxAnimation(CChain* pCChain);
	~IChGfxAnimation();

	//********************************************************************
	/// 设置是否高亮显示
	/// @author	Gan Shu Long
	/// @date	2026-01-12
	/// @param[in]	bIsHighlightVisible  是否高亮显示
	//********************************************************************
	void SetIsHighlightVisible(bool bIsHighlightVisible);

	//********************************************************************
	/// 获取是否高亮显示
	/// @author	Gan Shu Long
	/// @date	2026-01-12
	/// @return 是否高亮显示
	//********************************************************************
	bool GetIsHighlightVisible();

	//********************************************************************
	/// 设置是否显示线
	/// @author	Gan Shu Long
	/// @date	2026-01-12
	/// @param[in]	bIsLineVisible  是否显示线
	//********************************************************************
	void SetIsLineVisible(bool bIsLineVisible);

	//********************************************************************
	/// 获取是否显示线
	/// @author	Gan Shu Long
	/// @date	2026-01-12
	/// @return 是否显示线
	//********************************************************************
	bool GetIsLineVisible();
	
	//********************************************************************
	/// 设置颜色
	/// @author	Gan Shu Long
	/// @date	2026-01-12
	/// @param[in]	nColor  颜色
	//********************************************************************
	void SetColor(int nColor);

	//********************************************************************
	/// 获取设置颜色
	/// @author	Gan Shu Long
	/// @date	2026-01-12
	/// @return 颜色
	//********************************************************************
	int GetColor();

	//********************************************************************
	/// 设置线型
	/// @author	Gan Shu Long
	/// @date	2026-01-12
	/// @param[in]	eLineStyle  线型
	//********************************************************************
	void SetLineStyle(ELineStyle eLineStyle);

	//********************************************************************
	/// 获得线型
	/// @author	Gan Shu Long
	/// @date	2026-01-12
	/// @return	线型	
	//********************************************************************
	ELineStyle GetLineStyle();

	//********************************************************************
	/// 设置线宽
	/// @author	Gan Shu Long
	/// @date	2026-01-12
	/// @param[in]	eLineWidth  线宽
	//********************************************************************
	void SetLineWidth(ELineWidth eLineWidth);

	//********************************************************************
	/// 获得线宽
	/// @author	Gan Shu Long
	/// @date	2026-01-12
	/// @return	线宽	
	//********************************************************************
	ELineWidth GetLineWidth();

	//********************************************************************
	/// 设置是否显示方向
	/// @author	Gan Shu Long
	/// @date	2026-01-12
	/// @param[in]	bIsDirectionVisible  是否显示方向
	//********************************************************************
	void SetIsDirectionVisible(bool bIsDirectionVisible);

	//********************************************************************
	/// 获取是否显示方向
	/// @author	Gan Shu Long
	/// @date	2026-01-12
	/// @return 是否显示方向
	//********************************************************************
	bool GetIsDirectionVisible();

private:
	CChain*			m_pCChain;
};
