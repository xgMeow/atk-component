/// @file      ODEStepHandlerList.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-27

#pragma once

#include "AstGlobal.h"
#include "AstMath/ODEStateObserver.hpp"
#include <vector>

AST_NAMESPACE_BEGIN

class AST_MATH_API ODEStateObserverList: public ODEStateObserver
{
public:
    ODEStateObserverList() = default;
    ~ODEStateObserverList() override;

    EODEAction onStateUpdate(double* y, double& x, ODEIntegrator* integrator) override;

    void addStateObserver(ODEStateObserver* observer){ observers_.push_back(observer); }
    void removeStateObserver(ODEStateObserver* observer);

    bool empty() const { return observers_.empty(); }

    size_t size() const { return observers_.size(); }

    void clear();

    ODEStateObserver& operator[](size_t index) { return *observers_[index]; }
    const ODEStateObserver& operator[](size_t index) const { return *observers_[index]; }
protected:
    std::vector<ODEStateObserver*> observers_{};
};

AST_NAMESPACE_END
