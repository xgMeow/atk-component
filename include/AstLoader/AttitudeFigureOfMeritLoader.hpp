/// @file      AttitudeFigureOfMeritLoader.hpp
/// @brief     姿态性能指标加载器
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-10

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

class AttitudeFigureOfMerit;

/*!
    @addtogroup 
    @{
*/

/// @brief 加载姿态性能指标
/// @param filepath 文件路径
/// @param attitudeFigureOfMerit 姿态性能指标对象
/// @return 错误码
errc_t aLoadAttitudeFigureOfMerit(StringView filepath, AttitudeFigureOfMerit& attitudeFigureOfMerit);

/*! @} */

AST_NAMESPACE_END