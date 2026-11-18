/// @file      ODEInnerStateObserver.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-28

#pragma once

#include "AstGlobal.h"
#include "AstMath/ODEStateObserver.hpp"

AST_NAMESPACE_BEGIN

class ODEIntegrator;

class AST_MATH_API ODEInnerStateObserver : public ODEStateObserver
{
public:
    explicit ODEInnerStateObserver(ODEIntegrator* integrator)
        : integrator_(integrator) {}
    ODEInnerStateObserver(const ODEInnerStateObserver&) = delete;
    ODEInnerStateObserver& operator=(const ODEInnerStateObserver&) = delete;
    ~ODEInnerStateObserver() = default;
    EODEAction onStateUpdate(double* y, double& x, ODEIntegrator* integrator) final;
protected:
    ODEIntegrator* integrator_ = nullptr;
};

AST_NAMESPACE_END
