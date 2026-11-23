/// @file      ScStateCalcDotProduct.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-02

#pragma once

#include "AstGlobal.h"
#include "AstCore/ScStateCalculation.hpp"

AST_NAMESPACE_BEGIN

class ScStateCalcDotProduct : public ScStateCalculation
{
public:
    errc_t calculate(const SpacecraftState& scState, double& result) override;
};

AST_NAMESPACE_END