/// @file      ConstellationLoader.hpp
/// @brief     星座加载器
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-07

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class Constellation;

/// @brief 加载星座对象
/// @details 从文件加载星座对象
/// @param filepath 文件路径
/// @param constellation 星座对象引用
/// @return 错误码
AST_LOADER_CAPI errc_t aLoadConstellation(StringView filepath, Constellation& constellation);

/*! @} */

AST_NAMESPACE_END