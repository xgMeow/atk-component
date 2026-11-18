/// @file      AttitudeCoverage.hpp
/// @brief     姿态覆盖对象
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

/// @brief 姿态覆盖工具
class AST_SIM_API AttitudeCoverage: public ObjectNamed
{
public:
    AttitudeCoverage() = default;
    ~AttitudeCoverage() override = default;

    AST_OBJECT(AttitudeCoverage)
};

/*! @} */

AST_NAMESPACE_END