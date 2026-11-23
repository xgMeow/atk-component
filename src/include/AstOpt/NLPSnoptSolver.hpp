/// @file      NLPSnoptSolver.hpp
/// @brief     
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      16.11.2025

#pragma once

#include "NLPSolver.hpp"

AST_NAMESPACE_BEGIN




class CNLPSnoptSolver : public INLPSolver
{
public:
	errc_t solve(NLPProblem& prob, std::vector<double>& xopt) override;
public:
	struct
	{
		int major_iteration_limit = 500;
	} options;
};


AST_NAMESPACE_END
