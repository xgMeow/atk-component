/// @file      Symbol.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-21

#pragma once

#include "AstGlobal.h"
#include "AstScript/Expr.hpp"
#include "AstUtil/StringView.hpp"
#include <string>

AST_NAMESPACE_BEGIN


/// @brief 符号表达式
/// @details 表示变量或函数的名称
/// @ingroup Script
class AST_SCRIPT_API Symbol: public Expr{
public:
    AST_EXPR(Symbol)

    Symbol(StringView name)
        : name_(name) {}

    const std::string& name() const { return name_; }

    std::string getExpression(Object* object) const override {
        return name_;
    }
    Value* eval() const final;
    errc_t setValue(Value* value) final;
public:
    Expr* resolve() const;
private:
    std::string name_;
};

AST_NAMESPACE_END

