/// @file      GridCoord.hpp
/// @brief     体积网格坐标轴定义
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-29

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/// @brief 网格坐标离散化方法
enum class EGridCoordMethod
{
    eFixedNumSteps,   ///< 固定步数
    eFixedSpacing     ///< 固定间距
};

/// @brief 坐标轴定义
/// @details 描述体积网格单个坐标轴的范围和离散化方式
struct AST_CORE_API GridCoord
{
    EGridCoordMethod method_{EGridCoordMethod::eFixedNumSteps};  ///< 离散化方法
    double           minValue_{0.0};                              ///< 坐标最小值
    double           maxValue_{0.0};                              ///< 坐标最大值
    int              numSteps_{10};                               ///< 步数
};

AST_NAMESPACE_END
