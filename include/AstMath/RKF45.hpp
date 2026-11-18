/// @file      RKF45.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-17

#pragma once

#include "AstGlobal.h"
#include "AstMath/ODEVarStepIntegrator.hpp"

AST_NAMESPACE_BEGIN

/// @brief     Runge-Kutta-Fehlberg 4(5) 积分器
/// @details   
/// 参考文献：Classical fourth- and lower order Runge-Kutta formulas with stepsize control and their application to heat transfer problems
/// @ingroup ODE
class AST_MATH_API RKF45 : public ODEVarStepIntegrator
{
public:
    AST_OBJECT(RKF45);
    errc_t initialize(ODE& ode) final;

    errc_t singleStep(ODE& ode, double* y, double t0, double step) final;
};

AST_NAMESPACE_END
