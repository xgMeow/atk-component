/// @file      ScStateCalcEccentricity.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-02

#pragma once

#include "AstGlobal.h"
#include "AstCore/ScStateCalcBodyRelated.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AST_CORE_API ScStateCalcEccentricity: public ScStateCalcBodyRelated
{
public:
    AST_OBJECT(ScStateCalcEccentricity)

    ScStateCalcEccentricity() = default;
    ~ScStateCalcEccentricity() = default;
public:
    errc_t calculate(const SpacecraftState &scState, double& result) override;
};




/*! @} */

AST_NAMESPACE_END
