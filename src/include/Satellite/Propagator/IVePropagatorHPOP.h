#pragma once
#include "../../IAtkObj.h"
#include "IVePropagator.h"
struct CObjData;
class CObjManage;
class CSatellite;
class ISatellite;
class IVeHPOPForceModel;
class IVeInitialState;
class IVeIntegrator;
class ICrdnEventIntervalSmartInterval;

///
/// HPOP预报器
///
class IATKOBJECT_API IVePropagatorHPOP : public IVePropagator
{
public:
    IVePropagatorHPOP(const IVePropagatorHPOP&) = delete;
    IVePropagatorHPOP& operator=(const IVePropagatorHPOP&) = delete;

	IVePropagatorHPOP(CObjData* pObjData, ISatellite* pISate, CObjManage* IAsGObjManage);
	~IVePropagatorHPOP();

	//********************************************************************
	/// 获得HPOP轨道力模型属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	力模型属性指针			
	//********************************************************************
	IVeHPOPForceModel* GetForceModel();

	//********************************************************************
	/// 获得HPOP轨道轨道状态
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	轨道状态指针			
	//********************************************************************
	IVeInitialState* GetInitialState();

	//********************************************************************
	/// 获得HPOP轨道积分算法属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	积分算法属性指针			
	//********************************************************************
	IVeIntegrator* GetIntegrator();

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

	IVeHPOPForceModel*     m_ForceModel;     //HPOP轨道力模型属性
	IVeInitialState*       m_InitialState;   //HPOP轨道轨道状态
	IVeIntegrator*         m_Integrator;     //HPOP轨道积分算法属性
	ICrdnEventIntervalSmartInterval*	m_EphemerisInterval;	//历元时间间隔

};
