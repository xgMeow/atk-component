/// @file      ColoredPrint.hpp
/// @brief     彩色打印功能
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-10

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Color.hpp"
#include "AstUtil/ColorNamed.hpp"
#include <stdio.h>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Util
	@{
*/


/// @brief 彩色打印函数
/// @param color 颜色
/// @param format 格式化字符串
/// @param args 可变参数列表
/// @return 输出字符数
AST_UTIL_CAPI int cvprintf(Color color, const char* format, va_list args);

/// @brief 彩色打印函数
/// @param color 颜色
/// @param stream 流
/// @param format 格式化字符串
/// @param args 可变参数列表
/// @return 输出字符数
AST_UTIL_CAPI int cvfprintf(Color color, FILE* stream, const char* format, va_list args);


/// @brief 彩色打印函数
/// @param color 颜色
/// @param format 格式化字符串
/// @param ... 可变参数
/// @return 输出字符数
AST_UTIL_CAPI int cprintf(Color color, const char* format, ...);


/// @brief 彩色打印函数
/// @param color 颜色
/// @param stream 流
/// @param format 格式化字符串
/// @param ... 可变参数
/// @return 输出字符数
AST_UTIL_CAPI int cfprintf(Color color, FILE* stream, const char* format, ...);


/*! @} */


AST_NAMESPACE_END
