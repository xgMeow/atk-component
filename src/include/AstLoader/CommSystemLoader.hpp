/// @file      CommSystemLoader.hpp
/// @brief     通信系统加载器
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-07

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class CommSystem;

/// @brief 加载通信系统对象
/// @details 从文件加载通信系统对象
/// @param filepath 文件路径
/// @param commSystem 通信系统对象引用
/// @return 错误码
AST_LOADER_CAPI errc_t aLoadCommSystem(StringView filepath, CommSystem& commSystem);

/*! @} */

AST_NAMESPACE_END