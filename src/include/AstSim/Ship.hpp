/// @file      Ship.hpp
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

/// @brief 舰船对象
class AST_SIM_API Ship: public Mover
{
public:
    AST_OBJECT(Ship)
    Ship() = default;
    ~Ship() override = default;
};


/*! @} */

AST_NAMESPACE_END