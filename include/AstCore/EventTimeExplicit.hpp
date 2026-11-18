/// @file      EventTimeExplicit.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-14

#pragma once

#include "AstGlobal.h"
#include "AstCore/EventTime.hpp"
#include "AstCore/TimePoint.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 显式事件时间
class AST_CORE_API EventTimeExplicit final: public EventTime
{
public:
    AST_OBJECT(EventTimeExplicit)
    AST_PROPERT(Time)
    static EventTimeExplicit* New(const TimePoint& time);
    static SharedPtr<EventTimeExplicit> MakeShared(const TimePoint& time);

    EventTimeExplicit() = default;
    explicit EventTimeExplicit(const TimePoint& time);
    ~EventTimeExplicit() override = default;
    std::string getRepresentation() const override;
PROPERTIES:
    errc_t getTime(TimePoint& time) const override;
    void setTime(const TimePoint& time);
protected:
    TimePoint time_{};
};

/*! @} */

AST_NAMESPACE_END
