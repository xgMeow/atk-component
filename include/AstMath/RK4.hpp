/// @file      RK4.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-17

#pragma once

#include "AstGlobal.h"
#include "AstMath/ODEFixedStepIntegrator.hpp"

AST_NAMESPACE_BEGIN

/// @brief     RK4 积分器
/// @details   4阶龙格库塔方法 (The 4th order Runge-Kutta method)
/// @ingroup ODE
class AST_MATH_API RK4 : public ODEFixedStepIntegrator
{
public:
    errc_t initialize(ODE& ode) final;

    errc_t singleStep(ODE& ode, double* y, double t0, double step) final;
};



AST_NAMESPACE_END
