/// @file      CompressorImplSystem.hpp
/// @brief     系统命令后端
/// @details   通过 popen() 调用系统安装的 tar/zip/7z 命令进行压缩。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-25

#pragma once

#include "AstUtil/CompressorInterface.hpp"
#include "AstUtil/ArchiverUtils.hpp"

#include <string>

AST_NAMESPACE_BEGIN

/// 系统命令后端
/// @details 通过调用系统安装的命令行工具进行压缩：
/// - tar    → .tar, .tar.gz, .tar.bz2, .tar.xz
/// - zip    → .zip
/// - 7z     → .7z
class AST_UTIL_API CompressorImplSystem : public CompressorInterface
{
public:
    static CompressorImplSystem& Instance();

    CompressorImplSystem() = default;
    virtual ~CompressorImplSystem() = default;

    virtual errc_t compress(StringView source, StringView target, StringView curdir = {}) const override;
    virtual bool isSupported() const override;
    virtual bool canCompress(StringView source, StringView target) const override;
};

AST_NAMESPACE_END
