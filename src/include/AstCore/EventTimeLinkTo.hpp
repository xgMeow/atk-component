/// @file      EventTimeLinkTo.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-14

#pragma once

#include "AstGlobal.h"
#include "AstCore/EventTime.hpp"
#include <string>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AST_CORE_API EventTimeLinkTo : public EventTime
{
public:
    static EventTimeLinkTo* New(StringView name, StringView absolutePath);

    EventTimeLinkTo(StringView name, StringView absolutePath);
    EventTimeLinkTo() = default;
    ~EventTimeLinkTo() = default;
public:
    errc_t getTime(TimePoint& tp) const override;
protected:
    std::string name_;
    std::string absolutePath_;
};

/*! @} */

AST_NAMESPACE_END