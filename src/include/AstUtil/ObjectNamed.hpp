/// @file      ObjectNames.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-10

#pragma once

#include "AstGlobal.h"
#include "Object.hpp"
#include "AstUtil/StringView.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 命名对象
class AST_UTIL_API ObjectNamed: public Object
{
public:
    /// @brief 默认构造函数
    ObjectNamed() = default;

    /// @brief 构造函数
    /// @param name 对象名称
    explicit ObjectNamed(StringView name)
        : name_(name)
    {}

    /// @brief 获取对象名称
    const std::string& getName() const override { return name_; }

    /// @brief 设置对象名称
    void setName(StringView name) override { name_ = std::string(name); }
private:
    std::string name_{};      ///< 对象名称
};


/*! @} */

AST_NAMESPACE_END
