/// @file      ExtractorImplShellCOM.hpp
/// @brief     Windows Shell COM 解压后端
/// @details   通过 IShellDispatch 直接 COM 接口解压 ZIP 文件。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-25

#pragma once

#include "AstUtil/ExtractorInterface.hpp"
#include "AstUtil/StringView.hpp"

// 仅 Windows 平台
#if defined(_WIN32) && !defined(SWIG)


#include <string>
#include <vector>

AST_NAMESPACE_BEGIN

/// Windows Shell COM 解压后端
/// @details 利用 IShellDispatch 直接 COM 接口解压 ZIP 文件：
/// 1. IShellDispatch::NameSpace(zip) 获取 zip 内部 Folder
/// 2. Folder::Items 获取所有项集合
/// 3. IShellDispatch::NameSpace(dir) 获取目标目录 Folder
/// 4. 目标 Folder::CopyHere 一次性解压全部内容
/// 5. ParseName 轮询等待各项写入完成
class AST_UTIL_API ExtractorImplShellCOM : public ExtractorInterface
{
public:
    static ExtractorImplShellCOM& Instance();

    ExtractorImplShellCOM() = default;
    virtual ~ExtractorImplShellCOM() = default;

    virtual errc_t extract(StringView source, StringView target) const override;
    virtual bool canExtract(StringView source) const override;

};

AST_NAMESPACE_END

#endif // _WIN32
