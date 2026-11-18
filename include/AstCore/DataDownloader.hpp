/// @file      DataDownloader.hpp
/// @brief     数据文件夹下载器
/// @details   提供整包下载并安装 data 数据文件夹的能力，供 aInitialize 在缺少合法
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-08-26

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Data
    @{
*/

/// @brief 下载并安装数据文件夹
/// @details 从 gitcode 或 github 下载 data 仓库的整包压缩包，
///          并解压到动态库所在文件夹下的 data/ 目录。
///          优先尝试 gitcode，下载失败时自动回退到 github。
/// @param dataDir 数据文件夹路径
/// @return eNoError 表示成功，否则返回错误码
AST_CORE_CAPI errc_t aDownloadData(StringView dataDir = StringView());

/*! @} */

AST_NAMESPACE_END
