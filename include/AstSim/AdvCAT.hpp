/// @file      AdvCAT.hpp
/// @brief     高级CAT对象
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

/// @brief 高级接近分析工具
class AST_SIM_API AdvCAT: public ObjectNamed
{
public:
    AdvCAT() = default;
    ~AdvCAT() override = default;

    AST_OBJECT(AdvCAT)
};

/*! @} */

AST_NAMESPACE_END