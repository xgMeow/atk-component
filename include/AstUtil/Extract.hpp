/// @file      Extract.hpp
/// @brief     解压 API 入口
/// @details   工厂函数与便捷函数，对标 Network.hpp 中的 aNetworkRequest() 等。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-25

#pragma once

#include "ExtractorInterface.hpp"
#include "AstUtil/StringView.hpp"

AST_NAMESPACE_BEGIN

/// @brief 获取默认的解压实现
/// @details 按优先级探测后端，返回第一个对指定 source 可用的实现：
/// 1. ExtractorImplShellCOM  — Windows 上对 .zip 始终可用
/// 2. ExtractorImplPowerShell — Windows 上对 .gz 始终可用（PowerShell + .NET）
/// 3. ExtractorImplTar       — .tar 文件（纯 C++，始终可用）
/// 4. ExtractorImplSystem    — 系统安装了 tar/unzip/7z
/// 5. ExtractorImplRaw       — 始终可用（文件/目录复制）
/// @param source 待解压的文件路径（用于 canExtract 检查；为空则仅检查 isSupported）
/// @return ExtractorInterface* 可用的解压实现，如果全部不可用则返回 nullptr
AST_UTIL_API ExtractorInterface* aExtractGetImpl(StringView source = {});

/// @brief 解压文件或目录到目标位置
/// @details 自动选择最佳后端进行解压。支持 .zip, .tar, .tar.gz, .tar.bz2, .tar.xz, .7z 等格式。
/// @param source 压缩文件路径
/// @param target 解压目标目录路径
/// @return eNoError 表示解压成功，否则返回错误码
AST_UTIL_API errc_t aExtract(StringView source, StringView target);

AST_NAMESPACE_END
