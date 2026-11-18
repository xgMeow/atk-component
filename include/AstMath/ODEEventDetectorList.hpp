/// @file      ODEEventsHandler.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-27

#pragma once

#include "AstGlobal.h"
#include "AstMath/ODEEventObserver.hpp"
#include <vector>

AST_NAMESPACE_BEGIN

class ODEEventObserver;

class AST_MATH_API ODEEventDetectorList: public ODEStateObserver
{
public:
    ~ODEEventDetectorList() override;
    ODEEventDetectorList() = default;

    EODEAction onStateUpdate(double* y, double& x, ODEIntegrator* integrator) final;

    void addEventDetector(ODEEventDetector* detector);

    void removeEventDetector(ODEEventDetector* detector);

    bool empty() const { return eventObservers_.empty(); }

    size_t size() const { return eventObservers_.size(); }

    /// @brief 清除所有事件探测观察者
    /// @details 与 ODEStateObserverList::clear() 行为一致，会释放观察者对象
    void clear();

    void reset();

    ODEEventObserver& operator[](size_t index) { return *eventObservers_[index]; }
    const ODEEventObserver& operator[](size_t index) const { return *eventObservers_[index]; }
protected:
    std::vector<ODEEventObserver*> eventObservers_{};
};


AST_NAMESPACE_END
