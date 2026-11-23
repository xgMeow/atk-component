/// @file      ValDouble.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-19

#pragma once

#include "AstGlobal.h"
#include "AstScript/ValScalar.hpp"

AST_NAMESPACE_BEGIN

/// @brief 双精度浮点值
/// @ingroup Script
class AST_SCRIPT_API ValDouble: public ValScalar<double>
{
public:
    AST_EXPR(ValDouble)
    ValDouble()
        : ValScalar<double>(0.0)
    {}
    ValDouble(double value)
        : ValScalar<double>(value)
    {}
};

AST_NAMESPACE_END
