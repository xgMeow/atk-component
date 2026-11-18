/// @file      BKVItem.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-08

#pragma once

#include "AstGlobal.h"
#include "BKVNode.hpp"
#include "AstUtil/GenericValue.hpp"
#include "AstUtil/ValueView.hpp"
#include <string>

AST_NAMESPACE_BEGIN

/// @brief 键值对项节点（BlockKeyValueItemNode）
/// @ingroup ParseFormat
class BKVItem : public BKVNode
{
public:
    BKVItem() : BKVNode(eItem), key_(), value_() {}
    /// @brief 键值对项节点（BlockKeyValueItemNode）
    BKVItem(StringView key, ValueView value)
        : BKVNode{eItem}
        , key_(key)
        , value_(value.toValue()) 
    {}

public:
    std::string key_;       // 键
    GenericValue value_;    // 值
};



AST_NAMESPACE_END
