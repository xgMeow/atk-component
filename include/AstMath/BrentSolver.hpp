/// @file      BrentSolver.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-26

#pragma once

#include "AstGlobal.h"
#include "AstMath/UnarySolver.hpp"


AST_NAMESPACE_BEGIN

/// @brief Brentq法求解器
/// @ingroup NLE
class AST_MATH_API BrentqSolver: public UnarySolver
{
public:
    using UnarySolver::UnarySolver;
    BrentqSolver() = default;
    ~BrentqSolver() = default;
    using UnarySolver::solve;
    errc_t solve(UnaryScalarFunc& func, double min, double max, double& result) override;
};

/// @brief Brenth法求解器
/// @ingroup NLE
class AST_MATH_API BrenthSolver: public UnarySolver
{
public:
    using UnarySolver::UnarySolver;
    BrenthSolver() = default;
    ~BrenthSolver() = default;
    using UnarySolver::solve;
    errc_t solve(UnaryScalarFunc& func, double min, double max, double& result) override;
};

using BrentSolver = BrentqSolver;

AST_NAMESPACE_END
