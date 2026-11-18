/// @file      ValInt.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-19

#pragma once

#include "AstGlobal.h"
#include "AstScript/ValScalar.hpp"

AST_NAMESPACE_BEGIN

/// @brief 整数值
/// @ingroup Script
class AST_SCRIPT_API ValInt: public ValScalar<int>
{
public:
    AST_EXPR(ValInt)
    ValInt()
        : ValScalar<int>(0)
    {}
    ValInt(int value)
        : ValScalar<int>(value)
    {}
};

AST_NAMESPACE_END
