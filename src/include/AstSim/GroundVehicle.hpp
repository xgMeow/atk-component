/// @file      GroundVehicle.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-13

#pragma once

#include "AstGlobal.h"
#include "AstSim/Mover.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 地面车辆对象
class AST_SIM_API GroundVehicle: public Mover
{
public:
    AST_OBJECT(GroundVehicle)
    GroundVehicle() = default;
    ~GroundVehicle() override = default;
};


/*! @} */

AST_NAMESPACE_END