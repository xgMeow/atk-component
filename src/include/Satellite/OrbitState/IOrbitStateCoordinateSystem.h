#pragma once
#include "../../IAtkObj.h"
class CSatellite;
class ICrdnEventSmartEpoch;

///
/// 轨道坐标系统
///
class IATKOBJECT_API IOrbitStateCoordinateSystem
{
public:
	IOrbitStateCoordinateSystem(const IOrbitStateCoordinateSystem&) = delete;
	IOrbitStateCoordinateSystem& operator=(const IOrbitStateCoordinateSystem&) = delete;

	IOrbitStateCoordinateSystem(CSatellite* pSate);
	virtual ~IOrbitStateCoordinateSystem();

	//********************************************************************
	/// 获取 坐标历元时间
	/// @author	Gan Shu Long
	/// @date	2026-10-22
	/// @return	坐标历元时间
	//********************************************************************
	ICrdnEventSmartEpoch* GetCoordinateSystemEpoch() { return m_CoordinateSystemEpoch; }


private:
	ICrdnEventSmartEpoch*	m_CoordinateSystemEpoch;		//坐标历元时间
};
