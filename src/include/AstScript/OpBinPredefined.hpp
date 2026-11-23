/// @file      OperatorBinary.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-22

#pragma once

#include "AstGlobal.h"
#include "AstScript/ScriptAPI.hpp"

AST_NAMESPACE_BEGIN

class Value;


AST_SCRIPT_API Value* opbin(EOpBinType op, Value* left, Value* right);

AST_SCRIPT_API OpBinFunc opbin_get_func(EOpBinType op, Class* leftType, Class* rightType);

AST_NAMESPACE_END
