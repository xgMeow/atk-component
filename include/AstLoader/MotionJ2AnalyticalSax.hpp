/// @file      MotionJ2Analytical.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-14

#pragma once

#include "AstGlobal.h"
#include "MotionOrbitDynamicsKeplerianSax.hpp"
#include "AstSim/MotionJ2Analytical.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AST_LOADER_API MotionJ2AnalyticalSax: public MotionOrbitDynamicsKeplerianSax
{
public:
    using MotionOrbitDynamicsKeplerianSax::MotionOrbitDynamicsKeplerianSax;
    MotionOrbitDynamics* newMotionOrbitDynamics() override{
        return new MotionJ2Analytical();
    }
};

/*! @} */

AST_NAMESPACE_END
