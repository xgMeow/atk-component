/// @file      ScStateCalcRadiusOfApoapsis.hpp
/// @brief     
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-02

#pragma once

#include "AstGlobal.h"
#include "AstCore/ScStateCalculation.hpp"
#include "AstCore/ScStateCalcBodyRelated.hpp"

AST_NAMESPACE_BEGIN

class AST_CORE_API ScStateCalcRadiusOfApoapsis : public ScStateCalcBodyRelated
{
public:
    errc_t calculate(const SpacecraftState& state, double& result) override;
};

AST_NAMESPACE_END