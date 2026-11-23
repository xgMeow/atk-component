#pragma once
#include "../../Satellite/Attitude/IVeAttitudeStandard.h"
struct CObjData;
class IVeStandardBasic;

///
/// 标准姿态类型
///
class IATKOBJECT_API IVeTrajectoryAttitudeStandard : public IVeAttitudeStandard
{
public:
    IVeTrajectoryAttitudeStandard(const IVeTrajectoryAttitudeStandard&) = delete;
    IVeTrajectoryAttitudeStandard& operator=(const IVeTrajectoryAttitudeStandard&) = delete;

	IVeTrajectoryAttitudeStandard(CObjData* pObjData);
	~IVeTrajectoryAttitudeStandard();

	//********************************************************************
	/// 获得姿态类型属性
	/// @author	Gan Shu Long
	/// @date	2026-01-27
	/// @return	姿态类型指针
	//********************************************************************
	IVeStandardBasic* GetBasic() { return m_Basic; }

public:
	IVeStandardBasic*		m_Basic;   //得到姿态类型属性
};


