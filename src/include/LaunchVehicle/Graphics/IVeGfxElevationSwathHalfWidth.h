#pragma once
#include "../../IAtkObj.h"
#include "IVeGfxElevation.h"
struct CGfxSwath;

///
/// 刈幅半幅宽
///
class IATKOBJECT_API IVeGfxElevationSwathHalfWidth : public IVeGfxElevation
{
public:
    IVeGfxElevationSwathHalfWidth(const IVeGfxElevationSwathHalfWidth&) = delete;
    IVeGfxElevationSwathHalfWidth& operator=(const IVeGfxElevationSwathHalfWidth&) = delete;

	IVeGfxElevationSwathHalfWidth(CGfxSwath* pCGfxSwath);
	~IVeGfxElevationSwathHalfWidth();

	//********************************************************************
	/// 设置距离
	/// @author	Gan Shu Long
	/// @date	2026-01-28
	/// @param[in]	dDistance  距离
	//********************************************************************
	void SetDistance(double dDistance);

	//********************************************************************
	/// 获得距离
	/// @author	Gan Shu Long
	/// @date	2026-01-28
	/// @return	距离
	//********************************************************************
	double GetDistance();

private:
	CGfxSwath*           m_pCGfxSwath;
};

