/// @file      SecantSolver.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-26

#pragma once

#include "AstGlobal.h"
#include "AstMath/UnarySolver.hpp"
#include "AstMath/zeros.h"

AST_NAMESPACE_BEGIN

/// @brief 割线法求解器
/// @ingroup NLE
class AST_MATH_API SecantSolver: public UnarySolver
{
public:
    SecantSolver() = default;
    ~SecantSolver() = default;
    using UnarySolver::solve;
    errc_t solve(UnaryScalarFunc& func, double min, double max, double& result) override;
};

AST_NAMESPACE_END
