/// @file      CompressorImplRaw.hpp
/// @brief     原始复制后端
/// @details   将文件或目录直接复制到目标位置，始终可用，作为通用兜底方案。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-25

#pragma once

#include "AstUtil/CompressorInterface.hpp"
#include "AstUtil/StringView.hpp"

AST_NAMESPACE_BEGIN

/// 原始复制后端
/// @details 将文件或目录直接复制到目标位置，不依赖任何外部工具。
/// 始终可用，作为回退链的最终兜底方案。
class AST_UTIL_API CompressorImplRaw : public CompressorInterface
{
public:
    static CompressorImplRaw& Instance();

    CompressorImplRaw() = default;
    virtual ~CompressorImplRaw() = default;

    virtual errc_t compress(StringView source, StringView target, StringView curdir = {}) const override;
    virtual bool canCompress(StringView source, StringView target) const override;
};

AST_NAMESPACE_END
