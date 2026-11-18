/// @file      CoverageDefinitionLoader.hpp
/// @brief     覆盖定义加载器
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-07

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class CoverageDefinition;

/// @brief 加载覆盖定义对象
/// @details 从文件加载覆盖定义对象
/// @param filepath 文件路径
/// @param coverageDefinition 覆盖定义对象引用
/// @return 错误码
AST_LOADER_CAPI errc_t aLoadCoverageDefinition(StringView filepath, CoverageDefinition& coverageDefinition);

/*! @} */

AST_NAMESPACE_END