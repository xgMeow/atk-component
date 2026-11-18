/// @file      PropertyNoop.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-01

#pragma once

#include "AstGlobal.h"
#include "Property.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 无操作属性类
/// @details 该属性类不执行任何操作，仅用于占位或默认值
class AST_UTIL_API PropertyNoop final: public Property
{
public:
    static PropertyNoop* Instance();
    using Property::Property;
    errc_t accept(PropertyVisitor& visitor, const void* container) override;
    errc_t getValueDouble(const void* container, double& value) override;
    errc_t setValueDouble(void* container, double value) override;
    errc_t getValueInt(const void* container, int& value) override;
    errc_t setValueInt(void* container, int value) override;
    errc_t getValueBool(const void* container, bool& value) override;
    errc_t setValueBool(void* container, bool value) override;
    errc_t getValueString(const void* container, std::string& value) override;
    errc_t setValueString(void* container, StringView value) override;
    EValueType getValueType() const override{return EValueType::eInvalid;}
};


/*! @} */

AST_NAMESPACE_END
