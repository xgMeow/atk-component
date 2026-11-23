/// @file      Ephemeris.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-13

#pragma once

#include "AstGlobal.h"
#include "AstCore/Point.hpp"
#include "AstUtil/ObjectNamed.hpp"
#include "AstCore/TimeInterval.hpp"


AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 星历接口
using Ephemeris = Point;

using PEphemeris = Ephemeris*;
using HEphemeris = SharedPtr<Ephemeris>;





/*! @} */

AST_NAMESPACE_END
