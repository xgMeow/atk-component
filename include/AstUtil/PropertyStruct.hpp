/// @file      PropertyStruct.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-09

#pragma once

#include "AstGlobal.h"
#include "Property.hpp"

AST_NAMESPACE_BEGIN

/// @brief 结构体属性
/// @details 结构体属性，包含属性的名称、描述等信息
/// @ingroup RTTI
class AST_UTIL_API PropertyStruct: public Property
{
public:
    using Property::Property;
    using OutputType = void*;
    using InputType = void;
protected:
    /// @brief 设置属性值（结构体类型）
    /// @param container 容器指针
    /// @param value 属性值指针
    /// @return 0 成功，其他值 失败
    A_ALWAYS_INLINE
    errc_t setValue(void* container, const InputType* value)
    {
        return setter_(container, value);
    }
    /// @brief 获取属性值（结构体类型）
    /// @param container 容器指针
    /// @param value 属性值指针
    /// @return 0 成功，其他值 失败
    A_ALWAYS_INLINE
    errc_t getValue(void* container, OutputType* value)
    {
        return getter_(container, value);
    }
public:
    /// @brief 接受访问者
    /// @param visitor 访问者对象
    /// @param container 容器对象指针
    /// @return errc_t 错误码
    errc_t accept(PropertyVisitor& visitor, const void* container) override;

};


AST_NAMESPACE_END