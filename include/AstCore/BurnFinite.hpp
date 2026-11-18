/// @file      BurnFinite.hpp
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

/// @brief 有限推力点火
class AST_CORE_API BurnFinite: public Burn
{
public:
    BurnFinite() = default;
    ~BurnFinite() = default;
};


/*! @} */

AST_NAMESPACE_END
