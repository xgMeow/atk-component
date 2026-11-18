/// @file      VDFLoader.hpp
/// @brief     VDF (Visual Data File) 加载器
/// @details   将 STK VDF 打包文件解包还原为目录结构，然后加载场景。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-26

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

class Scenario;

/// @brief 从 VDF 打包文件加载场景
/// @details 自动解压 gzip、解包还原目录结构、然后加载场景。
///          支持 .vdf（gzip 压缩）和已解压的 .vdf 文件。
/// @param filepath VDF 文件路径
/// @param scenario 输出的场景对象
/// @return eNoError 成功，否则返回错误码
AST_LOADER_API errc_t aLoadVDF(StringView filepath, Scenario& scenario);

/// @brief 将 VDF 打包文件解包到指定目录
/// @details 解压 gzip 后将 VDF 内所有文件还原到 outputDir 目录。
/// @param filepath VDF 文件路径
/// @param outputDir 输出目录路径
/// @return eNoError 成功，否则返回错误码
AST_LOADER_API errc_t aExtractVDF(StringView filepath, StringView outputDir);

AST_NAMESPACE_END
