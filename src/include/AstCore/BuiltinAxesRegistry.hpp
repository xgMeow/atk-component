/// @file      BuiltinAxesRegistry.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-05

#pragma once

#include "AstGlobal.h"
#include "AstCore/Axes.hpp"
#include <unordered_map>
#include <string>


AST_NAMESPACE_BEGIN

/*!
    @addtogroup Spice
    @{
*/

/// @brief      内建轴系注册器
class AST_CORE_API BuiltinAxesRegistry
{
public:
    BuiltinAxesRegistry() = default;
    explicit BuiltinAxesRegistry(bool whetherInit);
    ~BuiltinAxesRegistry() = default;
    static BuiltinAxesRegistry& Instance();

    PAxes getAxes(StringView name) const;
    errc_t init();
protected:
    using AxesMap = std::unordered_map<std::string, HAxes>;
    AxesMap axesMap_;
};

/*! @} */

AST_NAMESPACE_END
