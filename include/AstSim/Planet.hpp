/// @file      Planet.hpp
/// @brief     行星对象
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-07

#pragma once

#include "AstGlobal.h"
#include "AstCore/CelestialBody.hpp"
#include "AstUtil/ObjectNamed.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 行星对象
class AST_SIM_API Planet: public ObjectNamed
{
public:
    Planet() = default;
    ~Planet() override = default;

    AST_OBJECT(Planet)
};

/*! @} */

AST_NAMESPACE_END