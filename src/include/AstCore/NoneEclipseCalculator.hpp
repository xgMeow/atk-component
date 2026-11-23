/// @file      NoneEclipseCalculator.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-10

#pragma once

#include "AstGlobal.h"
#include "AstCore/EclipseCalculator.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 空阴影光照计算器（无阴影模型）
/// @details 不计算任何阴影，始终返回全光照（1.0）。
///          用于无需考虑阴影影响的场景，或作为默认/占位计算器。
///          采用空对象模式（Null Object Pattern），避免空指针检查。
class AST_CORE_API NoneEclipseCalculator : public EclipseCalculator
{
public:
    NoneEclipseCalculator() = default;
    explicit NoneEclipseCalculator(CelestialBody* lightSource)
        : EclipseCalculator(lightSource)
    {
    }
    ~NoneEclipseCalculator() = default;

    /// @brief 始终返回全光照
    /// @param time 时间点（未使用）
    /// @param position 观测者位置（未使用）
    /// @param frame 观测者所在参考系（未使用）
    /// @return 始终为 1.0（全光照）
    double getLightingRatio(const TimePoint& time, const Vector3d& position, Frame* frame) override{return 1.0;}
};

/*! @} */

AST_NAMESPACE_END
