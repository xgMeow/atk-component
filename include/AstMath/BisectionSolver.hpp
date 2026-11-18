/// @file      BisectionSolver.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-26

#pragma once

#include "AstGlobal.h"
#include "AstMath/UnarySolver.hpp"



AST_NAMESPACE_BEGIN

/// @brief 二分法求解器
/// @ingroup NLE
class AST_MATH_API BisectionSolver: public UnarySolver
{
public:
    BisectionSolver() = default;
    ~BisectionSolver() = default;
    using UnarySolver::solve;
    errc_t solve(UnaryScalarFunc& func, double min, double max, double& result) override;
};



AST_NAMESPACE_END
