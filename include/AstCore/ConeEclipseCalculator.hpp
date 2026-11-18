/// @file      ConeEclipseCalculator.hpp
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

/// @brief 双锥阴影模型光照计算器
/// @details 使用双锥阴影模型（本影-半影模型）计算光照强度。该模型考虑光源的视张角，
///          当光源（如太阳）被遮挡体（如地球）部分遮挡时，可计算出0~1之间的半影光照比例。
///          - 全光照（1）：光源与遮挡体视圆盘相离
///          - 全阴影（0）：光源完全被遮挡体遮蔽
///          - 半影（0~1）：光源部分被遮挡，按被遮挡立体角比例计算
class AST_CORE_API ConeEclipseCalculator final: public EclipseCalculator
{
public:
    ConeEclipseCalculator() = default;
    ~ConeEclipseCalculator() = default;

    /// @brief 计算光照强度（含半影）
    /// @param time 时间点
    /// @param position 观测者位置（相对于 frame 坐标系）
    /// @param frame 观测者所在参考系
    /// @return 光照强度, 0: 全阴影, 1: 全光照，0-1: 部分遮挡（半影）
    double getLightingRatio(const TimePoint& time, const Vector3d& position, Frame* frame) override;

    /// @brief 计算光照强度（含半影），并返回造成最暗遮蔽的遮挡体
    /// @param time 时间点
    /// @param position 观测者位置（相对于 frame 坐标系）
    /// @param frame 观测者所在参考系
    /// @param obstructionOut 输出：给出最小光照比的遮挡体（全光照时为 nullptr；可为 nullptr 表示不关心）
    /// @return 光照强度, 0: 全阴影, 1: 全光照，0-1: 部分遮挡（半影）
    double getLightingRatio(const TimePoint& time, const Vector3d& position, Frame* frame,
                            CelestialBody** obstructionOut);
};



/*! @} */

AST_NAMESPACE_END
