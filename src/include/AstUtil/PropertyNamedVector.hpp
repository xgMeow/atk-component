/// @file      PropertyNamedVector.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-05

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Property.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

#ifndef SWIG

AST_UTIL_API errc_t aFakeGetByString(const void* container, StringView key, Object*& value);
AST_UTIL_API errc_t aFakeGetByIndex(const void* container, size_t key, Object*& value);


/// @brief 命名向量属性
class AST_UTIL_API PropertyNamedVector: public Property
{
public:
    /// @brief 构造函数
    /// @param getterByString 获取属性值的函数指针，用于根据属性键获取属性值
    /// @param getterByIndex 获取属性值的函数指针，用于根据属性索引获取属性值
    PropertyNamedVector(FPropertyGetItemByString getterByString, FPropertyGetItemByIndex getterByIndex)
        : getterByString_(getterByString?getterByString:&aFakeGetByString)
        , getterByIndex_(getterByIndex?getterByIndex:&aFakeGetByIndex)
    {
    }

    /// @brief 获取属性值
    /// @param container 容器指针
    /// @param key 属性键
    /// @param value 属性值
    errc_t getItem(const void* container, StringView key, Object*& value);

    /// @brief 获取属性值
    /// @param container 容器指针
    /// @param key 属性索引
    /// @param value 属性值
    errc_t getItem(const void* container, size_t key, Object*& value);
protected:
    FPropertyGetItemByString getterByString_;   ///< 获取属性值的函数指针，用于根据属性键获取属性值
    FPropertyGetItemByIndex  getterByIndex_;    ///< 获取属性值的函数指针，用于根据属性索引获取属性值
};

#endif

/*! @} */

AST_NAMESPACE_END

