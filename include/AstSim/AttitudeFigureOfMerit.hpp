/// @file      AttitudeFigureOfMerit.hpp
/// @brief     姿态性能指标对象
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-10

#pragma once

#include "AstGlobal.h"
#include "FigureOfMerit.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 姿态覆盖性能指标
class AST_SIM_API AttitudeFigureOfMerit: public FigureOfMerit
{
public:
    AttitudeFigureOfMerit() = default;
    ~AttitudeFigureOfMerit() override = default;

    AST_OBJECT(AttitudeFigureOfMerit)
};

/*! @} */

AST_NAMESPACE_END