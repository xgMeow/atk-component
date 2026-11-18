#pragma once
#include "../../IAtkObj.h"
#include "IVeGfxElevation.h"
struct CGfxSwath;

///
/// 飞行器半锥角 飞行器半锥角包络
///
class IATKOBJECT_API IVeGfxElevationVehicleHalfAngle : public IVeGfxElevation
{
public:
    IVeGfxElevationVehicleHalfAngle(const IVeGfxElevationVehicleHalfAngle&) = delete;
    IVeGfxElevationVehicleHalfAngle& operator=(const IVeGfxElevationVehicleHalfAngle&) = delete;

	IVeGfxElevationVehicleHalfAngle(CGfxSwath* pCGfxSwath);
	~IVeGfxElevationVehicleHalfAngle();
	
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

