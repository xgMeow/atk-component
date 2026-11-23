/// @file      Volumetric.hpp
/// @brief     体积对象
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-07

#pragma once

#include "AstGlobal.h"
#include "AstUtil/ObjectNamed.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 体积对象
class AST_SIM_API Volumetric: public ObjectNamed
{
public:
    Volumetric() = default;
    ~Volumetric() override = default;

    AST_OBJECT(Volumetric)
};

/*! @} */

AST_NAMESPACE_END