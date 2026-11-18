/// @file      ExtractorImplPowerShell.hpp
/// @brief     PowerShell .gz 解压后端
/// @details   通过 PowerShell + .NET System.IO.Compression.GZipStream 解压
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-26

#pragma once

#if defined(_WIN32) && !defined(SWIG)

#include "AstUtil/ExtractorInterface.hpp"
#include "AstUtil/StringView.hpp"

AST_NAMESPACE_BEGIN

/// PowerShell .gz 解压后端
/// @details 通过 PowerShell + .NET System.IO.Compression.GZipStream 解压
/// 单文件 .gz。在 Windows 上始终可用（PowerShell 自 Windows 7 起内置）。
/// 兼容 PowerShell 2.0 (.NET 3.5 SP1)。
class AST_UTIL_API ExtractorImplPowerShell : public ExtractorInterface
{
public:
    static ExtractorImplPowerShell& Instance();

    ExtractorImplPowerShell() = default;
    virtual ~ExtractorImplPowerShell() = default;

    virtual errc_t extract(StringView source, StringView target) const override;
    virtual bool canExtract(StringView source) const override;
    virtual bool isSupported() const override;
};

AST_NAMESPACE_END

#endif // _WIN32
