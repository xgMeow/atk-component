/// @file      DetectorEpoch.hpp
/// @brief
/// @details
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-18

#pragma once

#include "AstGlobal.h"
#include "EventDetector.hpp"
#include "AstCore/TimePoint.hpp"

AST_NAMESPACE_BEGIN

class AST_CORE_API DetectorEpoch final: public EventDetector
{
public:
    AST_OBJECT(DetectorEpoch)
    DetectorEpoch() = default;
    double getValue(const SpacecraftState& state, double t) const override;
    double getDifference(const SpacecraftState& state, double t) const override;
public:
    void setGoal(const TimePoint& time);
    const TimePoint& goal() const{return goal_;}
private:
    TimePoint goal_{};        ///< 目标时间
};

AST_NAMESPACE_END
