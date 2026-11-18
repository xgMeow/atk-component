/// @file      Spacecraft.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-13

#pragma once

#include "AstGlobal.h"
#include "AstSim/Mover.hpp"
#include "AstSim/SpaceObject.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


class Spacecraft;
using HSpacecraft = SharedPtr<Spacecraft>;
using PSpacecraft = Spacecraft*;



/// @brief 航天器对象
class AST_SIM_API Spacecraft: public SpaceObject
{
public:
    AST_OBJECT(Spacecraft)
    Spacecraft() = default;
    ~Spacecraft() override = default;
};


/*! @} */

AST_NAMESPACE_END