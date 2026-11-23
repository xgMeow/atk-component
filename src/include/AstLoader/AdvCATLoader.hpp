/// @file      AdvCATLoader.hpp
/// @brief     高级CAT加载器
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-07

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AdvCAT;

/// @brief 加载高级CAT对象
/// @details 从文件加载高级CAT对象
/// @param filepath 文件路径
/// @param advCAT 高级CAT对象引用
/// @return 错误码
AST_LOADER_CAPI errc_t aLoadAdvCAT(StringView filepath, AdvCAT& advCAT);

/*! @} */

AST_NAMESPACE_END