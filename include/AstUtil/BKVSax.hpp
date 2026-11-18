/// @file      BKVSax.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-08

#pragma once

#include "AstGlobal.h"
#include "AstUtil/GenericValue.hpp"
#include "AstUtil/ValueView.hpp"
#include "AstUtil/Color.hpp"

AST_NAMESPACE_BEGIN

class ValueView;

/// @brief 键值对解析器SAX接口（BlockKeyValueSax）
/// @details 本接口定义了键值对解析器的SAX接口，用于解析键值对格式的文本。
/// @ingroup ParseFormat
class AST_UTIL_API BKVSax
{
public:
    static constexpr int endParse = 1;

    /// @brief 析构函数
    virtual ~BKVSax() = default;

    /// @brief 开始解析一个块
    /// @param name 块名
    virtual errc_t begin(StringView name) = 0;

    /// @brief 结束解析一个块
    /// @param name 块名
    virtual errc_t end(StringView name) = 0;

    /// @brief 迭代解析一个键值对
    /// @param key 键
    /// @param value 值
    virtual errc_t keyValue(StringView key, const ValueView& value) = 0;

    errc_t begin() { return begin(StringView{});}
    errc_t end() { return end(StringView{});}
    errc_t keyValue(StringView key, const char* value){ return keyValue(key, ValueView(value)); }
    errc_t keyValue(StringView key, int value){ return keyValue(key, GenericValue(value)); }
    errc_t keyValue(StringView key, bool value){ return keyValue(key, GenericValue(value)); }
    errc_t keyValue(StringView key, double value){ return keyValue(key, GenericValue(value)); }
    errc_t keyValue(StringView key, Color value){ return keyValue(key, GenericValue(value)); }
    errc_t keyValue(StringView key, StringView value){ return keyValue(key, ValueView(value)); }
};


AST_NAMESPACE_END
