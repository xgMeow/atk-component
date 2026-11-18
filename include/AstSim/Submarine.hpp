/// @file      Submarine.hpp
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

/// @brief 潜艇对象
class AST_SIM_API Submarine: public Mover
{
public:
    AST_OBJECT(Submarine)
    Submarine() = default;
    ~Submarine() override = default;
};


/*! @} */

AST_NAMESPACE_END