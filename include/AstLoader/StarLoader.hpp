/// @file      StarLoader.hpp
/// @brief     恒星对象加载器
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-10

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

class Star;

/*!
    @addtogroup 
    @{
*/

/// @brief 加载恒星对象
/// @param filepath 文件路径
/// @param star 恒星对象
/// @return 错误码
errc_t aLoadStar(StringView filepath, Star& star);

/*! @} */

AST_NAMESPACE_END