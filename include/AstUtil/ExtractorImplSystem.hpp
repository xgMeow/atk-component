/// @file      ExtractorImplSystem.hpp
/// @brief     系统命令后端
/// @details   通过 popen() 调用系统安装的 tar/unzip/7z 命令进行解压。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-25

#pragma once

#include "AstUtil/ExtractorInterface.hpp"
#include "AstUtil/StringView.hpp"

#include <string>

AST_NAMESPACE_BEGIN

/// 系统命令后端
/// @details 通过调用系统安装的命令行工具进行解压：
/// - tar    → .tar, .tar.gz, .tar.bz2, .tar.xz
/// - unzip  → .zip
/// - gzip   → .gz
/// - 7z     → .7z, .rar
class AST_UTIL_API ExtractorImplSystem : public ExtractorInterface
{
public:
    static ExtractorImplSystem& Instance();

    ExtractorImplSystem() = default;
    virtual ~ExtractorImplSystem() = default;

    virtual errc_t extract(StringView source, StringView target) const override;
    virtual bool isSupported() const override;
    virtual bool canExtract(StringView source) const override;
};

AST_NAMESPACE_END
