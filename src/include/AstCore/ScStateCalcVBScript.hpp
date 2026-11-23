/// @file      ScStateCalcVBScript.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-02

#pragma once

#include "AstGlobal.h"
#include "AstCore/ScStateCalculation.hpp"
#include "ScStateCalcScript.hpp"

AST_NAMESPACE_BEGIN

class AST_CORE_API ScStateCalcVBScript : public ScStateCalcScript
{
public:
    errc_t calculate(const SpacecraftState& scState, double& result) override;
    ScriptExecutor* newScriptExecutor() const override;
};

AST_NAMESPACE_END