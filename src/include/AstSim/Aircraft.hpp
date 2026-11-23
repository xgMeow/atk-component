/// @file      Aircraft.hpp
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

/// @brief 航空器对象
class AST_SIM_API Aircraft: public Mover
{
public:
    AST_OBJECT(Aircraft)
    Aircraft() = default;
    ~Aircraft() override = default;
};


/*! @} */

AST_NAMESPACE_END