#pragma once
#include "../../Satellite/Propagator/IVePropagator.h"
#include "../../ICEnum.h"
#include <vector>
#include <string>
struct CObjData;
class CMissile;
class ICrdnEventIntervalSmartInterval;
class IVeLaunch;
class IVeImpactLocation;


///
/// 弹道学预报器
///
class IATKOBJECT_API IVePropagatorBallistic : public IVePropagator
{
public:
    IVePropagatorBallistic(const IVePropagatorBallistic&) = delete;
    IVePropagatorBallistic& operator=(const IVePropagatorBallistic&) = delete;

	IVePropagatorBallistic(CObjData* pObjData);
	~IVePropagatorBallistic();

	//********************************************************************
	/// 获得轨道传播间隔
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @return	轨道传播间隔			
	//********************************************************************
	ICrdnEventIntervalSmartInterval* GetEphemerisInterval() { return m_EphemerisInterval; }

	//********************************************************************
	/// 获得轨道步长
	/// @author	Gan Shu Long
	/// @date	2026-03-04
	/// @return	步长
	//********************************************************************
	double GetStep();

	//********************************************************************
	/// 设置轨道步长
	/// @author	Gan Shu Long
	/// @date	2026-03-04
	/// @param[in]	dStep 步长
	//********************************************************************
	void SetStep(double dStep);

	//********************************************************************
	/// 获得发射点
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @return	发射点		
	//********************************************************************
	IVeLaunch* GetLaunch() { return m_Launch; }

	//********************************************************************
	/// 获得支持的落点类型
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @return 支持的落点类型
	//********************************************************************
	std::vector<std::string> GetImpactLocationSupportedTypes();

	//********************************************************************
	/// 判断是否支持落点类型
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @param	eVeImpactLocation  落点类型
	/// @return 是否支持落点类型
	//********************************************************************
	bool IsImpactLocationTypeSupported(EVeImpactLocation eVeImpactLocation);

	//********************************************************************
	/// 设置落点类型
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @param[in]	eVeImpactLocation  落点类型
	//********************************************************************
	void SetImpactLocationType(EVeImpactLocation eVeImpactLocation);

	//********************************************************************
	/// 获得落点类型
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @return	落点类型
	//********************************************************************
	EVeImpactLocation GetImpactLocationType();

	//********************************************************************
	/// 获得落点
	/// @author	Gan Shu Long
	/// @date	2026-03-05
	/// @return	落点		
	//********************************************************************
	IVeImpactLocation* GetImpactLocation() { return m_ImpactLocation; }

private:
	CObjData*											m_pObjData;
	CMissile*												m_pCMissile;

	ICrdnEventIntervalSmartInterval*		m_EphemerisInterval;		//轨道传播间隔
	IVeLaunch*											m_Launch;						//发射点
	IVeImpactLocation*								m_ImpactLocation;			//落点
};
