/// @file      BodyObstruction.hpp
/// @brief     天体遮挡判断
/// @details   提供视线到天体表面最短距离的计算函数，用于可见性分析中的遮挡约束。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-21

#pragma once

#include "AstGlobal.h"
#include "AstCore/BodyShape.hpp"

AST_NAMESPACE_BEGIN

/// @brief 计算视线到天体表面的最短有符号距离
/// @param observerPos 观测者在天体固连系中的位置
/// @param targetPos 目标在天体固连系中的位置
/// @param bodyShape 天体形状（球体 / 扁球体 / 椭球体）
/// @return 最短距离：>0 视线未穿入天体表面，<0 视线穿入，==0 恰好相切
AST_CORE_API double aLineOfSightClearance(
    const Vector3d& observerPos,
    const Vector3d& targetPos,
    const BodyShape* bodyShape);

/// @brief 便捷方法：视线是否被中心天体遮挡
/// @param observerPos 观测者在天体固连系中的位置
/// @param targetPos 目标在天体固连系中的位置
/// @param bodyShape 天体形状
/// @return true = 被遮挡，false = 无遮挡
inline bool aLineOfSightObstructed(
    const Vector3d& observerPos,
    const Vector3d& targetPos,
    const BodyShape* bodyShape)
{
    return aLineOfSightClearance(observerPos, targetPos, bodyShape) < 0.0;
}

AST_NAMESPACE_END
