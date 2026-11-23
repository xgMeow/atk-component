#pragma once
#include "../../IAtkObj.h"
struct CObjData;
struct CGfxRange;
class ILevelAttributeCollection;

///
/// 二维范围
///
class IATKOBJECT_API IGfxRangeContours
{
public:
    IGfxRangeContours(const IGfxRangeContours&) = delete;
    IGfxRangeContours& operator=(const IGfxRangeContours&) = delete;

	IGfxRangeContours(CGfxRange* pCGfxRange);
	~IGfxRangeContours();

	//********************************************************************
	/// 设置是否显示
	/// @author	Gan Shu Long
	/// @date	2026-01-08
	/// @param[in]	bIsVisible  是否显示
	//********************************************************************
	void SetIsVisible(bool bIsVisible);

	//********************************************************************
	/// 获得是否显示
	/// @author	Gan Shu Long
	/// @date	2026-01-08
	/// @return	是否显示
	//********************************************************************
	bool GetIsVisible();

	//********************************************************************
	/// 设置是否显示填充
	/// @author	Gan Shu Long
	/// @date	2026-01-08
	/// @param[in]	bIsVisible  是否显示填充
	//********************************************************************
	void SetIsFillVisible(bool bIsVisible);

	//********************************************************************
	/// 获得是否显示填充
	/// @author	Gan Shu Long
	/// @date	2026-01-08
	/// @return	是否显示填充
	//********************************************************************
	bool GetIsFillVisible();

	//********************************************************************
	/// 设置填充透明度
	/// @author	Gan Shu Long
	/// @date	2026-01-08
	/// @param[in]	dFillTranslucency  填充透明度
	//********************************************************************
	void SetFillTranslucency(double dFillTranslucency);

	//********************************************************************
	/// 获得填充透明度
	/// @author	Gan Shu Long
	/// @date	2026-01-08
	/// @return	填充透明度
	//********************************************************************
	double GetFillTranslucency();

	//********************************************************************
	/// 获得分级列表
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @return	分级列表
	//********************************************************************
	ILevelAttributeCollection* GetElevations() { return m_LevelAttributes; }

private:
	ILevelAttributeCollection*		m_LevelAttributes;		//分级

	CGfxRange*							m_pCGfxRange;			//C对象范围指针
};

