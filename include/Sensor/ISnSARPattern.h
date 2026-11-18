#pragma once
#include "ISnPattern.h"
class CSensor;

///
/// 模式类型：SAR
///
class IATKOBJECT_API ISnSARPattern : public ISnPattern
{
public:
    ISnSARPattern(const ISnSARPattern&) = delete;
    ISnSARPattern& operator=(const ISnSARPattern&) = delete;

	ISnSARPattern(CSensor* pCSensor);
	~ISnSARPattern();

	//********************************************************************
	/// 设置 地面仰角最小值
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @param[in]	dMinElevationAngle  地面仰角最小值
	//********************************************************************
	void SetMinElevationAngle(double dMinElevationAngle);

	//********************************************************************
	/// 获得 地面仰角最小值
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @return	double 地面仰角最小值	
	//********************************************************************
	double GetMinElevationAngle();

	//********************************************************************
	/// 设置 地面仰角最大值
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @param[in]	dMaxElevationAngle  地面仰角最大值
	//********************************************************************
	void SetMaxElevationAngle(double dMaxElevationAngle);

	//********************************************************************
	/// 获得 地面仰角最大值
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @return	double 地面仰角最大值	
	//********************************************************************
	double GetMaxElevationAngle();

	//********************************************************************
	/// 设置 前向排除角
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @param[in]	dForeExclusionAngle  前向排除角
	//********************************************************************
	void SetForeExclusionAngle(double dForeExclusionAngle);

	//********************************************************************
	/// 获得 前向排除角
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @return	double 前向排除角	
	//********************************************************************
	double GetForeExclusionAngle();

	//********************************************************************
	/// 设置 后向排除角
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @param[in]	dAftExclusionAngle  后向排除角
	//********************************************************************
	void SetAftExclusionAngle(double dAftExclusionAngle);

	//********************************************************************
	/// 获得 后向排除角
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @return	double 后向排除角	
	//********************************************************************
	double GetAftExclusionAngle();

	//********************************************************************
	/// 设置 是否使用父对象高度
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @param[in]	bIsTrackParentAltitude  是否使用父对象高度
	//********************************************************************
	void SetIsTrackParentAltitude(bool bIsTrackParentAltitude);

	//********************************************************************
	/// 获得 是否使用父对象高度
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @return	double 是否使用父对象高度	
	//********************************************************************
	bool GetIsTrackParentAltitude();

	//********************************************************************
	/// 设置 父对象高度
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @param[in]	dParentAltitude  父对象高度
	//********************************************************************
	void SetParentAltitude(double dParentAltitude);

	//********************************************************************
	/// 获得 父对象高度
	/// @author	Gan Shu Long
	/// @date	2026-03-20
	/// @return	double 父对象高度	
	//********************************************************************
	double GetParentAltitude();

private:
	CSensor*			m_pCSensor;
};

