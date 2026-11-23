/// @file      IdentifierAPI.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-18

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"
#include <string>

AST_NAMESPACE_BEGIN

class Identifier;


/// @brief 创建一个标识符
/// @param str 标识符字符串
/// @return 标识符指针
AST_UTIL_API Identifier* aIdentifier(const std::string& str);

/// @brief 创建一个标识符
/// @param str 标识符字符串
/// @return 标识符指针
AST_UTIL_API Identifier* aIdentifier(const StringView& str);


/// @brief 创建一个标识符
/// @param str 标识符字符串
/// @param len 标识符字符串长度
/// @return 标识符指针
AST_UTIL_API Identifier* aIdentifier(const char* str, size_t len);


/// @brief 创建一个标识符
/// @param str 标识符字符串
/// @return 标识符指针
A_ALWAYS_INLINE Identifier* aIdentifier(const char* str)
{
    return aIdentifier(str,  std::char_traits<char>::length(str));
}


AST_NAMESPACE_END
