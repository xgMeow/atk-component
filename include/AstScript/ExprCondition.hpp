/// @file      ExprCondition.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-24

#pragma once

#include "AstGlobal.h"
#include "Expr.hpp"
#include "AstScript/ScriptAPI.hpp"
#include "AstUtil/SharedPtr.hpp"

AST_NAMESPACE_BEGIN

/// @brief     条件表达式 (三元运算符 ? :)
/// @ingroup Script
class AST_SCRIPT_API ExprCondition: public Expr
{
public:
    AST_EXPR(ExprCondition)

public:
    ExprCondition(Expr* condition, Expr* thenExpr, Expr* elseExpr)
        : condition_(condition), thenExpr_(thenExpr), elseExpr_(elseExpr)
    {};
    virtual ~ExprCondition() = default;

    // accept函数由AST_EXPR宏自动生成，无需手动声明
    Value* eval() const override;
    errc_t setValue(Value* val) override;
    std::string getExpression(Object* context=nullptr) const override;

    Expr* condition() const { return condition_.get(); }
    Expr* thenExpr() const { return thenExpr_.get(); }
    Expr* elseExpr() const { return elseExpr_.get(); }
private:
    SharedPtr<Expr> condition_; ///< 条件表达式
    SharedPtr<Expr> thenExpr_;  ///< 条件为真时的表达式
    SharedPtr<Expr> elseExpr_;  ///< 条件为假时的表达式
};

AST_NAMESPACE_END