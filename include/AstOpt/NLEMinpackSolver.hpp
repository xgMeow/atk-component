/// @file      NLEMinpackSolver.hpp
/// @brief     
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      16.11.2025

#pragma once

#include "NLPSolver.hpp"

AST_NAMESPACE_BEGIN


class CNLEMinpackSolver : INLPSolver
{
public:
	errc_t solve(NLPProblem& problem, std::vector<double>& xopt) override;
};


AST_NAMESPACE_END
