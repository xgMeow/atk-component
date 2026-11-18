/// @file      SpiceFrameRegistry.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-06

#pragma once

#include "AstGlobal.h"
#include "AstCore/Frame.hpp"
#include <unordered_map>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Spice
    @{
*/

class AST_SPICE_API SpiceFrameRegistry
{
public:
    SpiceFrameRegistry() = default;
    explicit SpiceFrameRegistry(bool whetherInit);
    ~SpiceFrameRegistry() = default;

    static SpiceFrameRegistry& Instance();

    errc_t init();

    PFrame findFrame(StringView name) const;

private:
    using FrameMap = std::unordered_map<std::string, HFrame>;
    FrameMap frameMap_{};
};



/*! @} */

AST_NAMESPACE_END
