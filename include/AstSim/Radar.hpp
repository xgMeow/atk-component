/// @file      Radar.hpp
/// @brief     雷达对象
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-07

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Object.hpp"
#include "AstUtil/ObjectNamed.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 雷达对象
class AST_SIM_API Radar: public ObjectNamed
{
public:
    Radar() = default;
    ~Radar() override = default;

    AST_OBJECT(Radar)
};

/*! @} */

AST_NAMESPACE_END