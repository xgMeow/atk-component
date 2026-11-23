/// @file      SimTime.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-18

#pragma once

#include "AstGlobal.h"
#include "AstCore/TimePoint.hpp"

AST_NAMESPACE_BEGIN

/// @brief 仿真时间
/// @details 仿真时间类，包含仿真时间点和相对于参考时间点已经过的时间。
class SimTime{
public:
    /// @brief 获取仿真时间点
    /// @return 仿真时间点
    const TimePoint& timePoint() const { return timePoint_; }
    /// @brief 获取已经过时间
    /// @return 已经过时间
    double elapsedTime() const { return elapsedTime_; }
    /// @brief 设置仿真时间点
    /// @param timePoint 仿真时间点
    void setTimePoint(const TimePoint& timePoint) { timePoint_ = timePoint; }
    /// @brief 设置已经过时间
    /// @param elapsedTime 已经过时间
    void setElapsedTime(double elapsedTime) { elapsedTime_ = elapsedTime; }
public:
    double elapsedTime_{0.0};       ///< 已经过时间(相对于参考时间点)
    TimePoint timePoint_{};         ///< 仿真时间点
};


AST_NAMESPACE_END
