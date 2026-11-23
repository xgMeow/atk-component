/// @file      ExprLoop.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-24

#pragma once

#include "AstGlobal.h"
#include "Expr.hpp"
#include "ExprBlock.hpp"
#include "AstUtil/SharedPtr.hpp"

AST_NAMESPACE_BEGIN

/// @brief     循环表达式基类
/// @ingroup Script
class AST_SCRIPT_API ExprLoop: public Expr
{
public:
    using Expr::Expr;
    ~ExprLoop() override = default;
};


/// @brief     while 循环表达式
/// @details   Julia语法: while condition; body end
/// @ingroup Script
class AST_SCRIPT_API ExprWhile: public ExprLoop
{
public:
    AST_EXPR(ExprWhile)

    /// @brief 构造函数
    ExprWhile();

    /// @brief 构造函数
    /// @param condition 循环条件表达式
    /// @param body 循环体
    ExprWhile(Expr* condition, Expr* body);

    ~ExprWhile() override = default;

    /// @brief 求值
    /// @return Value* 求值结果
    Value* eval() const override;

    /// @brief 设置表达式的值
    errc_t setValue(Value* val) override;

    /// @brief 获取表达式的字符串表示
    /// @param context 可选的上下文对象，用于解析变量等
    /// @return std::string 表达式的字符串表示
    std::string getExpression(Object* context=nullptr) const override;

    /// @brief 获取循环条件表达式
    Expr* condition() const { return condition_.get(); }

    /// @brief 获取循环体表达式
    Expr* body() const { return body_.get(); }

protected:
    SharedPtr<Expr> condition_; ///< 循环条件表达式
    SharedPtr<Expr> body_;      ///< 循环体
};



/// @brief     for 循环表达式（范围风格）
/// @details   Julia语法: for variable in range; body end
/// @ingroup Script
class AST_SCRIPT_API ExprForRange: public ExprLoop
{
public:
    AST_EXPR(ExprForRange)

    /// @brief 构造函数
    ExprForRange();

    /// @brief 构造函数
    /// @param variable 循环变量
    /// @param range 范围表达式
    /// @param body 循环体
    ExprForRange(Expr* variable, Expr* range, Expr* body);

    ~ExprForRange() override = default;

    /// @brief 求值
    /// @return Value* 求值结果
    Value* eval() const override;

    /// @brief 设置表达式的值
    errc_t setValue(Value* val) override;

    /// @brief 获取表达式的字符串表示
    /// @param context 可选的上下文对象，用于解析变量等
    /// @return std::string 表达式的字符串表示
    std::string getExpression(Object* context=nullptr) const override;

    /// @brief 获取循环变量表达式
    Expr* variable() const { return variable_.get(); }

    /// @brief 获取范围表达式
    Expr* range() const { return range_.get(); }

    /// @brief 获取循环体表达式
    Expr* body() const { return body_.get(); }

protected:
    SharedPtr<Expr> variable_; ///< 循环变量
    SharedPtr<Expr> range_;    ///< 范围表达式
    SharedPtr<Expr> body_;     ///< 循环体
};


AST_NAMESPACE_END