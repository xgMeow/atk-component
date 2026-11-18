/// @file      CelestialBodyLoader.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-06

#pragma once

#include "AstGlobal.h"
#include "CelestialBody.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 从文件加载一个天体
/// @param  filepath    - 天体文件路径
/// @param  body        - 天体指针
/// @retval             - 错误码
AST_CORE_CAPI errc_t aLoadBody(StringView filepath, HCelestialBody& body);


/*! @} */

AST_NAMESPACE_END
