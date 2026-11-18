/// @file      Transmitter.hpp
/// @brief     发射机对象
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

/// @brief 发射机对象
class AST_SIM_API Transmitter: public ObjectNamed
{
public:
    Transmitter() = default;
    ~Transmitter() override = default;

    AST_OBJECT(Transmitter)
};

/*! @} */

AST_NAMESPACE_END