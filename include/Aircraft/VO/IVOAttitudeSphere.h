#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
class CGfx3DAttitudeSphere;
class IPlanetProjectionCollection;

///
/// 三维姿态球
///
class IATKOBJECT_API IVOAttitudeSphere
{
public:
    IVOAttitudeSphere(const IVOAttitudeSphere&) = delete;
    IVOAttitudeSphere& operator=(const IVOAttitudeSphere&) = delete;

	IVOAttitudeSphere(CGfx3DAttitudeSphere* pCGfx3DAttitudeSphere);
	~IVOAttitudeSphere();

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
	/// 设置零度线宽
	/// @author	Gan Shu Long
	/// @date	2026-01-21
	/// @param[in]	eZeroDegLineWidth  零度线宽
	//********************************************************************
	void SetZeroDegLineWidth(ELineWidth eZeroDegLineWidth);

	//********************************************************************
	/// 获得零度线宽
	/// @author	Gan Shu Long
	/// @date	2026-01-21
	/// @return	零度线宽	
	//********************************************************************
	ELineWidth GetZeroDegLineWidth();
	
	//********************************************************************
	/// 设置线宽
	/// @author	Gan Shu Long
	/// @date	2026-01-21
	/// @param[in]	eLineWidth  线宽
	//********************************************************************
	void SetLineWidth(ELineWidth eLineWidth);

	//********************************************************************
	/// 获得线宽
	/// @author	Gan Shu Long
	/// @date	2026-01-21
	/// @return	线宽	
	//********************************************************************
	ELineWidth GetLineWidth();

	////********************************************************************
	///// 设置参考坐标系
	///// @Author	Gan Shu Long
	///// @Date	2026-01-21
	///// @Input
	///// @Param	eLineWidth  参考坐标系
	///// @Return	
	////********************************************************************
	//void SetReferenceAxes(ELineWidth eLineWidth);

	////********************************************************************
	///// 获得参考坐标系
	///// @Author	Gan Shu Long
	///// @Date	2026-01-21
	///// @Return	参考坐标系	
	////********************************************************************
	//ELineWidth GetReferenceAxes();

	//********************************************************************
	/// 设置比例
	/// @author	Gan Shu Long
	/// @date	2026-01-21
	/// @param[in]	dScale  比例
	//********************************************************************
	void SetScale(double dScale);

	//********************************************************************
	/// 获得比例
	/// @author	Gan Shu Long
	/// @date	2026-01-21
	/// @return	比例		
	//********************************************************************
	double GetScale();

	//********************************************************************
	/// 获得行星投影列表
	/// @author	Gan Shu Long
	/// @date	2026-01-21
	/// @return	行星投影列表
	//********************************************************************
	IPlanetProjectionCollection* GetPlanetProjectionCollection() { return m_PlanetProjectionCollection; }

private:
	IPlanetProjectionCollection*			m_PlanetProjectionCollection;	//行星投影列表

	CGfx3DAttitudeSphere*					m_pCGfx3DAttitudeSphere;		//C对象姿态球
};

