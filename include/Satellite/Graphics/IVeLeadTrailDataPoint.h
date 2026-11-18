#pragma once
#include "IVeLeadTrailData.h"
struct CGfxVehPass;

///
/// 二维轨迹点类型
///
class IATKOBJECT_API IVeLeadTrailDataPoint : public IVeLeadTrailData
{ 
public:
    IVeLeadTrailDataPoint(const IVeLeadTrailDataPoint&) = delete;
    IVeLeadTrailDataPoint& operator=(const IVeLeadTrailDataPoint&) = delete;

	IVeLeadTrailDataPoint(CGfxVehPass* pCGfxVehPass);
	~IVeLeadTrailDataPoint();

	//********************************************************************
	/// 设置轨迹点属性值
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @param[in]	dPoint  轨迹点值
	//********************************************************************
	void SetPoint(double dPoint);

	//********************************************************************
	/// 获得轨迹点属性值
	/// @author	Dong Min
	/// @date	2023-11-3
	/// @return	轨迹点值
	//********************************************************************
	double GetPoint();

private:
	CGfxVehPass*	m_pCGfxVehPass;		//C对象二维轨迹指针
};

