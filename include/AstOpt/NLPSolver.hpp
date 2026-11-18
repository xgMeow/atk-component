/// @file      NLPSolver.hpp
/// @brief     
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      16.11.2025

#pragma once

#include "AstGlobal.h"
#include "NLPProblem.hpp"

AST_NAMESPACE_BEGIN


class INLPSolver
{
public:
    virtual ~INLPSolver() {}
    virtual errc_t solve(NLPProblem& prob, std::vector<double>& xopt) = 0;
};


AST_NAMESPACE_END







