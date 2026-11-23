/// @file      LibraryLoader.hpp
/// @brief     
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      16.11.2025

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Platform
    @{
*/

/// @brief 加载动态库
/// @param filepath 动态库路径（C 字符串）
/// @return 库句柄，失败返回 nullptr
AST_UTIL_API void* aLoadLibrary(const char* filepath);

/// @brief 加载动态库（StringView 重载）
/// @return 库句柄，失败返回 nullptr
AST_UTIL_API void* aLoadLibrary(StringView filepath);


/// @brief 从动态库中查询函数指针
/// @param lib 动态库
/// @param funcName 函数名称
/// @return 
AST_UTIL_CAPI void* aGetProcAddress(void* lib, const char* funcName);


/// @brief 从动态库中获取函数指针
/// @param filepath 动态库路径
/// @param funcName 函数名称
/// @return 
AST_UTIL_CAPI void* aResolveProcAddress(const char* filepath, const char* funcName);


/// @brief 卸载动态库
/// @param lib 动态库句柄
/// @return 0: 成功
AST_UTIL_CAPI errc_t aFreeLibrary(void* lib);


/// @brief 获取最后的错误信息
/// @return 错误信息字符串
AST_UTIL_CAPI const char* aGetLoadError();


/// @brief 判断文件名是否具有有效的动态库后缀
/// @param fileName 文件名
/// @return 是否为有效的库后缀
AST_UTIL_CAPI bool aIsLibrary(StringView fileName);


/*! @} */

AST_NAMESPACE_END

