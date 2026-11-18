/// @file      EventIntervalFallback.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-14

#pragma once

#include "AstGlobal.h"
#include "AstCore/EventInterval.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief  支持fallback的事件时间段
/// @details 当第一个EventInterval计算失败时，使用第二个EventInterval的值
class AST_CORE_API EventIntervalFallback : public EventInterval
{
public:
    static EventIntervalFallback* New(EventInterval* primary, EventInterval* fallback);
    static EventIntervalFallback* New(EventInterval* primary, const TimeInterval& fallback);
    static SharedPtr<EventIntervalFallback> MakeShared(EventInterval* primary, EventInterval* fallback);

    EventIntervalFallback() = default;
    EventIntervalFallback(EventInterval* primary, EventInterval* fallback);
    EventIntervalFallback(EventInterval* primary, const TimeInterval& fallback);
    ~EventIntervalFallback() override = default;

    errc_t getInterval(TimeInterval& interval) const override;
    void setPrimary(EventInterval* primary);
    void setFallback(EventInterval* fallback);
protected:
    SharedPtr<EventInterval> primary_{};       ///< 主要事件时间段
    SharedPtr<EventInterval> fallback_{};      ///< 后备事件时间段
};

/*! @} */

AST_NAMESPACE_END