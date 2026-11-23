/// @file      FigureOfMeritLoader.hpp
/// @brief     性能指标加载器
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-10

#pragma once

#include "AstGlobal.h"
#include "AstUtil/StringView.hpp"

AST_NAMESPACE_BEGIN

class FigureOfMerit;

/// @brief 加载性能指标对象
/// @param filepath 文件路径
/// @param figureOfMerit 性能指标对象引用
/// @return 错误码
errc_t aLoadFigureOfMerit(StringView filepath, FigureOfMerit& figureOfMerit);

AST_NAMESPACE_END