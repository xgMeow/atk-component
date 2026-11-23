/// @file      Asteroid.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-26

#pragma once

#include "AstGlobal.h"
#include "AstSim/SpaceObject.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 小行星
class AST_SIM_API Asteroid: public SpaceObject
{
public:
    AST_OBJECT(Asteroid)
    Asteroid() = default;
    ~Asteroid() override = default;
};

/*! @} */

AST_NAMESPACE_END