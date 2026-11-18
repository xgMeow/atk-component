#pragma once
#include "../../IAtkObj.h"
#include "../../ICEnum.h"
class CSatellite;
class IVeStepSizeControl;

///
/// 积分算法
///
class IATKOBJECT_API IVeIntegrator
{
public:
    IVeIntegrator(const IVeIntegrator&) = delete;
    IVeIntegrator& operator=(const IVeIntegrator&) = delete;

	IVeIntegrator(CSatellite* pSate);
	~IVeIntegrator();

	//********************************************************************
	/// 获得HPOP轨道模型积分算法属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	积分算法属性
	//********************************************************************
	IVeStepSizeControl* GetStepSizeControl();

	//********************************************************************
	/// 设置HPOP轨道模型积分算法是否固定步长输出星历
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	bReEphOnFixTStep 是否固定步长输出星历
	//********************************************************************
	void SetReportEphemOnFixedTimeStep(bool bReEphOnFixTStep);
	//********************************************************************
	/// 获得HPOP轨道模型积分算法是否固定步长输出星历
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	是否固定步长输出星历
	//********************************************************************
	bool GetReportEphemOnFixedTimeStep();

private:
	CSatellite*             m_pSate;

	IVeStepSizeControl*     m_StepSizeControl;              //HPOP轨道模型积分算法属性

};

