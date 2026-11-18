/// @file      BurnCollocation.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-18

#pragma once

#include "AstGlobal.h"
#include "Burn.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 发动机点火(正交配置法求解)
class AST_CORE_API BurnCollocation: public Burn
{
public:
    BurnCollocation() = default;
    ~BurnCollocation() = default;
public:

};


/*! @} */

AST_NAMESPACE_END
