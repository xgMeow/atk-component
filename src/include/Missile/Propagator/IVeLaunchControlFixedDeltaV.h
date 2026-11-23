#pragma once
#include "../../IAtkObj.h"
#include "IVeLaunchControl.h"

///
/// 增量：固定速度
///
class IATKOBJECT_API IVeLaunchControlFixedDeltaV : public IVeLaunchControl
{
public:
    IVeLaunchControlFixedDeltaV(const IVeLaunchControlFixedDeltaV&) = delete;
    IVeLaunchControlFixedDeltaV& operator=(const IVeLaunchControlFixedDeltaV&) = delete;

	IVeLaunchControlFixedDeltaV(double* pDeltaV);
	~IVeLaunchControlFixedDeltaV();

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

private:
	double*			m_pDeltaV;
};
