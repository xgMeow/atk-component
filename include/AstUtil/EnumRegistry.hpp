/// @file      EnumRegistry.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-10-09

#pragma once

#include "AstGlobal.h"
#include "EnumDescriptor.hpp"
#include <map>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 枚举注册器
/// @details 用于注册和获取枚举描述符
class AST_UTIL_API EnumRegistry
{   
public:
    EnumRegistry() = default;
    ~EnumRegistry() = default;
    A_DISABLE_COPY(EnumRegistry);

    static EnumRegistry* Instance();

    void registerEnum(StringView name, EnumDescriptorData* descriptor);
    EnumDescriptorData* getEnum(StringView name) const;
private:
    std::map<std::string, EnumDescriptorData*> enums_{};
};




/*! @} */

AST_NAMESPACE_END
