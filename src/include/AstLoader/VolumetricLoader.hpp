/// @file      VolumetricLoader.hpp
/// @brief     体积加载器
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-07

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class Volumetric;

/// @brief 加载体积对象
/// @details 从文件加载体积对象
/// @param filepath 文件路径
/// @param volumetric 体积对象引用
/// @return 错误码
AST_LOADER_CAPI errc_t aLoadVolumetric(StringView filepath, Volumetric& volumetric);

/*! @} */

AST_NAMESPACE_END