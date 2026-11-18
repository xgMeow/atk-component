/// @file      TargetLoader.hpp
/// @brief     目标加载器
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-07

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class Target;

/// @brief 加载目标对象
/// @details 从文件加载目标对象
/// @param filepath 文件路径
/// @param target 目标对象引用
/// @return 错误码
AST_LOADER_CAPI errc_t aLoadTarget(StringView filepath, Target& target);

/*! @} */

AST_NAMESPACE_END