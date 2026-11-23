/// @file      StringPosix.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-02-10

#pragma once

#include "AstGlobal.h"
#include <string>
#include <cstring>
#include <cctype>   // for std::isspace

AST_NAMESPACE_BEGIN

typedef std::string String;


namespace posix{

#ifdef _WIN32
/// @brief 比较两个字符串是否相等（不区分大小写）
/// @param str1 第一个字符串
/// @param str2 第二个字符串
/// @return 若相等则返回0，否则返回非0值
A_ALWAYS_INLINE int strcasecmp(const char* str1, const char* str2)
{
	return ::_stricmp(str1, str2);
}

/// @brief 比较两个字符串是否相等（不区分大小写）
/// @param str1 第一个字符串
/// @param str2 第二个字符串
/// @param n 比较的字符数
/// @return 若相等则返回0，否则返回非0值
A_ALWAYS_INLINE int strncasecmp(const char* str1, const char* str2, size_t n)
{
	return ::_strnicmp(str1, str2, n);
}

#else
using ::strcasecmp;
using ::strncasecmp;
#endif

}

// 比较两个字符串是否相等（不区分大小写）
#ifdef _WIN32
using ::stricmp;
using ::strnicmp;
#else

/// @brief 比较两个字符串是否相等（不区分大小写）
/// @param str1 第一个字符串
/// @param str2 第二个字符串
/// @return 若相等则返回0，否则返回非0值
A_ALWAYS_INLINE int stricmp(const char* str1, const char* str2)
{
	return ::strcasecmp(str1, str2);
}

/// @brief 比较两个字符串是否相等（不区分大小写）
/// @param str1 第一个字符串
/// @param str2 第二个字符串
/// @param n 比较的字符数
/// @return 若相等则返回0，否则返回非0值
A_ALWAYS_INLINE int strnicmp(const char* str1, const char* str2, size_t n)
{
	return ::strncasecmp(str1, str2, n);
}

#endif

using posix::strcasecmp;
using posix::strncasecmp;

AST_NAMESPACE_END
