#pragma once
#include "IVAManeuver.h"
class CObjManage;
class CMCSSegment;
class IVAMCSSegment;
class IVAManeuverFinitePropagator;

///
/// 机动段有限推力
///
class IATKOBJECT_API IVAManeuverFinite : public IVAManeuver
{
public:
    IVAManeuverFinite(const IVAManeuverFinite&) = delete;
    IVAManeuverFinite& operator=(const IVAManeuverFinite&) = delete;

	IVAManeuverFinite(CMCSSegment* pcSegment, IVAMCSSegment* pIVAMCSSegment, CObjManage* IAsGObjManage);
	~IVAManeuverFinite();

	//********************************************************************
	/// 获得轨道预报
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	轨道预报指针
	//********************************************************************
	IVAManeuverFinitePropagator* GetPropagator();

	//********************************************************************
	/// 设置推力
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Input
	/// @Param	dThrust 推力，在有限推力类型下可设置
	/// @Return	
	//********************************************************************
	void SetThrust(double dThrust);
	//********************************************************************
	/// 获得推力
	/// @Author	Dong Min
	/// @Date	2023-11-3
	/// @Return	推力
	//********************************************************************
	double GetThrust();



private:
	CMCSSegment*						m_pcSegment;
	IVAMCSSegment*						m_pIVAMCSSegment;
	CObjManage*							m_IAsGObjManage;

	IVAManeuverFinitePropagator*		m_Propagator;   //轨道预报

};
