#pragma once
#include "../IAtkObj.h"
#include "IAreaTypeData.h"
struct AsTAtEllipse;

///
/// 区域椭圆
///
class IATKOBJECT_API IAreaTypeEllipse :public IAreaTypeData
{
public:
    IAreaTypeEllipse(const IAreaTypeEllipse&) = delete;
    IAreaTypeEllipse& operator=(const IAreaTypeEllipse&) = delete;

	IAreaTypeEllipse(AsTAtEllipse* pAsTAtEllipse);
	~IAreaTypeEllipse();

	//********************************************************************
	/// 设置椭圆数据半长轴
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @param[in]	dSemiMajorAxis 椭圆数据半长轴
	//********************************************************************
	void SetSemiMajorAxis(double dSemiMajorAxis);

	//********************************************************************
	/// 获取椭圆数据半长轴
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @return 椭圆数据半长轴
	//********************************************************************
	double GetSemiMajorAxis();

	//********************************************************************
	/// 设置椭圆数据半短轴
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @param[in]	dSemiMinorAxis 椭圆数据半短轴
	//********************************************************************
	void SetSemiMinorAxis(double dSemiMinorAxis);

	//********************************************************************
	/// 获取椭圆数据半短轴
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @return 椭圆数据半短轴
	//********************************************************************
	double GetSemiMinorAxis();

	//********************************************************************
	/// 设置椭圆数据方位角
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @param[in]	dBearing 椭圆数据方位角
	//********************************************************************
	void SetBearing(double dBearing);

	//********************************************************************
	/// 获取椭圆数据方位角
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @return 椭圆数据方位角
	//********************************************************************
	double GetBearing();

private:
	AsTAtEllipse*					m_pAsTAtEllipse;						//C对象椭圆数据
};
