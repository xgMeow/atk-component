/// @file      Op.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-19

#pragma once

#include "AstGlobal.h"
#include "AstScript/Expr.hpp"
#include "AstUtil/SharedPtr.hpp"

AST_NAMESPACE_BEGIN

/// @brief 运算符表达式
/// @ingroup Script
class AST_SCRIPT_API Op: public Expr
{
public:
    errc_t setValue(Value* val) override{return eErrorReadonly;}

};

AST_NAMESPACE_END
