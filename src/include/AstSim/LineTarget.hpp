/// @file      LineTarget.hpp
/// @brief     线目标对象
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

/// @brief 线目标对象
class AST_SIM_API LineTarget: public ObjectNamed
{
public:
    LineTarget() = default;
    ~LineTarget() override = default;

    AST_OBJECT(LineTarget)
};

/*! @} */

AST_NAMESPACE_END