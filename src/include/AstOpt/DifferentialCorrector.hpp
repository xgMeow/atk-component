/// @file      DifferentialCorrector.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-30

#pragma once

#include "AstGlobal.h"
#include "AstOpt/NLPSolver.hpp"
#include <vector>

AST_NAMESPACE_BEGIN

/// @brief 微分修正算法
class DifferentialCorrector: public INLPSolver
{
public:
    using vector_t = std::vector<double>;
    static DifferentialCorrector* New();

    ~DifferentialCorrector()  override;
    errc_t solve(NLPProblem& prob, std::vector<double>& xopt) override;
protected:

};

AST_NAMESPACE_END
