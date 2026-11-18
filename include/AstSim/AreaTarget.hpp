/// @file      AreaTarget.hpp
/// @brief     区域目标对象
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

/// @brief 区域目标对象
class AST_SIM_API AreaTarget: public ObjectNamed
{
public:
    AreaTarget() = default;
    ~AreaTarget() override = default;

    AST_OBJECT(AreaTarget)
};

/*! @} */

AST_NAMESPACE_END