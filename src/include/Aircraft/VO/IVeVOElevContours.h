#pragma once
#include "../../IAtkObj.h"
struct CObjData;
struct CGfxContour;

///
/// 三维等高线
///
class IATKOBJECT_API IVeVOElevContours
{
public:
    IVeVOElevContours(const IVeVOElevContours&) = delete;
    IVeVOElevContours& operator=(const IVeVOElevContours&) = delete;

	IVeVOElevContours(CGfxContour* pCGfxContour);
	~IVeVOElevContours();

	//********************************************************************
	/// 设置是否显示
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @param[in]	bIsVisible  是否显示
	//********************************************************************
	void SetIsVisible(bool bIsVisible);

	//********************************************************************
	/// 获得是否显示
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @return	是否显示
	//********************************************************************
	bool GetIsVisible();

	//********************************************************************
	/// 设置是否显示Cones
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @param[in]	bIsConesVisible  是否显示Cones
	//********************************************************************
	void SetIsConesVisible(bool bIsConesVisible);

	//********************************************************************
	/// 获得是否显示Cones
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @return	是否显示Cones
	//********************************************************************
	bool GetIsConesVisible();

	//********************************************************************
	/// 设置透明度
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @param[in]	dTranslucency  透明度
	//********************************************************************
	void SetTranslucency(double dTranslucency);

	//********************************************************************
	/// 获得填充透明度
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @return	填充透明度
	//********************************************************************
	double GetTranslucency();

	//********************************************************************
	/// 设置是否显示填充
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @param[in]	bIsVisible  是否显示填充
	//********************************************************************
	void SetIsFillVisible(bool bIsVisible);

	//********************************************************************
	/// 获得是否显示填充
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @return	是否显示填充
	//********************************************************************
	bool GetIsFillVisible();

	//********************************************************************
	/// 设置填充透明度
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @param[in]	dFillTranslucency  填充透明度
	//********************************************************************
	void SetFillTranslucency(double dFillTranslucency);

	//********************************************************************
	/// 获得填充透明度
	/// @author	Gan Shu Long
	/// @date	2026-01-06
	/// @return	填充透明度
	//********************************************************************
	double GetFillTranslucency();

private:
	CGfxContour*							m_pCGfxContour;		//C对象等高线指针
};

