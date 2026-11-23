/// @file      MotionWithIntervalStep.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-26

#pragma once

#include "AstGlobal.h"
#include "AstSim/MotionProfile.hpp"
#include "AstCore/EventInterval.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief  具有时间段和步长的运动模型
class AST_SIM_API MotionWithIntervalStep : public MotionProfile
{
public:
    using MotionProfile::MotionProfile;
public:
    /// @brief 获取运动时间间隔
    /// @param interval 时间间隔引用
    /// @return 错误码
    errc_t getInterval(TimeInterval& interval) const;

    /// @brief 获取运动时间间隔句柄
    SharedPtr<EventInterval>& getIntervalHandle() { return interval_; }

    /// @brief 设置运动时间间隔
    void setInterval(EventInterval* interval) { interval_ = interval;}

    /// @brief 设置运动时间间隔
    void setInterval(const TimeInterval& interval);

    /// @brief 获取预报步长
    /// @return 预报步长
    double getStepSize() const { return stepSize_; }

    /// @brief 设置预报步长
    /// @param stepSize 预报步长
    void setStepSize(double stepSize) { stepSize_ = stepSize; }
protected:
    SharedPtr<EventInterval>    interval_{};             ///< 时间段
    double                      stepSize_{60.0};        ///< 生成星历步长
};

/*! @} */

AST_NAMESPACE_END
