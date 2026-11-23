/// @file      CompressorImplTar.hpp
/// @brief     纯 C++ TAR 格式写入后端
/// @details   从头实现 TAR 归档文件写入器，零依赖。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-25

#pragma once

#include "AstUtil/CompressorInterface.hpp"
#include "AstUtil/FileSystem.hpp"
#include "AstUtil/StringView.hpp"
#include "AstUtil/ArchiverUtils.hpp"

#include <string>

AST_NAMESPACE_BEGIN

/// 纯 C++ TAR 写入后端
/// @details 从头实现 TAR 归档文件写入，不依赖任何第三方库。
/// 支持 USTAR 格式。仅生成未压缩的 .tar 文件。
class AST_UTIL_API CompressorImplTar : public CompressorInterface
{
public:
    static CompressorImplTar& Instance();

    CompressorImplTar() = default;
    virtual ~CompressorImplTar() = default;

    virtual errc_t compress(StringView source, StringView target, StringView curdir = {}) const override;
    virtual bool canCompress(StringView source, StringView target) const override;

private:
    /// 写入一个文件条目（头部 + 数据 + 填充）
    static errc_t writeFileEntry(FILE* dst, const std::string& name,
                                 const std::string& filePath);

    /// 写入一个目录条目（仅头部）
    static errc_t writeDirectoryEntry(FILE* dst, const std::string& name);

    /// 递归归档目录
    static errc_t archiveDirectory(FILE* dst, const fs::path& dirPath,
                                    const std::string& basePath);
};

AST_NAMESPACE_END
