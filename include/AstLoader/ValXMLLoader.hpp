/// @file      ValXMLLoader.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-16

#pragma once

#include "AstGlobal.h"
#include "AstUtil/SharedPtr.hpp"
#include "AstScript/Value.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class Value;

/// @brief 加载值
/// @param filepath 值文件路径
/// @param value 加载后的值
/// @return 错误码
AST_LOADER_API errc_t aLoadValue(StringView filepath, SharedPtr<Value>& value);

/// @brief 加载值
/// @param file 值文件指针
/// @param value 加载后的值
/// @return 错误码
AST_LOADER_API errc_t aLoadValue(FILE* file, SharedPtr<Value>& value);

/*! @} */

AST_NAMESPACE_END
