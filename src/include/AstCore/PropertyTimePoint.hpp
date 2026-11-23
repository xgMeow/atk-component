/// @file      PropertyTimePoint.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-29

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Property.hpp"
#include "AstCore/TimePoint.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup RTTI
    @{
*/

/// @brief 时间点属性
/// @details 时间点属性，包含属性的名称、描述等信息
class AST_CORE_API PropertyTimePoint : public Property
{
public:
    using InputType  = TimePoint;
    using OutputType = TimePoint;
public:
    using Property::Property;
    using Property::getValue;
    errc_t getValueBool(const void* container, bool& value) override;
    errc_t setValueBool(void* container, bool value) override;
    errc_t getValueInt(const void* container, int& value) override;
    errc_t setValueInt(void* container, int value) override;
    errc_t getValueDouble(const void* container, double& value) override;
    errc_t setValueDouble(void* container, double value) override;
    errc_t getValueString(const void* container, std::string& value) override;
    errc_t setValueString(void* container, StringView value) override;
    EValueType getValueType() const override{return EValueType::eTimePoint;}

    /// @brief 接受访问者
    /// @param visitor 访问者对象
    /// @param container 容器对象指针
    /// @return errc_t 错误码
    errc_t accept(PropertyVisitor& visitor, const void* container) override;
public:
    /// @brief 设置属性值（时间点类型）
    /// @param container 容器指针
    /// @param value 属性值指针
    /// @return 0 成功，其他值 失败
    errc_t setValue(void* container, const InputType* value)
    {
        return setter_(container, value);
    }
    /// @brief 获取属性值（时间点类型）
    /// @param container 容器指针
    /// @param value 属性值指针
    /// @return 0 成功，其他值 失败
    errc_t getValue(const void* container, OutputType* value)
    {
        return getter_(container, value);
    }
};

/*! @} */

AST_NAMESPACE_END