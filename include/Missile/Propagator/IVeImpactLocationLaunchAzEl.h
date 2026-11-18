#pragma once
#include "../../IAtkObj.h"
#include "IVeImpactLocation.h"
struct CObjData;
class CMissile;

///
/// 发射仰角方位角落点
///
class IATKOBJECT_API IVeImpactLocationLaunchAzEl : public IVeImpactLocation
{
public:
    IVeImpactLocationLaunchAzEl(const IVeImpactLocationLaunchAzEl&) = delete;
    IVeImpactLocationLaunchAzEl& operator=(const IVeImpactLocationLaunchAzEl&) = delete;

	IVeImpactLocationLaunchAzEl(CObjData* pObjData);
	~IVeImpactLocationLaunchAzEl();

	//********************************************************************
	/// 获得速度增量
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @return	速度增量
	//********************************************************************
	double GetDeltaV();

	//********************************************************************
	/// 设置速度增量
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @param[in]	dDeltaV 速度增量
	//********************************************************************
	void SetDeltaV(double dDeltaV);

	//********************************************************************
	/// 获得发射仰角
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @return	发射仰角
	//********************************************************************
	double GetElevation();

	//********************************************************************
	/// 设置发射仰角
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @param[in]	dElevation 发射仰角
	//********************************************************************
	void SetElevation(double dElevation);

	//********************************************************************
	/// 获得发射点方位角
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @return	发射点方位角
	//********************************************************************
	double GetAzimuth();

	//********************************************************************
	/// 设置发射点方位角
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @param[in]	dAzimuth 发射点方位角
	//********************************************************************
	void SetAzimuth(double dAzimuth);

private:
	CObjData*											m_pObjData;
	CMissile*												m_pCMissile;
};
