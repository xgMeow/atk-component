/// @file      GroundStation.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-08

#pragma once

#include "AstGlobal.h"
#include "Facility.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 地面站
class AST_SIM_API GroundStation: public Facility
{
public:
    AST_OBJECT(GroundStation)

    GroundStation() = default;
    ~GroundStation() override  = default ;
};


/*! @} */

AST_NAMESPACE_END
