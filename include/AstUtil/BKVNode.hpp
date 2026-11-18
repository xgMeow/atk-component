/// @file      BKVNode.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-08

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/// @brief 节点（BlockKeyValueNode）
/// @ingroup ParseFormat
class BKVNode
{
public:
    enum EType{
        eBlock,
        eItem,
    };
    explicit BKVNode(EType type) : type_(type) {}
    virtual ~BKVNode() = default;
public:
    /// @brief 获取节点类型
    EType type() const { return type_; }
public:
    EType type_;
};

AST_NAMESPACE_END
