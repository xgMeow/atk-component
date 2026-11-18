/// @file      Field.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-09

#pragma once

#include "AstGlobal.h"
#include <string>                   // for std::string
#include "AstUtil/StringView.hpp"   // for StringView

AST_NAMESPACE_BEGIN


/// @brief 反射字段类
/// @details 反射字段类，包含字段的名称、描述等信息
/// @ingroup RTTI
class AST_UTIL_API Field
{
public:
    Field() : name_(), desc_() {}

    explicit Field(StringView name, StringView desc = "")
        : name_(name), desc_(desc)
    {}

    virtual ~Field() = default;

    /// @brief 获取字段名称
    const std::string& name() const{return name_;}

    /// @brief 设置字段名称
    /// @param name 字段名称
    void setName(StringView name){name_ = std::string(name);}

    /// @brief 获取字段描述
    const std::string& desc() const{return desc_;}

    /// @brief 设置字段描述
    /// @param desc 字段描述
    void setDesc(StringView desc){desc_ = std::string(desc);}
protected:
    //@todo: 考虑使用StringView来提升效率

    std::string name_;  ///< 名称
    std::string desc_;  ///< 描述
};


AST_NAMESPACE_END