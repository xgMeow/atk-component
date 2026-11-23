/// @file      RK8.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-17

#pragma once

#include "AstGlobal.h"
#include "AstMath/ODEFixedStepIntegrator.hpp"

AST_NAMESPACE_BEGIN

/// @brief     RK8 积分器
/// @details   
/// 10级8阶龙格库塔方法 (The 10 stage 8th order Runge-Kutta method)
/// 参考文献：Shanks, E. Baylis "Solutions of Differential Equations by Evaluations of Functions"
/// @ingroup ODE
class AST_MATH_API RK8 : public ODEFixedStepIntegrator
{
public:
    AST_OBJECT(RK8);
    errc_t initialize(ODE& ode) final;

    errc_t singleStep(ODE& ode, double* y, double t0, double step) final;
};


AST_NAMESPACE_END
