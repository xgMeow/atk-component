/// @file      Chain.hpp
/// @brief     链对象
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

/// @brief 链对象
class AST_SIM_API Chain: public ObjectNamed
{
public:
    Chain() = default;
    ~Chain() override = default;

    AST_OBJECT(Chain)
};

/*! @} */

AST_NAMESPACE_END