/// @file      AttitudeCoverageLoader.hpp
/// @brief     姿态覆盖加载器
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-07

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AttitudeCoverage;

/// @brief 加载姿态覆盖对象
/// @details 从文件加载姿态覆盖对象
/// @param filepath 文件路径
/// @param attitudeCoverage 姿态覆盖对象引用
/// @return 错误码
AST_LOADER_CAPI errc_t aLoadAttitudeCoverage(StringView filepath, AttitudeCoverage& attitudeCoverage);

/*! @} */

AST_NAMESPACE_END