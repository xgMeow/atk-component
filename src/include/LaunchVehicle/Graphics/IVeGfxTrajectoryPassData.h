#pragma once
#include "../../IAtkObj.h"
struct CGfxVehPass;
class IVeGfxLeadTrailData;

///
/// 二维轨迹
///
class IATKOBJECT_API IVeGfxTrajectoryPassData
{
public:
    IVeGfxTrajectoryPassData(const IVeGfxTrajectoryPassData&) = delete;
    IVeGfxTrajectoryPassData& operator=(const IVeGfxTrajectoryPassData&) = delete;

	IVeGfxTrajectoryPassData(CGfxVehPass* pCGfxVehPass);
	~IVeGfxTrajectoryPassData();

	//********************************************************************
	/// 获得轨迹属性
	/// @author	Gan Shu Long
	/// @date	2024-09-25
	/// @return	轨迹属性指针	
	//********************************************************************
	IVeGfxLeadTrailData* GetTrajectory() { return m_Trajectory; }

private:
	IVeGfxLeadTrailData*     m_Trajectory;   //轨迹属性
};

