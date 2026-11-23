/// @file      ODEEventWatcher.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-27

#pragma once

#include "AstGlobal.h"
#include "AstMath/ODEStateObserver.hpp"
#include "AstMath/ODEEventDetector.hpp"
#include <limits>

AST_NAMESPACE_BEGIN


class AST_MATH_API ODEEventObserver: public ODEStateObserver
{
public:
    ODEEventObserver() = default;
    ODEEventObserver(const ODEEventObserver&) = delete;
    ODEEventObserver& operator=(const ODEEventObserver&) = delete;
    explicit ODEEventObserver(ODEEventDetector* detector);
    ~ODEEventObserver() override;
    EODEAction onStateUpdate(double* y, double& x, ODEIntegrator* integrator) final;
    ODEEventDetector* getEventDetector() const { return detector_; }
    bool isEventOccurred(double* y, double& x);
    errc_t findEventTime(double x1, double x2, double& result, ODEIntegrator* integrator);
    void reset();
protected:
    friend class ODEEventDetectorList;
    ODEEventDetector* detector_ {nullptr};
    double lastDifference_ {std::numeric_limits<double>::quiet_NaN()};
    double lastTime_{std::numeric_limits<double>::quiet_NaN()};
    double eventTime_{std::numeric_limits<double>::quiet_NaN()};
    int    repeatCount_{-1};
};

AST_NAMESPACE_END
