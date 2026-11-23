/// @file      EventTime.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-14

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Object.hpp"
#include "AstUtil/ObjectNamed.hpp"
#include "AstCore/TimePoint.hpp"
#include "AstCore/ReflectAPI.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class EventTime;
using PEventTime = EventTime*;
using HEventTime = SharedPtr<EventTime>;


/// @brief 事件时间
/// @details 
class AST_CORE_API EventTime: public ObjectNamed
{
public:
    AST_OBJECT(EventTime)

    static EventTime* Resolve(StringView value);

    virtual ~EventTime() override = default;
    /// @brief 获取时间点
    /// @param tp 时间点
    /// @return 
    virtual errc_t getTime(TimePoint& tp) const = 0;

};

/*! @} */

AST_NAMESPACE_END
