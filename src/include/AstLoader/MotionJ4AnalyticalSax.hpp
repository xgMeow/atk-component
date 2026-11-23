/// @file      MotionJ4Analytical.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-14

#pragma once

#include "AstGlobal.h"
#include "MotionOrbitDynamicsKeplerianSax.hpp"
#include "AstSim/MotionJ4Analytical.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AST_LOADER_API MotionJ4AnalyticalSax: public MotionOrbitDynamicsKeplerianSax
{
public:
    using MotionOrbitDynamicsKeplerianSax::MotionOrbitDynamicsKeplerianSax;
    MotionOrbitDynamics* newMotionOrbitDynamics() override{
        return new MotionJ4Analytical();
    }
};


/*! @} */

AST_NAMESPACE_END
