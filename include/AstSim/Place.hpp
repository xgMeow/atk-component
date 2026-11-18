/// @file      Place.hpp
/// @brief     地点对象
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-07

#pragma once

#include "AstGlobal.h"
#include "AstSim/Facility.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 地点对象
class AST_SIM_API Place: public Facility
{
public:
    Place() = default;
    ~Place() override = default;

    AST_OBJECT(Place)
};

/*! @} */

AST_NAMESPACE_END