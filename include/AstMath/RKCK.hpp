/// @file      RKCK.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-17

#pragma once

#include "AstGlobal.h"
#include "AstMath/ODEVarStepIntegrator.hpp"

AST_NAMESPACE_BEGIN

/// @brief  Runge-Kutta Cash-Karp 方法
/// @details  
/// 参考文献：A Variable Order Runge-Kutta Method for Initial Value Problems with Rapidly Varying Right-Hand Sides
/// @ingroup ODE
class AST_MATH_API RKCK : public ODEVarStepIntegrator
{
public:
    AST_OBJECT(RKCK);
    errc_t initialize(ODE& ode) final;

    errc_t singleStep(ODE& ode, double* y, double t0, double step) final;
};

AST_NAMESPACE_END
