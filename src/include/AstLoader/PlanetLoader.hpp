/// @file      PlanetLoader.hpp
/// @brief     行星对象加载器
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-10

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

class Planet;

/*!
    @addtogroup 
    @{
*/

/// @brief 加载行星对象
/// @param filepath 文件路径
/// @param planet 行星对象
/// @return 错误码
errc_t aLoadPlanet(StringView filepath, Planet& planet);

/*! @} */

AST_NAMESPACE_END