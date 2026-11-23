/// @file      CoverageDefinition.hpp
/// @brief     覆盖定义对象
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

/// @brief 覆盖定义对象
class AST_SIM_API CoverageDefinition: public ObjectNamed
{
public:
    CoverageDefinition() = default;
    ~CoverageDefinition() override = default;

    AST_OBJECT(CoverageDefinition)
};

/*! @} */

AST_NAMESPACE_END