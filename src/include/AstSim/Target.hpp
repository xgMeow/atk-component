/// @file      Target.hpp
/// @brief     目标对象
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-07

#pragma once

#include "AstGlobal.h"
#include "AstSim/Mover.hpp"
#include "AstSim/Facility.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 目标对象
class AST_SIM_API Target: public Facility
{
public:
    Target() = default;
    ~Target() override = default;

    AST_OBJECT(Target)
};

/*! @} */

AST_NAMESPACE_END