/// @file      ChainLoader.hpp
/// @brief     链加载器
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-07

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class Chain;

/// @brief 加载链对象
/// @details 从文件加载链对象
/// @param filepath 文件路径
/// @param chain 链对象引用
/// @return 错误码
AST_LOADER_CAPI errc_t aLoadChain(StringView filepath, Chain& chain);

/*! @} */

AST_NAMESPACE_END