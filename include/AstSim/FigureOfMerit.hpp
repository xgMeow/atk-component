/// @file      FigureOfMerit.hpp
/// @brief     性能指标对象
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-10

#pragma once

#include "AstGlobal.h"
#include "AstUtil/ObjectNamed.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 性能指标对象
class AST_SIM_API FigureOfMerit: public ObjectNamed
{
public:
    FigureOfMerit() = default;
    ~FigureOfMerit() override = default;

    AST_OBJECT(FigureOfMerit)
};

/*! @} */

AST_NAMESPACE_END