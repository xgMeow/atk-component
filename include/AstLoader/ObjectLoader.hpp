/// @file      ObjectLoader.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-07

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Object.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 加载对象
/// @details 从文件加载对象
/// @param filepath 文件路径
/// @param object 加载的对象
/// @return errc_t 加载结果
// errc_t aLoadObject(StringView filepath, SharedPtr<Object>& object);


/// @brief 加载对象
/// @details 从文件加载对象
/// @param filepath 文件路径
/// @param objectType 对象类型
/// @param object 加载的对象
/// @return errc_t 加载结果
AST_LOADER_API errc_t aLoadObject(StringView filepath, StringView objectType, SharedPtr<Object>& object);


/*! @} */

AST_NAMESPACE_END
