/// @file      DifferentiationSettings.hpp
/// @brief     空间计算的导数/时间差分设置
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-29

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/// @brief 导数/时间差分设置
struct AST_CORE_API DifferentiationSettings
{
    double diffTimeStep_{0.1};  ///< 差分时间步长（秒）
};

AST_NAMESPACE_END
