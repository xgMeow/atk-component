/// @file      ScStateCalcVy.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-02

#pragma once

#include "AstGlobal.h"
#include "AstCore/ScStateCalculation.hpp"
#include "AstCore/ScStateCalcFrameRelated.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AST_CORE_API ScStateCalcVy : public ScStateCalcFrameRelated
{
public:
    errc_t calculate(const ScState& state, double& result) override;
};

/*! @} */

AST_NAMESPACE_END
