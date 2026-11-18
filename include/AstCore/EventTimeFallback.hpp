/// @file      EventTimeFallback.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-14

#pragma once

#include "AstGlobal.h"
#include "AstCore/EventTime.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief  支持fallback的事件时间
/// @details 当第一个EventTime计算失败时，使用第二个EventTime的值
class AST_CORE_API EventTimeFallback : public EventTime
{
public:
    static EventTimeFallback* New(EventTime* primary, EventTime* fallback);
    static EventTimeFallback* New(EventTime* primary, const TimePoint& fallback);
    static SharedPtr<EventTimeFallback> MakeShared(EventTime* primary, EventTime* fallback);
    static SharedPtr<EventTimeFallback> MakeShared(EventTime* primary, const TimePoint& fallback);


    EventTimeFallback() = default;
    EventTimeFallback(EventTime* primary, EventTime* fallback);
    EventTimeFallback(EventTime* primary, const TimePoint& fallback);

    ~EventTimeFallback() override = default;

    errc_t getTime(TimePoint& tp) const override;
    void setPrimary(EventTime* primary);
    void setFallback(EventTime* fallback);
protected:
    SharedPtr<EventTime> primary_{};       ///< 主要事件时间
    SharedPtr<EventTime> fallback_{};      ///< 后备事件时间
};

/*! @} */

AST_NAMESPACE_END