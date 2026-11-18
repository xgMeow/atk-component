/// @file      NLE.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-28

#pragma once

/*!
    @ingroup Math
    @defgroup NLE 非线性方程求解
    @brief 提供非线性方程求解相关功能
    @details
    本模块提供了非线性方程求解功能，包括：
    - secant 方法
    - ridder 方法
    - brent 方法
    - bisection 方法
*/

#include "AstMath/SecantSolver.hpp"
#include "AstMath/RidderSolver.hpp"
#include "AstMath/BrentSolver.hpp"
#include "AstMath/BisectionSolver.hpp"