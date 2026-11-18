/// @file      ObjectResolver.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-17

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Object.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 对象解析器
/// @details 用于解析对象的延迟链接
class ObjectResolver
{
public:
    ObjectResolver() = default;

    virtual ~ObjectResolver() = default;

    /// @brief 解析对象
    /// @details 解析对象的延迟链接
    /// @return 解析后的对象指针
    virtual Object* resolve() const = 0;

    /// @brief 获取期望的类型元信息
    /// @details Class* 类型元信息指针
    /// @return Class* 类型元信息指针
    virtual Class* getExpectedType() const {return Object::StaticType();};
};


/*! @} */

AST_NAMESPACE_END
