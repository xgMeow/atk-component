#pragma once
#include "../../IAtkObj.h"
#include "../../IClassInfo.h" 
struct GfxFOMGraphics;
class IFmGfxContours;

///
/// 二维视图 静态
///
class IATKOBJECT_API IFmGfxAttributes :public IClassInfo
{
public:
    IFmGfxAttributes(const IFmGfxAttributes&) = delete;
    IFmGfxAttributes& operator=(const IFmGfxAttributes&) = delete;

	IFmGfxAttributes(GfxFOMGraphics* pGfxFOMGraphics);
	~IFmGfxAttributes();

	//********************************************************************
	/// 设置 是否显示静态/动态图像
	/// @author	Gan Shu Long
	/// @date	2026-05-11
	/// @param[in]	bIsVisible  是否显示静态/动态图像
	//********************************************************************
	void SetIsVisible(bool bIsVisible);

	//********************************************************************
	/// 获得 是否显示静态/动态图像
	/// @author	Gan Shu Long
	/// @date	2026-05-11
	/// @return 是否显示静态/动态图像
	//********************************************************************
	bool GetIsVisible();

	//********************************************************************
	/// 设置 透明度
	/// @author	Gan Shu Long
	/// @date	2026-05-12
	/// @param[in]	dFillTranslucency  透明度
	//********************************************************************
	void SetFillTranslucency(double dFillTranslucency);

	//********************************************************************
	/// 获得  透明度
	/// @author	Gan Shu Long
	/// @date	2026-05-12
	/// @return	 透明度
	//********************************************************************
	double GetFillTranslucency();

	//********************************************************************
	/// 设置 颜色
	/// @author	Gan Shu Long
	/// @date	2026-05-12
	/// @param[in]	nColor  颜色
	//********************************************************************
	void SetColor(int nColor);

	//********************************************************************
	/// 获取 颜色
	/// @author	Gan Shu Long
	/// @date	2026-05-12
	/// @return 颜色
	//********************************************************************
	int GetColor();

	//********************************************************************
	/// 获得 分级轮廓
	/// @author	Gan Shu Long
	/// @date	2026-05-11
	/// @return	分级轮廓
	//********************************************************************
	IFmGfxContours* GetContours() { return m_Contours; }
	
private:
	GfxFOMGraphics*			m_pGfxFOMGraphics;

	IFmGfxContours*		m_Contours;
	
};

