/// @file      SourceLocation.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-09

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 判断字符是否为路径分隔符（反斜杠或正斜杠）
constexpr bool is_sep(char c) {
#ifdef _WIN32
    return c == '\\' || c == '/';
#else
    return c == '/';
#endif
}


constexpr const char* extract_after_last_dotdot_impl(const char* str,
                                                     const char* last,
                                                     const char* orig) 
{
    return *str == '\0'
        ? (last ? last : orig)                                        // 扫描结束：有匹配则返回匹配后位置，否则返回原串
        : (str[0] == '.' && str[1] == '.' && is_sep(str[2]))
            ? extract_after_last_dotdot_impl(str + 3, str + 3, orig)  // 匹配到 ..\，更新 last 并继续
            : extract_after_last_dotdot_impl(str + 1, last, orig);    // 未匹配，继续扫描
}


/// @brief 查找最后一个 ".." 后的路径，并返回后续实际路径的起始位置，若无 .. 则返回原串
constexpr const char* extract_after_last_dotdot(const char* str) 
{
    return extract_after_last_dotdot_impl(str, nullptr, str);
}


constexpr const char* extract_filename_impl(const char* str, const char* last, const char* orig) 
{
    return *str == '\0'
        ? (last ? last + 1 : orig)  // 返回最后一个分隔符后的位置，若无则返回原串
        : (is_sep(*str)
            ? extract_filename_impl(str + 1, str, orig)   // 更新最后一个分隔符位置
            : extract_filename_impl(str + 1, last, orig));
}


/// @brief 从路径中提取文件名，若无分隔符则返回原串
constexpr const char* extract_filename(const char* str)
{
    return extract_filename_impl(str, nullptr, str);
}



#define A_SOURCE_FILE_PATH  _AST extract_after_last_dotdot(__FILE__)  // 仅包含 .. 后的路径部分
#define A_SOURCE_FILE_NAME  _AST extract_filename(__FILE__)
#define A_SOURCE_LINE       __LINE__
#define A_SOURCE_FUNC       __FUNCTION__

/*! @} */

AST_NAMESPACE_END
