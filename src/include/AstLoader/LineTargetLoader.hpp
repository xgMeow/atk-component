/// @file      LineTargetLoader.hpp
/// @brief     线目标加载器
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-07

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class LineTarget;

/// @brief 加载线目标对象
/// @details 从文件加载线目标对象
/// @param filepath 文件路径
/// @param lineTarget 线目标对象引用
/// @return 错误码
AST_LOADER_CAPI errc_t aLoadLineTarget(StringView filepath, LineTarget& lineTarget);

/*! @} */

AST_NAMESPACE_END