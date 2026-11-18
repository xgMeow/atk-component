/// @file      RadarLoader.hpp
/// @brief     雷达加载器
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-07

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class Radar;

/// @brief 加载雷达对象
/// @details 从文件加载雷达对象
/// @param filepath 文件路径
/// @param radar 雷达对象引用
/// @return 错误码
AST_LOADER_CAPI errc_t aLoadRadar(StringView filepath, Radar& radar);

/*! @} */

AST_NAMESPACE_END