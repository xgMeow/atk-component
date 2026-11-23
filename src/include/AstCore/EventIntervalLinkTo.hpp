/// @file      EventIntervalLinkTo.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-14

#pragma once

#include "AstGlobal.h"
#include "AstCore/EventInterval.hpp"
#include <string>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AST_CORE_API EventIntervalLinkTo : public EventInterval
{
public:
    static EventIntervalLinkTo* New(StringView name, StringView absolutePath);

    EventIntervalLinkTo(StringView name, StringView absolutePath);
    EventIntervalLinkTo() = default;
    ~EventIntervalLinkTo() = default;
public:
    errc_t getInterval(TimeInterval& interval) const override;
protected:
    std::string name_;
    std::string absolutePath_;
};

/*! @} */

AST_NAMESPACE_END
