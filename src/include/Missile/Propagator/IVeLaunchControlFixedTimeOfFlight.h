#pragma once
#include "../../IAtkObj.h"
#include "IVeLaunchControl.h"

///
/// 增量：固定飞行时间
///
class IATKOBJECT_API IVeLaunchControlFixedTimeOfFlight : public IVeLaunchControl
{
public:
    IVeLaunchControlFixedTimeOfFlight(const IVeLaunchControlFixedTimeOfFlight&) = delete;
    IVeLaunchControlFixedTimeOfFlight& operator=(const IVeLaunchControlFixedTimeOfFlight&) = delete;

	IVeLaunchControlFixedTimeOfFlight(double* pTimeOfFlight);
	~IVeLaunchControlFixedTimeOfFlight();

	//********************************************************************
	/// 获得飞行时间增量
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @return	飞行时间增量
	//********************************************************************
	double GetTimeOfFlight();

	//********************************************************************
	/// 设置飞行时间增量
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @param[in]	dTimeOfFlight 飞行时间增量
	//********************************************************************
	void SetTimeOfFlight(double dTimeOfFlight);

private:
	double*			m_pTimeOfFlight;
};
