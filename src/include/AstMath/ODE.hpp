/// @file      ODE.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-17

#pragma once

/*!
    @ingroup Math
    @defgroup ODE 常微分方程求解
    @brief 提供常微分方程的数值求解方法
    @details
    本模块提供了多种常微分方程的数值求解方法，包括：
    - 定步长方法（RK4、RK8、RKV8）
    - 自适应步长方法（RKF45、RKF56、RKF78、RKCK）
*/

#include "AstGlobal.h"
#include "AstMath/OrdinaryDifferentialEquation.hpp"
#include "AstMath/RK4.hpp"
#include "AstMath/RK8.hpp"
#include "AstMath/RKCK.hpp"
#include "AstMath/RKF45.hpp"
#include "AstMath/RKF56.hpp"
#include "AstMath/RKF78.hpp"
#include "AstMath/RKV8.hpp"

// AST_MATH_CAPI errc_t aIntegrateConst(ODEIntegrator& integrator, ODE& ode, double* y, double t0, double tf);

