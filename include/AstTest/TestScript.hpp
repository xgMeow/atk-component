/// @file      TestScript.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-15

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"
#include "AstUtil/Quantity.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class Quantity;

/// @brief 测试字符串表达式的解析
/// @details 测试字符串表达式的解析，包括输入表达式的解析和格式化表达式的解析
/// @param script 表达式字符串
/// @return errc_t 错误码
/// @note 该函数用于测试字符串表达式的解析
AST_TEST_CAPI errc_t aTestScriptParse(StringView script);

/// @brief 测试字符串表达式的语法错误
/// @param str 表达式字符串
/// @return errc_t 错误码
AST_TEST_CAPI errc_t aTestScriptSyntaxError(StringView str);

/// @brief 测试字符串表达式的运行时错误
/// @param str 表达式字符串
/// @return errc_t 错误码
AST_TEST_CAPI errc_t aTestScriptEvalRuntimeError(StringView str);

/// @brief 计算字符串表达式，期望结果为布尔值
/// @param str 表达式字符串
/// @param expectValue 期望的布尔值
/// @return errc_t 错误码
/// @note 该函数用于测试字符串表达式的解析和求值
AST_TEST_CAPI errc_t aTestScriptEvalBool(StringView str, bool expectValue);

/// @brief 计算字符串表达式，期望结果为整数
/// @param str 表达式字符串
/// @param expectedValue 期望的整数值
/// @return errc_t 错误码
/// @note 该函数用于测试字符串表达式的解析和求值
AST_TEST_CAPI errc_t aTestScriptEvalInt(StringView str, int expectedValue);


/// @brief 计算字符串表达式，期望结果为浮点数
/// @param str 表达式字符串
/// @param expectedValue 期望的浮点数值
/// @return errc_t 错误码
/// @note 该函数用于测试字符串表达式的解析和求值
AST_TEST_CAPI errc_t aTestScriptEvalDouble(StringView str, double expectedValue);

/// @brief 计算字符串表达式，期望结果为字符串
/// @param str 表达式字符串
/// @param expectedValue 期望的字符串值
/// @return errc_t 错误码
/// @note 该函数用于测试字符串表达式的解析和求值
AST_TEST_CAPI errc_t aTestScriptEvalString(StringView str, StringView expectedValue);

/// @brief 计算字符串表达式，期望结果为数量
/// @param str 表达式字符串
/// @param expectedValue 期望的数量值
/// @return errc_t 错误码
/// @note 该函数用于测试字符串表达式的解析和求值
AST_TEST_CAPI errc_t aTestScriptEvalQuantity(StringView str, const Quantity& expectedValue);


template<typename T>
errc_t aTestScriptEval(StringView str, T expectedValue);


template<>
errc_t aTestScriptEval<bool>(StringView str, bool expectedValue)
{
    return aTestScriptEvalBool(str, expectedValue);
}

template<>
errc_t aTestScriptEval<int>(StringView str, int expectedValue)
{
    return aTestScriptEvalInt(str, expectedValue);
}

template<>
errc_t aTestScriptEval<double>(StringView str, double expectedValue)
{
    return aTestScriptEvalDouble(str, expectedValue);
}

template<>
errc_t aTestScriptEval<StringView>(StringView str, StringView expectedValue)
{
    return aTestScriptEvalString(str, expectedValue);
}

template<>
errc_t aTestScriptEval<Quantity>(StringView str, Quantity expectedValue)
{
    return aTestScriptEvalQuantity(str, expectedValue);
}



/*! @} */

AST_NAMESPACE_END