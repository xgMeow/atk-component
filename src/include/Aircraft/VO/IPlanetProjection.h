#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
#include <string>
struct CGfxAttSphPlanetProj;

///
/// 三维姿态球行星投影
///
class IATKOBJECT_API IPlanetProjection
{
public:
    IPlanetProjection(const IPlanetProjection&) = delete;
    IPlanetProjection& operator=(const IPlanetProjection&) = delete;

	IPlanetProjection(CGfxAttSphPlanetProj* pCGfxAttSphPlanetProj);
	~IPlanetProjection();

	//********************************************************************
	/// 获得名称
	/// @author	Gan Shu Long
	/// @date	2026-01-21
	/// @return	名称
	//********************************************************************
	std::string GetName();

	//********************************************************************
	/// 设置是否显示
	/// @author	Gan Shu Long
	/// @date	2026-01-21
	/// @param[in]	bIsVisible  是否显示
	//********************************************************************
	void SetIsVisible(bool bIsVisible);

	//********************************************************************
	/// 获得是否显示
	/// @author	Gan Shu Long
	/// @date	2026-01-21
	/// @return	是否显示
	//********************************************************************
	bool GetIsVisible();

	//********************************************************************
	/// 设置是否显示标签
	/// @author	Gan Shu Long
	/// @date	2026-01-21
	/// @param[in]	bIsVisibleLable  是否显示标签
	//********************************************************************
	void SetIsVisibleLable(bool bIsVisibleLable);

	//********************************************************************
	/// 获得是否显示
	/// @author	Gan Shu Long
	/// @date	2026-01-21
	/// @return	是否显示
	//********************************************************************
	bool GetIsVisibleLable();

	//********************************************************************
	/// 设置颜色
	/// @author	Gan Shu Long
	/// @date	2026-01-21
	/// @param[in]	nColor  颜色
	//********************************************************************
	void SetColor(int nColor);

	//********************************************************************
	/// 获取设置颜色
	/// @author	Gan Shu Long
	/// @date	2026-01-21
	/// @return 颜色
	//********************************************************************
	int GetColor();

	//********************************************************************
	/// 设置点大小
	/// @author	Gan Shu Long
	/// @date	2026-01-21
	/// @param[in]	nPointSize  点大小
	//********************************************************************
	void SetPointSize(int nPointSize);

	//********************************************************************
	/// 获取点大小
	/// @author	Gan Shu Long
	/// @date	2026-01-21
	/// @return 点大小
	//********************************************************************
	int GetPointSize();

private:
	CGfxAttSphPlanetProj*			m_pCGfxAttSphPlanetProj;
};
