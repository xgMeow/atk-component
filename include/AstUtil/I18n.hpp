/// @file      I18n.hpp
/// @brief     Internationalization and Localization API
/// @details   国际化和本地化接口
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-03

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 设置当前文本域（尚未实现）
AST_UTIL_CAPI const char* aTextDomain(const char *domainname);


/// @brief 获取翻译文本（无上下文）
AST_UTIL_CAPI const char* aGetText(const char* msgid);

/// @brief 给定上下文，获取翻译文本
/// @param msgctxt 上下文
/// @param msgid 消息ID
AST_UTIL_CAPI const char* aTranslate(const char* msgctxt, const char* msgid);

//-----------------------
// 与 Qt 兼容的函数接口
//-----------------------

A_ALWAYS_INLINE const char* translate(const char* msgctxt, const char* msgid)
{
    return aTranslate(msgctxt, msgid);
}

// 仅用于标记翻译字符串，不进行即时翻译（仅在class中有效，自动提取class名称作为上下文）
#define AST_TR_NOOP(String) String

// 仅用于标记带上下文的翻译字符串，不进行即时翻译
#define AST_TRANSLATE_NOOP(Context, String) String


//-----------------------
// 与 libintl 兼容的函数接口
//-----------------------

/// @brief 获取翻译文本（无上下文）
A_ALWAYS_INLINE const char* gettext(const char* msgid)
{
    return aGetText(msgid);
}

/// @brief 给定上下文，获取翻译文本
/// The letter 'p' stands for 'particular' or 'special'.  
/// @param msgctxt 上下文
/// @param msgid 消息ID
/// @return 上下文文本
A_ALWAYS_INLINE const char* pgettext(const char* msgctxt, const char* msgid)
{
    return aTranslate(msgctxt, msgid);
}

/// @brief 翻译文本（无上下文）
A_ALWAYS_INLINE const char* _(const char* msgid)
{
    return aGetText(msgid);
}

/// @brief 翻译文本（带上下文信息）
A_ALWAYS_INLINE const char* C_(const char* msgctxt, const char* msgid)
{
    return aTranslate(msgctxt, msgid);
}

// 仅用于标记翻译字符串，不进行即时翻译（无上下文）
#ifndef N_
    #define N_(String) String
#endif

// 用于标记带上下文的翻译字符串，不进行即时翻译
#ifndef NC_
    #define NC_(Context, String) String
#endif


/// @brief 设置当前文本域
A_ALWAYS_INLINE const char* textdomain(const char* domainname)
{
    return aTextDomain(domainname);
}

/*! @} */

AST_NAMESPACE_END


