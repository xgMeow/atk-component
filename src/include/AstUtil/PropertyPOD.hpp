/// @file      PropertyPOD.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-09

#pragma once

#include "AstGlobal.h"
#include "Property.hpp"

AST_NAMESPACE_BEGIN

/// @brief 反射属性类（POD类型: plain old data）
/// @details POD类型是指简单的数据类型，如int、float、double、bool等。
/// @todo 拟作为int, double, bool等的基础属性类，其他属性类继承自该类。
/// @ingroup RTTI
class AST_UTIL_API PropertyPOD : public Property
{
public:
    using Property::Property;

    /// @brief 接受访问者
    /// @param visitor 访问者对象
    /// @param container 容器对象指针
    /// @return errc_t 错误码
    errc_t accept(PropertyVisitor& visitor, const void* container) override;

protected:

};

AST_NAMESPACE_END