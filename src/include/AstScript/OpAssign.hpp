/// @file      OpAssign.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-19

#pragma once

#include "AstGlobal.h"
#include "Op.hpp"
#include "AstScript/ScriptAPI.hpp"

AST_NAMESPACE_BEGIN


/// @brief 赋值运算符表达式
/// @details
/// 赋值运算符表达式用于表示赋值操作，将右侧表达式的值赋值给左侧表达式。
/// @ingroup Script
class AST_SCRIPT_API OpAssign: public Op
{
public:
    AST_EXPR(OpAssign)

    OpAssign(EOpAssignType op, Expr* left, Expr* right)
        :op_{op}
        ,left_{left}
        ,right_{right}
    {};
    Value* eval() const override;
    std::string getExpression(Object* context=nullptr) const override;
    EOpAssignType op() const {return op_;}
    Expr* left() const {return left_.get();}
    Expr* right() const {return right_.get();}
protected:
    EOpAssignType op_;
    SharedPtr<Expr> left_;
    SharedPtr<Expr> right_;
};

AST_NAMESPACE_END
