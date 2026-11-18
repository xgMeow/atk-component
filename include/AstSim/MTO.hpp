/// @file      MTO.hpp
/// @brief     多目标对象
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

/// @brief 多目标对象
class AST_SIM_API MTO: public ObjectNamed
{
public:
    MTO() = default;
    ~MTO() override = default;

    AST_OBJECT(MTO)
};

/*! @} */

AST_NAMESPACE_END