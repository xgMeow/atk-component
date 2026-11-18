/// @file      ValBool.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-19

#pragma once

#include "AstGlobal.h"
#include "AstScript/ValScalar.hpp"

AST_NAMESPACE_BEGIN

/// @brief 布尔值
/// @ingroup Script
class AST_SCRIPT_API ValBool: public ValScalar<bool>
{
public:
    AST_EXPR(ValBool)
    ValBool()
        : ValScalar<bool>(false)
    {}
    ValBool(bool value)
        : ValScalar<bool>(value)
    {}

    using ValScalar<bool>::ValScalar;
};



AST_NAMESPACE_END
