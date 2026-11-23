/// @file      EventInterval.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-14

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Object.hpp"
#include "AstUtil/ObjectNamed.hpp"
#include "AstCore/TimeInterval.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class EventInterval;
using PEventInterval = EventInterval*;
using HEventInterval = SharedPtr<EventInterval>;

/// @brief 事件时间段
class AST_CORE_API EventInterval: public ObjectNamed
{
public:
    /// @brief 获取时间段
    /// @param interval 
    /// @return 
    virtual errc_t getInterval(TimeInterval& interval) const = 0;
};

/*! @} */

AST_NAMESPACE_END
