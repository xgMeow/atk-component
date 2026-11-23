/// @file      OpAssignPredefined.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-22

#pragma once

#include "AstGlobal.h"
#include "AstScript/ScriptAPI.hpp"

AST_NAMESPACE_BEGIN

AST_SCRIPT_API OpAssignFunc opassign_get_func(EOpAssignType op, Class* leftType, Class* rightType);


AST_NAMESPACE_END
