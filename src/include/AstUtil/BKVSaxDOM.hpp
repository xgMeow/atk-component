/// @file      BKVSaxDOM.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-08

#pragma once

#include "AstGlobal.h"
#include "BKVSax.hpp"

AST_NAMESPACE_BEGIN

/// @brief     键值对DOM树解析器（BlockKeyValueSaxDOM）
/// @details   本类实现了键值对解析器，用于解析键值对格式的文本。
/// @ingroup ParseFormat
class BKVSaxDOM : public BKVSax
{
public:
    BKVSaxDOM() = default;
    ~BKVSaxDOM() = default;
};

AST_NAMESPACE_END
