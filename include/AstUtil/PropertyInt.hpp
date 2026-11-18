/// @file      PropertyInt.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-10

#pragma once

#include "AstGlobal.h"
#include "Property.hpp"

AST_NAMESPACE_BEGIN


/// @brief 反射属性类（int类型）
/// @details 反射属性类（int类型），包含属性的名称、描述等信息
/// @ingroup RTTI
class AST_UTIL_API PropertyInt: public Property
{
public:
    using Property::Property;
    using Property::getValue;
    using InputType = int;
    using OutputType = int;
    errc_t getValueBool(const void* container, bool& value) override;
    errc_t setValueBool(void* container, bool value) override;
    errc_t getValueInt(const void* container, int& value) override;
    errc_t setValueInt(void* container, int value) override;
    errc_t getValueString(const void* container, std::string& value) override;
    errc_t setValueString(void* container, StringView value) override;
    errc_t getValueDouble(const void* container, double& value) override;
    errc_t setValueDouble(void* container, double value) override;
    EValueType getValueType() const override{return EValueType::eInt;}

    /// @brief 接受访问者
    /// @param visitor 访问者对象
    /// @param container 容器对象指针
    /// @return errc_t 错误码
    errc_t accept(PropertyVisitor& visitor, const void* container) override;

protected:
    /// @brief 设置属性值（int类型）
    /// @param container 容器指针
    /// @param value 属性值指针
    /// @return 0 成功，其他值 失败
    A_ALWAYS_INLINE
    errc_t setValue(void* container, const InputType* value)
    {
        return setter_(container, value);
    }
    /// @brief 获取属性值（int类型）
    /// @param container 容器指针
    /// @param value 属性值指针
    /// @return 0 成功，其他值 失败
    A_ALWAYS_INLINE
    errc_t getValue(const void* container, OutputType* value)
    {
        return getter_(container, value);
    }
};


AST_NAMESPACE_END