/// @file      CylindricalEclipseCalculator.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-10

#pragma once

#include "AstGlobal.h"
#include "EclipseCalculator.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 圆柱阴影模型光照计算器
/// @details 使用圆柱阴影模型计算光照强度。该模型假定光源为平行光（光源无穷远），
///          遮挡体在光源反方向投射出一个圆柱形阴影。
///          当观测者位于阴影圆柱内时，返回全阴影（0）；
///          否则返回全光照（1）。
///          该模型没有半影区，结果为二值（0或1）。
class AST_CORE_API CylindricalEclipseCalculator final: public EclipseCalculator
{
public:
    CylindricalEclipseCalculator() = default;
    ~CylindricalEclipseCalculator() = default;

    /// @brief 计算光照强度
    /// @param time 时间点
    /// @param position 观测者位置（相对于 frame 坐标系）
    /// @param frame 观测者所在参考系
    /// @return 光照强度, 0: 全阴影, 1: 全光照（圆柱模型无半影）
    double getLightingRatio(const TimePoint& time, const Vector3d& position, Frame* frame) override;
};



/*! @} */

AST_NAMESPACE_END
