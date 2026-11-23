#pragma once
#include "../IAtkObj.h"
#include <vector>
class IAreaTypeEllipse;
class IAreaTypePatternCollection;
class IAreaTarget;

///
/// 常用任务
///
class IATKOBJECT_API IATCommonTasks
{
public:
    IATCommonTasks(const IATCommonTasks&) = delete;
    IATCommonTasks& operator=(const IATCommonTasks&) = delete;

	IATCommonTasks(IAreaTarget* pIAreaTarget);
	~IATCommonTasks();

	//********************************************************************
	/// 设置椭圆数据
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @param[in]	dSemiMajorAxis 椭圆数据半长轴
	/// @param[in]	dSemiMinorAxis 椭圆数据半短轴
	/// @param[in]	dBearing 椭圆数据方位角
	/// @return
	//********************************************************************
	IAreaTypeEllipse* SetAreaTypeEllipse(double dSemiMajorAxis, double dSemiMinorAxis, double dBearing);

	//********************************************************************
	/// 设置椭圆数据
	/// @author	Gan Shu Long
	/// @date	2026-01-15
	/// @note 参数 dSemiMajorAxis：椭圆数据半长轴
	/// @note 参数 dSemiMinorAxis：椭圆数据半短轴
	/// @note 参数 dBearing：椭圆数据方位角
	/// @return
	//********************************************************************
	IAreaTypePatternCollection* SetAreaTypePattern(std::vector<std::vector<double>> vectorVectorDouble);

private:
	IAreaTarget*		m_pIAreaTarget;
};
