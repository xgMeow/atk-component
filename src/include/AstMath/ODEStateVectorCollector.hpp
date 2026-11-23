/// @file      ODEVectorCollector.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-25

#pragma once

#include "AstGlobal.h"
#include "AstMath/ODEStateObserver.hpp"
#include <vector>

AST_NAMESPACE_BEGIN

/// @brief ODE积分的状态向量收集器
/// @details 
/// 该类用于收集ODE积分过程中的状态向量。
class AST_MATH_API ODEStateVectorCollector: public ODEStateObserver
{
public:
    explicit ODEStateVectorCollector(int ndim);
    ~ODEStateVectorCollector() = default;

    EODEAction onStateUpdate(double* y, double& x, ODEIntegrator* integrator) override;

    std::vector<double>& x(){ return x_; };
    std::vector<std::vector<double>>& y(){ return y_; };
protected:
    int ndim_;
    std::vector<double> x_;
    std::vector<std::vector<double>> y_;
};

AST_NAMESPACE_END
