/// @file      ExtractorImplRaw.hpp
/// @brief     原始复制后端
/// @details   将文件或目录直接复制到目标位置，始终可用，作为通用兜底方案。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-25

#pragma once

#include "AstUtil/ExtractorInterface.hpp"

AST_NAMESPACE_BEGIN

/// 原始复制后端
/// @details 将文件或目录直接复制到目标位置，不依赖任何外部工具。
/// 始终可用，作为回退链的最终兜底方案。
class AST_UTIL_API ExtractorImplRaw : public ExtractorInterface
{
public:
    static ExtractorImplRaw& Instance();

    ExtractorImplRaw() = default;
    virtual ~ExtractorImplRaw() = default;

    virtual errc_t extract(StringView source, StringView target) const override;
};

AST_NAMESPACE_END
