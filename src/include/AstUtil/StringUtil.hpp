/// @file      StringUtil.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-02-10

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"
#include "AstUtil/StringPosix.hpp"
#include "AstUtil/StringSplit.hpp"
#include <string>   // for std::string
#include <cctype>   // for isspace(), tolower(), toupper()

AST_NAMESPACE_BEGIN

/*!
    @addtogroup String
    @{
*/


/// @brief 比较两个字符串是否相等（不区分大小写）
/// @param str1 第一个字符串
/// @param str2 第二个字符串
/// @return 若相等则返回true，否则返回false
bool aEqualsIgnoreCase(StringView piece1, StringView piece2) noexcept;


/// @brief 移除字符串首尾的ASCII空白字符
/// @param str 输入字符串
/// @return 移除首尾空白字符后的字符串视图
StringView aStripAsciiWhitespace(StringView str) noexcept;


/// @brief 移除字符串尾部的ASCII空白字符
/// @param str 输入字符串
/// @return 移除尾部空白字符后的字符串视图
StringView aStripTrailingAsciiWhitespace(StringView str) noexcept;


/// @brief 移除字符串首部的ASCII空白字符
/// @param str 输入字符串
/// @return 移除首部空白字符后的字符串视图
StringView aStripLeadingAsciiWhitespace(StringView str) noexcept;


/// @brief 将字符串转换为小写
/// @param str 输入字符串
/// @return 小写后的字符串
std::string aAsciiStrToLower(StringView str);


/// @brief 将字符串转换为大写
/// @param str 输入字符串
/// @return 大写后的字符串
std::string aAsciiStrToUpper(StringView str);


inline
bool aEqualsIgnoreCase(StringView piece1, StringView piece2) noexcept
{
    return piece1.size() == piece2.size() && (posix::strncasecmp(piece1.data(), piece2.data(), piece1.size()) == 0);
}

inline
StringView aStripAsciiWhitespace(StringView str) noexcept
{
    const char* begin = str.data();
    const char* end = begin + str.size();

    // Skip leading whitespace
    while (begin < end && std::isspace(static_cast<unsigned char>(*begin))) {
        ++begin;
    }

    // Skip trailing whitespace
    while (end > begin && std::isspace(static_cast<unsigned char>(*(end - 1)))) {
        --end;
    }

    return StringView(begin, static_cast<size_t>(end - begin));
}

inline
StringView aStripTrailingAsciiWhitespace(StringView str) noexcept
{
    const char* begin = str.data();
    const char* end = begin + str.size();

    // Skip trailing whitespace
    while (end > begin && std::isspace(static_cast<unsigned char>(*(end - 1)))) {
        --end;
    }

    return StringView(begin, static_cast<size_t>(end - begin));
}

inline
StringView aStripLeadingAsciiWhitespace(StringView str) noexcept
{
    const char* begin = str.data();
    const char* end = begin + str.size();

    // Skip leading whitespace
    while (begin < end && std::isspace(static_cast<unsigned char>(*begin))) {
        ++begin;
    }

    return StringView(begin, static_cast<size_t>(end - begin));
}

inline std::string aAsciiStrToLower(StringView sv)
{
    std::string str(sv);
    for (char& c : str) {
        c = std::tolower(static_cast<unsigned char>(c));
    }
    return str;
}

inline std::string aAsciiStrToUpper(StringView sv)
{
    std::string str(sv);
    for (char& c : str) {
        c = std::toupper(static_cast<unsigned char>(c));
    }
    return str;
}

/*! @} */


AST_NAMESPACE_END
