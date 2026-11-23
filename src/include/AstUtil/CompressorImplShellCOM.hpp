/// @file      CompressorImplShellCOM.hpp
/// @brief     Windows Shell COM 压缩后端
/// @details   通过 IShellDispatch 直接 COM 接口创建 ZIP 文件。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-25

#pragma once

#include "AstUtil/CompressorInterface.hpp"
#include "AstUtil/StringView.hpp"

// 仅 Windows 平台
#if defined(_WIN32) && !defined(SWIG)


#include <string>

AST_NAMESPACE_BEGIN

/// Windows Shell COM 压缩后端
/// @details 利用 IShellDispatch 直接 COM 接口创建 ZIP 文件：
/// 1. 写入空 EOCD 记录作为最小 zip 容器
/// 2. IShellDispatch::NameSpace 获取 zip Folder
/// 3. Folder::ParseName 定位源文件/文件夹
/// 4. Folder::CopyHere 异步复制进 zip
/// 5. ParseName 轮询等待写入完成
class AST_UTIL_API CompressorImplShellCOM : public CompressorInterface
{
public:
    static CompressorImplShellCOM& Instance();

    CompressorImplShellCOM() = default;
    virtual ~CompressorImplShellCOM() = default;

    virtual errc_t compress(StringView source, StringView target, StringView curdir = {}) const override;
    virtual bool canCompress(StringView source, StringView target) const override;

private:
    /// 写入空的 ZIP End of Central Directory Record（22 字节）
    static errc_t createEmptyZip(const std::wstring& path);
};

AST_NAMESPACE_END

#endif // _WIN32
