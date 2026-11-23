#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
class CChain;

///
/// 静态可视化属性
///
class IATKOBJECT_API IChGfxStatic
{
public:
    IChGfxStatic(const IChGfxStatic&) = delete;
    IChGfxStatic& operator=(const IChGfxStatic&) = delete;

	IChGfxStatic(CChain* pCChain);
	~IChGfxStatic();

	//********************************************************************
	/// 设置是否显示
	/// @author	Gan Shu Long
	/// @date	2026-01-12
	/// @param[in]	bIsVisible  是否显示
	//********************************************************************
	void SetIsVisible(bool bIsVisible);

	//********************************************************************
	/// 获取是否显示
	/// @author	Gan Shu Long
	/// @date	2026-01-12
	/// @return 是否显示
	//********************************************************************
	bool GetIsVisible();

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

private:
	CChain*			m_pCChain;
};
