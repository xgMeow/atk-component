/// @file      AstPlot.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-30

#pragma once

#include "AstGlobal.h"

#ifdef AST_WITH_MATPLOT
A_SUPPRESS_WARNINGS_BEGIN
#include <matplot/matplot.h>
A_SUPPRESS_WARNINGS_END
#else
#include "NoPlot.hpp"
#endif

AST_NAMESPACE_BEGIN

#ifdef AST_WITH_MATPLOT
namespace plt = matplot;
#else
namespace plt = noplot;
#endif

AST_NAMESPACE_END
