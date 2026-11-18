/// @file      FixedStepAccessStepper.hpp
/// @brief     固定步长步进器
/// @details   以固定时间步长在时间范围内生成采样点。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-22

#pragma once

#include "AccessStepper.hpp"

AST_NAMESPACE_BEGIN

/// @brief 固定步长步进器
class AST_CORE_API FixedStepAccessStepper : public AccessStepper
{
public:
    AST_OBJECT(FixedStepAccessStepper)

    FixedStepAccessStepper() = default;

    /// @brief 构造固定步长步进器
    /// @param stepSize 步长（秒）
    explicit FixedStepAccessStepper(double stepSize);

    void init(const TimePoint& start, const TimePoint& stop) override;

    /// @brief 获取第一个采样时刻（即时间范围起点）
    bool first(TimePoint& tp) override;

    /// @brief 获取下一个采样时刻（起点之后每隔 stepSize 取一个）
    bool next(TimePoint& tp) override;

    void setStepSize(double step) { stepSize_ = step; }
    double stepSize() const { return stepSize_; }

private:
    double     stepSize_{60.0};
    TimePoint  start_{};
    TimePoint  stop_{};
    TimePoint  current_{};
};

AST_NAMESPACE_END
