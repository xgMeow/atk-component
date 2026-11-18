/// @file      ReportStyleLoader.hpp
/// @brief     报表样式加载器
/// @details   提供从 ReportStyle 文件（.rst/.rsg）加载报表样式数据的功能。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-02

#pragma once

#include "AstGlobal.h"
#include "AstReport/ReportStyle.hpp"

AST_NAMESPACE_BEGIN

// 前置声明
class BKVParser;

/*!
    @addtogroup AstLoader
    @{
*/

/// @brief 从文件加载报表样式
/// @param filepath 文件路径（.rst 或 .rsg 文件）
/// @param report   [out] 报表样式数据
/// @return 错误码
AST_LOADER_API errc_t aLoadReportStyle(StringView filepath, ReportStyle& report);

/// @brief 从已打开的 BKVParser 加载报表样式
/// @param parser  已定位到 ReportStyle 块内部的 BKVParser
/// @param report  [out] 报表样式数据
/// @return 错误码
AST_LOADER_API errc_t aLoadReportStyle(BKVParser& parser, ReportStyle& report);

/*! @} */

AST_NAMESPACE_END
