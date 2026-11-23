#pragma once
#include "IVeGfxAttributesBasic.h"
struct CGfxVeh2D;

///
/// 二维显示轨迹属性
///
class IATKOBJECT_API IVeGfxAttributesOrbit : public IVeGfxAttributesBasic
{
public:
    IVeGfxAttributesOrbit(const IVeGfxAttributesOrbit&) = delete;
    IVeGfxAttributesOrbit& operator=(const IVeGfxAttributesOrbit&) = delete;

	IVeGfxAttributesOrbit(CGfxVeh2D* pCGfxVeh2D);
	~IVeGfxAttributesOrbit();

	//********************************************************************
	/// 设置是否显示二维轨迹
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	bIsGroundTrackVisible  是否显示二维轨迹
	//********************************************************************
	void SetIsGroundTrackVisible(bool bIsGroundTrackVisible);

	//********************************************************************
	/// 获得是否显示二维轨迹
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	true-显示
	//********************************************************************
	bool GetIsGroundTrackVisible();

	//********************************************************************
	/// 设置是否显示三维地面轨道
	/// @author	Gan Shu Long
	/// @date	2026-01-26
	/// @param[in]	bIsOrbitGroundVisible  是否显示三维地面轨道
	//********************************************************************
	void SetIsOrbitGroundVisible(bool bIsOrbitGroundVisible);

	//********************************************************************
	/// 获得是否显示三维地面轨道
	/// @author	Gan Shu Long
	/// @date	2026-01-26
	/// @return	true-显示
	//********************************************************************
	bool GetIsOrbitGroundVisible();

	//********************************************************************
	/// 设置是否显示三维轨道
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	bIsOrbitVisible  是否显示三维轨道
	//********************************************************************
	void SetIsOrbitVisible(bool bIsOrbitVisible);

	//********************************************************************
	/// 获得是否显示三维轨道
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	true-显示
	//********************************************************************
	bool GetIsOrbitVisible();

private:
	CGfxVeh2D*		m_pCGfxVeh2D;				//C对象二维显示指针

};
