/// @file      Satellite.hpp
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

/// @brief 卫星对象
class AST_SIM_API Satellite: public Spacecraft
{
public:
    AST_OBJECT(Satellite)
    static Satellite* New();

    Satellite() = default;
    ~Satellite() override = default;
};


/*! @} */

AST_NAMESPACE_END