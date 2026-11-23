/// @file      Optim.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-08-17

#pragma once

/*!
    @ingroup Math
    @defgroup Optim 一维优化
    @brief 提供一维函数优化相关功能
    @details
    本模块提供了一维函数优化功能，包括：
    - golden-section 黄金分割搜索（求极小值）
    - brent 方法（反抛物线插值 + 黄金分割，求极小值）
*/

#include "AstMath/UnaryOptimizer.hpp"
#include "AstMath/BrentOptimizer.hpp"
#include "AstMath/GoldenSectionOptimizer.hpp"
