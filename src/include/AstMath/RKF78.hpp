/// @file      RKF78.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-16

#pragma once

#include "AstGlobal.h"
#include "AstMath/ODEVarStepIntegrator.hpp"

AST_NAMESPACE_BEGIN

/// @brief     RKF78 积分器
/// @details   
/// 参考文献：Classical Fifth-, Sixth-, Seventh-, and Eighth-Order Runge-Kutta Formulas with Stepsize Control
/// @ingroup ODE
class AST_MATH_API RKF78 : public ODEVarStepIntegrator
{
public:
    AST_OBJECT(RKF78);
    errc_t initialize(ODE& ode) final;

    errc_t singleStep(ODE& ode, double* y, double t0, double step) final;
};

AST_NAMESPACE_END
