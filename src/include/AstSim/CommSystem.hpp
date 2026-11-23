/// @file      CommSystem.hpp
/// @brief     通信系统对象
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

/// @brief 通信系统对象
class AST_SIM_API CommSystem: public ObjectNamed
{
public:
    CommSystem() = default;
    ~CommSystem() override = default;

    AST_OBJECT(CommSystem)
};

/*! @} */

AST_NAMESPACE_END