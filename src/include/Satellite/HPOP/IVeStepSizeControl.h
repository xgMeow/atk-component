#pragma once
#include "../../IAtkObj.h"
class CSatellite;

///
/// 太阳辐射通量/地磁指数设置
///
class IATKOBJECT_API IVeStepSizeControl
{
public:
    IVeStepSizeControl(const IVeStepSizeControl&) = delete;
    IVeStepSizeControl& operator=(const IVeStepSizeControl&) = delete;

	IVeStepSizeControl(CSatellite* pSate);
	~IVeStepSizeControl();

	//********************************************************************
	/// 设置HPOP轨道模型积分算法中积分精度
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dErrToler 积分精度
	//********************************************************************
	void SetErrorTolerance(double dErrToler);
	//********************************************************************
	/// 获得HPOP轨道模型积分算法中积分精度
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	积分精度
	//********************************************************************
	double GetErrorTolerance();

private:
	CSatellite* m_pSate;

};
