/// @file      ExprMatch.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-24

#pragma once

#include "AstGlobal.h"
#include "Expr.hpp"

AST_NAMESPACE_BEGIN


/// @brief     匹配表达式
/// @ingroup Script
class AST_SCRIPT_API ExprMatch: public Expr
{
public:
    ExprMatch() = default;
    ~ExprMatch() = default;
};

AST_NAMESPACE_END
