#pragma once
#include "../../IAtkObj.h"
#include "IVeLaunchControl.h"

///
/// 增量：固定远地点距离
///
class IATKOBJECT_API IVeLaunchControlFixedApogeeAlt : public IVeLaunchControl
{
public:
    IVeLaunchControlFixedApogeeAlt(const IVeLaunchControlFixedApogeeAlt&) = delete;
    IVeLaunchControlFixedApogeeAlt& operator=(const IVeLaunchControlFixedApogeeAlt&) = delete;

	IVeLaunchControlFixedApogeeAlt(double* pApogeeAlt);
	~IVeLaunchControlFixedApogeeAlt();

	//********************************************************************
	/// 获得距离增量
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @return	距离增量
	//********************************************************************
	double GetApogeeAlt();

	//********************************************************************
	/// 设置距离增量
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @param[in]	dApogeeAlt 距离增量
	//********************************************************************
	void SetApogeeAlt(double dApogeeAlt);

private:
	double*			m_pApogeeAlt;
};
