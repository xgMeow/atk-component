/// @file      BKVItemView.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-08

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"
#include "AstUtil/ValueView.hpp"

AST_NAMESPACE_BEGIN

/// @brief 键值对项视图类（BlockKeyValueItemView）
/// @ingroup ParseFormat
class BKVItemView
{
public:
    BKVItemView() = default;
    BKVItemView(StringView key, ValueView value)
        : key_(key), value_(value) {}

    /// @brief 获取键视图
    const StringView& key() const { return key_; }
    StringView& key()  { return key_; }


    /// @brief 获取值视图
    const ValueView& value() const { return value_; }
    ValueView& value()  { return value_; }

public:
    StringView key_{};      ///< 键
    ValueView value_{};     ///< 值
};



AST_NAMESPACE_END

