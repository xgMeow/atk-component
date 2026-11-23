/// @file      Constellation.hpp
/// @brief     星座对象
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

/// @brief 星座对象
class AST_SIM_API Constellation: public ObjectNamed
{
public:
    Constellation() = default;
    ~Constellation() override = default;

    AST_OBJECT(Constellation)
};

/*! @} */

AST_NAMESPACE_END