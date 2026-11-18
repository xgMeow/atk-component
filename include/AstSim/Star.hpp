/// @file      Star.hpp
/// @brief     恒星对象
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

/// @brief 恒星对象
class AST_SIM_API Star: public ObjectNamed
{
public:
    Star() = default;
    ~Star() override = default;

    AST_OBJECT(Star)
};

/*! @} */

AST_NAMESPACE_END