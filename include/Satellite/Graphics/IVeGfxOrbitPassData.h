#pragma once
#include "../../IAtkObj.h"
struct CGfxVehPass;
class IVeGfxLeadTrailData;

///
/// 二维轨迹
///
class IATKOBJECT_API IVeGfxOrbitPassData
{
public:
    IVeGfxOrbitPassData(const IVeGfxOrbitPassData&) = delete;
    IVeGfxOrbitPassData& operator=(const IVeGfxOrbitPassData&) = delete;

	IVeGfxOrbitPassData(CGfxVehPass* pCGfxVehPass);
	~IVeGfxOrbitPassData();

	//********************************************************************
	/// 获得二维轨迹属性
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	二维属性指针	
	//********************************************************************
	IVeGfxLeadTrailData* GetGroundTrack();

private:
	CGfxVehPass*             m_pCGfxVehPass;

	IVeGfxLeadTrailData*     m_GroundTrack;   //二维属性

};

