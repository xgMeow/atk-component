/// @file      BKVBlock.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-08

#pragma once

#include "AstGlobal.h"
#include "BKVNode.hpp"
#include <memory>
#include <vector>
#include <string>

AST_NAMESPACE_BEGIN

/// @brief 键值对块节点（BlockKeyValueBlockNode）
/// @ingroup ParseFormat
class BKVBlock : public BKVNode
{
public:
    BKVBlock() : BKVNode(eBlock), name_(), children_() {}
private:
    std::string name_;      // 块名
    std::vector<std::unique_ptr<BKVNode>> children_;
};

AST_NAMESPACE_END
