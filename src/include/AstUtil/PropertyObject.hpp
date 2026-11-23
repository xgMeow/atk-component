/// @file      PropertyObject.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-09

#pragma once

#include "AstGlobal.h"
#include "Property.hpp"


AST_NAMESPACE_BEGIN

class Object;

/// @brief 反射属性类（对象类型）
/// @details 反射属性类（对象类型），包含属性的名称、描述等信息
/// @ingroup RTTI
class AST_UTIL_API PropertyObject: public Property
{
public:
    using Property::Property;
    using Property::getValue;
    using InputType = Object;
    using OutputType = Object*;
public:
    PropertyObject() = default;

    PropertyObject(const PropertyObject&) = delete;
    PropertyObject& operator=(const PropertyObject&) = delete;

    PropertyObject(FPropertyGet getter, FPropertySet setter, Class* cls);

    errc_t getValueBool(const void* container, bool& value) override;
    errc_t setValueBool(void* container, bool value) override;
    errc_t getValueInt(const void* container, int& value) override;
    errc_t setValueInt(void* container, int value) override;
    errc_t getValueString(const void* container, std::string& value) override;
    errc_t setValueString(void* container, StringView value) override;
    errc_t getValueDouble(const void* container, double& value) override;
    errc_t setValueDouble(void* container, double value) override;
    EValueType getValueType() const override{return EValueType::eObject;}

    /// @brief 设置属性值（对象类型）
    /// @param container 容器指针
    /// @param value 属性值指针
    /// @return 0 成功，其他值 失败
    errc_t setValue(void* container, const InputType* value);
    errc_t getValue(const void* container, OutputType* value);

    Class* getClass() const { return class_; }
public:
    /// @brief 接受访问者
    /// @param visitor 访问者对象
    /// @param container 容器对象指针
    /// @return errc_t 错误码
    errc_t accept(PropertyVisitor& visitor, const void* container) override;
private:
    Class* class_{nullptr};      ///< 期望的对象类指针
};


AST_NAMESPACE_END