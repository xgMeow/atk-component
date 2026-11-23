/// @file      NLPIpoptSolver.hpp
/// @brief     
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      16.11.2025

#pragma once

#include "NLPSolver.hpp"

AST_NAMESPACE_BEGIN



class CNLPIpoptSolver : public INLPSolver
{
public:
	errc_t solve(NLPProblem& prob, std::vector<double>& xopt) override;
protected:

};


AST_NAMESPACE_END
