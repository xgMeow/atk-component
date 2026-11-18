#pragma once
#include "../../IAtkObj.h"
#include "IVeGfxElevation.h"
struct CGfxSwath;

///
/// 地面仰角 地面仰角包络
///
class IATKOBJECT_API IVeGfxElevationGroundElevation : public IVeGfxElevation
{
public:
    IVeGfxElevationGroundElevation(const IVeGfxElevationGroundElevation&) = delete;
    IVeGfxElevationGroundElevation& operator=(const IVeGfxElevationGroundElevation&) = delete;

	IVeGfxElevationGroundElevation(CGfxSwath* pCGfxSwath);
	~IVeGfxElevationGroundElevation();

	//********************************************************************
	/// 设置角度
	/// @author	Gan Shu Long
	/// @date	2026-01-28
	/// @param[in]	dAngle  角度
	//********************************************************************
	void SetAngle(double dAngle);

	//********************************************************************
	/// 获得角度
	/// @author	Gan Shu Long
	/// @date	2026-01-28
	/// @return	角度
	//********************************************************************
	double GetAngle();

private:
	CGfxSwath*           m_pCGfxSwath;
};

