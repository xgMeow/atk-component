#pragma once
#include "IVePropagator.h"
struct CObjData;
class CObjManage;
class CSatellite;
class ISatellite;
class IVeInitialState;
class ICrdnEventIntervalSmartInterval;

///
/// J2预报器
///
class IATKOBJECT_API IVePropagatorJ4Perturbation : public IVePropagator
{
public:
    IVePropagatorJ4Perturbation(const IVePropagatorJ4Perturbation&) = delete;
    IVePropagatorJ4Perturbation& operator=(const IVePropagatorJ4Perturbation&) = delete;

	IVePropagatorJ4Perturbation(CObjData* pObjData, ISatellite* pISate, CObjManage* IAsGObjManage);
	~IVePropagatorJ4Perturbation();

	//********************************************************************
	/// 获得J2轨道轨道状态
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	轨道状态指针			
	//********************************************************************
	IVeInitialState* GetInitialState();

	//********************************************************************
	/// 设置HPOP轨道模型步长
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dStep 步长
	//********************************************************************
	void SetStep(double dStep);
	//********************************************************************
	/// 获得HPOP轨道模型步长
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	步长
	//********************************************************************
	double GetStep();

	//********************************************************************
	/// 获取 历元时间间隔
	/// @author	Gan Shu Long
	/// @date	2026-10-21
	/// @return	历元时间间隔
	//********************************************************************
	ICrdnEventIntervalSmartInterval* GetEphemerisInterval() { return m_EphemerisInterval; }

private:
	CObjManage*            m_IAsGObjManage;
	CObjData*              m_pObjData;
	CSatellite*            m_pSate;
	ISatellite*            m_pISate;

	IVeInitialState*					m_InitialState;			//轨道轨道状态
	ICrdnEventIntervalSmartInterval*	m_EphemerisInterval;	//历元时间间隔

};
