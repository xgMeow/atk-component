#pragma once
#include "../../IAtkObj.h"
class CFacility;
class IGfxRangeContours;

///
/// 二维
///
class IATKOBJECT_API IFaGraphics
{
public:
    IFaGraphics(const IFaGraphics&) = delete;
    IFaGraphics& operator=(const IFaGraphics&) = delete;

	IFaGraphics(CFacility* pCFacilit);
	~IFaGraphics();

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
	/// 设置是否显示标签
	/// @author	Gan Shu Long
	/// @date	2026-01-20
	/// @param[in]	bLabelVisible  是否显示标签
	//********************************************************************
	void SetLabelVisible(bool bLabelVisible);

	//********************************************************************
	/// 获得是否显示标签
	/// @author	Gan Shu Long
	/// @date	2026-01-20
	/// @return	是否显示标签
	//********************************************************************
	bool GetLabelVisible();

	//********************************************************************
	/// 设置二维显示颜色
	/// @author	Gan Shu Long
	/// @date	2024-05-21
	/// @param[in]	nColor  二维显示颜色，例绿色-65280
	//********************************************************************
	void SetColor(int nColor);

	//********************************************************************
	/// 获得二维显示颜色
	/// @author	Gan Shu Long
	/// @date	2024-05-21
	/// @return	二维显示颜色
	//********************************************************************
	int GetColor();

	//********************************************************************
	/// 设置二维显示标识类型
	/// @author	Gan Shu Long
	/// @date	2024-05-21
	/// @note 参数 strMakStyle：标识类型
	//********************************************************************
	//void SetMarkerStyle(std::string strMakStyle);

	//********************************************************************
	/// 获得二维显示标识类型
	/// @author	Gan Shu Long
	/// @date	2024-05-21
	/// @note 取值：标识类型
	//********************************************************************
	//std::string GetMarkerStyle() { return m_MarkerStyle; }

	//********************************************************************
	/// 获得二维范围
	/// @author	Gan Shu Long
	/// @date	2026-01-20
	/// @return	二维范围
	//********************************************************************
	IGfxRangeContours* GetContours() { return m_Contours; }
	
private:
	CFacility*							m_pCFacility;
	IGfxRangeContours*		m_Contours;
};

