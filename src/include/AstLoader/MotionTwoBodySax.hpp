/// @file      TwoBodySAX.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-19

#pragma once

#include "AstGlobal.h"
#include "MotionOrbitDynamicsKeplerianSax.hpp"
#include "AstSim/MotionTwoBody.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AST_LOADER_API MotionTwoBodySax: public MotionOrbitDynamicsKeplerianSax
{
public:
    using MotionOrbitDynamicsKeplerianSax::MotionOrbitDynamicsKeplerianSax;
    MotionOrbitDynamics* newMotionOrbitDynamics() override{
        return new MotionTwoBody();
    }
};


/*! @} */

AST_NAMESPACE_END
