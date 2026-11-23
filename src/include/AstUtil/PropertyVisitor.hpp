/// @file      PropertyVisitor.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-30

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/
class Property;
class PropertyBool;
class PropertyDouble;
class PropertyInt;
class PropertyString;
class PropertyObject;
class PropertyStruct;
class PropertyQuantity;
class PropertyPOD;
class PropertyTimePoint;
class Object;

class PropertyVisitor {
public:
    virtual ~PropertyVisitor() = default;

    /// @brief 访问属性（默认方法）
    /// @param property 属性对象
    /// @param container 容器对象指针
    /// @return errc_t 错误码
    virtual errc_t visit(Property& property, const void* container) = 0;

    /// @brief 访问Bool类型属性
    /// @param property Bool类型属性对象
    /// @param container 容器对象指针
    /// @return errc_t 错误码
    virtual errc_t visit(PropertyBool& property, const void* container) = 0;

    /// @brief 访问Double类型属性
    /// @param property Double类型属性对象
    /// @param container 容器对象指针
    /// @return errc_t 错误码
    virtual errc_t visit(PropertyDouble& property, const void* container) = 0;

    /// @brief 访问Int类型属性
    /// @param property Int类型属性对象
    /// @param container 容器对象指针
    /// @return errc_t 错误码
    virtual errc_t visit(PropertyInt& property, const void* container) = 0;

    /// @brief 访问String类型属性
    /// @param property String类型属性对象
    /// @param container 容器对象指针
    /// @return errc_t 错误码
    virtual errc_t visit(PropertyString& property, const void* container) = 0;

    /// @brief 访问Object类型属性
    /// @param property Object类型属性对象
    /// @param container 容器对象指针
    /// @return errc_t 错误码
    virtual errc_t visit(PropertyObject& property, const void* container) = 0;

    /// @brief 访问Struct类型属性
    /// @param property Struct类型属性对象
    /// @param container 容器对象指针
    /// @return errc_t 错误码
    virtual errc_t visit(PropertyStruct& property, const void* container) = 0;

    /// @brief 访问Quantity类型属性
    /// @param property Quantity类型属性对象
    /// @param container 容器对象指针
    /// @return errc_t 错误码
    virtual errc_t visit(PropertyQuantity& property, const void* container) = 0;

    /// @brief 访问POD类型属性
    /// @param property POD类型属性对象
    /// @param container 容器对象指针
    /// @return errc_t 错误码
    virtual errc_t visit(PropertyPOD& property, const void* container) = 0;

    /// @brief 访问TimePoint类型属性
    /// @param property TimePoint类型属性对象
    /// @param container 容器对象指针
    /// @return errc_t 错误码
    virtual errc_t visit(PropertyTimePoint& property, const void* container) = 0;
};

/*! @} */

AST_NAMESPACE_END