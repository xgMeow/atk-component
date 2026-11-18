#pragma once
#include "../../Satellite/Propagator/IVePropagator.h"
struct CObjData;
class CLaunchVehicle;
class ICrdnEventIntervalSmartInterval;
class IVeLvInitialState;

///
/// 简单上升预报器
///
class IATKOBJECT_API IVePropagatorSimpleAscent : public IVePropagator
{
public:
    IVePropagatorSimpleAscent(const IVePropagatorSimpleAscent&) = delete;
    IVePropagatorSimpleAscent& operator=(const IVePropagatorSimpleAscent&) = delete;

	IVePropagatorSimpleAscent(CObjData* pObjData);
	~IVePropagatorSimpleAscent();

	//********************************************************************
	/// 获得轨道传播间隔
	/// @author	Gan Shu Long
	/// @date	2024-09-23
	/// @return	轨道传播间隔			
	//********************************************************************
	ICrdnEventIntervalSmartInterval* GetEphemerisInterval() { return m_EphemerisInterval; }

	//********************************************************************
	/// 获得轨道初始状态
	/// @author	Gan Shu Long
	/// @date	2024-09-23
	/// @return	轨道状态指针			
	//********************************************************************
	IVeLvInitialState* GetInitialState() { return m_InitialState; }

	//********************************************************************
	/// 获得轨道步长
	/// @author	Gan Shu Long
	/// @date	2024-09-23
	/// @return	步长
	//********************************************************************
	double GetStep();

	//********************************************************************
	/// 设置轨道步长
	/// @author	Gan Shu Long
	/// @date	2024-09-23
	/// @param[in]	dStep 步长
	//********************************************************************
	void SetStep(double dStep);

private:
	CLaunchVehicle*								m_pCLaunchVehicle;

	ICrdnEventIntervalSmartInterval*	m_EphemerisInterval;		//轨道传播间隔
	IVeLvInitialState*								m_InitialState;					//轨道初始状态
};
