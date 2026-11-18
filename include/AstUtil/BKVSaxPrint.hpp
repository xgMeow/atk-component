/// @file      BKVSaxPrint.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-08

#pragma once

#include "AstGlobal.h"
#include "BKVSax.hpp"
#include "AstUtil/ScopedPtr.hpp"
#include <cstdio>

AST_NAMESPACE_BEGIN

/// @brief     键值对打印器（BlockKeyValueSaxPrint）
/// @details   本类实现了键值对打印器，用于打印键值对格式的文本。
/// @ingroup ParseFormat
class AST_UTIL_API  BKVSaxPrint : public BKVSax
{
public:
    BKVSaxPrint();

    BKVSaxPrint(const BKVSaxPrint&) = delete;
    BKVSaxPrint& operator=(const BKVSaxPrint&) = delete;

    explicit BKVSaxPrint(StringView filepath);
    ~BKVSaxPrint();
    errc_t begin(StringView name) override;
    errc_t end(StringView name) override;
    using BKVSax::keyValue;
    errc_t keyValue(StringView key, const ValueView& value) override;
protected:
    FILE* file_;
    int indent_;
    int depth_;
};

AST_NAMESPACE_END
