/// @file      StringSplit.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-06

#pragma once

#include "AstGlobal.h"
#include "StringView.hpp"
#include "StringSplitter.hpp"


AST_NAMESPACE_BEGIN

/*!
    @addtogroup String
    @{
*/

/// @brief  字符串分割函数
/// @details 该函数将字符串 text 按照分隔符 delimiter 进行分割。
/// @param  text -  输入字符串
/// @param  delimiter -  分隔符
/// @retval          -  分割后的字符串视图迭代器
template <typename Delimiter>
inline strings_internal::Splitter<typename strings_internal::SelectDelimiter<Delimiter>::type, strings_internal::AllowEmpty, StringView>
aStrSplit(StringView text, Delimiter delimiter) {
    using DelimiterType = typename strings_internal::SelectDelimiter<Delimiter>::type;
    return strings_internal::Splitter<DelimiterType, strings_internal::AllowEmpty, StringView>(
        text, DelimiterType(delimiter), strings_internal::AllowEmpty());
}

/// @brief  字符串分割函数
/// @details 该函数将字符串 text 按照分隔符 delimiter 进行分割,
///          并根据分割条件 predicate 进行筛选。
/// @param  text -  输入字符串
/// @param  delimiter -  分隔符
/// @param  predicate -  分割条件
/// @retval          -  分割后的字符串视图迭代器
template <typename Delimiter, typename Predicate>
inline strings_internal::Splitter<typename strings_internal::SelectDelimiter<Delimiter>::type, Predicate, StringView>
aStrSplit(StringView text, Delimiter delimiter, Predicate predicate) {
    using DelimiterType = typename strings_internal::SelectDelimiter<Delimiter>::type;
    return strings_internal::Splitter<DelimiterType, Predicate, StringView>(
        text, DelimiterType(delimiter), std::move(predicate));
}



/*! @} */

AST_NAMESPACE_END