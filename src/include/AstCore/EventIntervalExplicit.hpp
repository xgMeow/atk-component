/// @file      EventIntervalExplicit.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-14

#pragma once

#include "AstGlobal.h"
#include "AstCore/EventInterval.hpp"
#include "AstCore/TimeInterval.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class EventIntervalExplicit;
using PEventIntervalExplicit = EventIntervalExplicit*;
using HEventIntervalExplicit = SharedPtr<EventIntervalExplicit>;

class AST_CORE_API EventIntervalExplicit final: public EventInterval
{
public:
    static PEventIntervalExplicit New(const TimeInterval& interval);
    static PEventIntervalExplicit New(const TimePoint& startTime, const TimePoint& stopTime);
    static HEventIntervalExplicit MakeShared(const TimeInterval& interval);

    EventIntervalExplicit() = default;
    explicit EventIntervalExplicit(const TimeInterval& interval);
    ~EventIntervalExplicit() = default;
    errc_t getInterval(TimeInterval& interval) const override;
protected:
    TimeInterval interval_;     ///< 事件时间段
};

/*! @} */

AST_NAMESPACE_END
