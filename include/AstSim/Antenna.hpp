/// @file      Antenna.hpp
/// @brief     天线对象
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

/// @brief 天线对象
class AST_SIM_API Antenna: public ObjectNamed
{
public:
    Antenna() = default;
    ~Antenna() override = default;

    AST_OBJECT(Antenna)
};

/*! @} */

AST_NAMESPACE_END