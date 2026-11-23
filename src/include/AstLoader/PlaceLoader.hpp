/// @file      PlaceLoader.hpp
/// @brief     地点加载器
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-07

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class Place;

/// @brief 加载地点对象
/// @details 从文件加载地点对象
/// @param filepath 文件路径
/// @param place 地点对象引用
/// @return 错误码
AST_LOADER_CAPI errc_t aLoadPlace(StringView filepath, Place& place);

/*! @} */

AST_NAMESPACE_END