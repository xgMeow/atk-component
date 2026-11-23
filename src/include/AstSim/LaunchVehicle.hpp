/// @file      LaunchVehicle.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-13

#pragma once

#include "AstGlobal.h"
#include "AstSim/Spacecraft.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 运载火箭对象
class AST_SIM_API LaunchVehicle: public Spacecraft
{
public:
    AST_OBJECT(LaunchVehicle)
    LaunchVehicle() = default;
    ~LaunchVehicle() override = default;
};


/*! @} */

AST_NAMESPACE_END