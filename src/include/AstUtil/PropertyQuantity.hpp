/// @file      PropertyQuantity.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-18

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Quantity.hpp"
#include "AstUtil/PropertyDouble.hpp"
#include "AstUtil/Dimension.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup RTTI
    @{
*/


/// @brief 数量值属性
/// @details 数量值属性，包含属性的名称、描述等信息
/// @ingroup RTTI
class AST_UTIL_API PropertyQuantity: public PropertyDouble
{
public:
    PropertyQuantity(FPropertyGet getter, FPropertySet setter, Dimension dimension);
    PropertyQuantity(StringView name, StringView desc, FPropertyGet getter, FPropertySet setter, Dimension dimension);

    errc_t accept(PropertyVisitor& visitor, const void* container) override;
    errc_t getValueString(const void* container, std::string& value) override;
    errc_t setValueString(void* container, StringView value) override;
    EValueType getValueType() const override{return EValueType::eQuantity;}
protected:
    Dimension dimension_{Dimension::Unit()};   ///< 数量值属性的量纲
};

/*! @} */

AST_NAMESPACE_END
