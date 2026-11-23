/// @file      ValNull.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-19

#pragma once

#include "AstGlobal.h"
#include "Value.hpp"

AST_NAMESPACE_BEGIN

/// @brief 空值
/// @ingroup Script
class AST_SCRIPT_API ValNull: public Value
{
public:
    AST_EXPR(ValNull)

    using Value::Value;
    std::string getExpression(Object* context=nullptr) const override{
        return "null";
    }
};


AST_NAMESPACE_END
