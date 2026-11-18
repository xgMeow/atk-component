/// @file      ExprRange.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-26

#pragma once

#include "AstGlobal.h"
#include "Expr.hpp"
#include "AstUtil/SharedPtr.hpp"

AST_NAMESPACE_BEGIN


/// @brief 范围表达式
/// @details 
/// 范围表达式用于表示一个范围，包含起始值、结束值和步长（可选）。
/// 步长表达式可选，默认值为1。
/// @ingroup Script
class AST_SCRIPT_API ExprRange : public Expr
{
public:
    AST_EXPR(ExprRange)

    /// @brief 范围表达式构造函数
    /// @param start 范围的起始值表达式
    /// @param stop 范围的结束值表达式
    /// @param step 范围的步长表达式（可选）
    ExprRange(Expr* start, Expr* stop, Expr* step=nullptr);
    ~ExprRange() override = default;

    /// @brief 获取范围的起始值表达式
    /// @return 范围的起始值表达式
    Expr* start() const { return start_.get(); }

    /// @brief 获取范围的结束值表达式
    /// @return 范围的结束值表达式
    Expr* stop() const { return stop_.get(); }

    /// @brief 获取范围的步长表达式
    /// @return 范围的步长表达式
    /// @warning 可能返回nullptr，此时表示步长表达式未指定，默认值为1
    Expr* step() const { return step_.get(); }


    /// @brief 评估范围表达式
    /// @return 范围表达式的结果值
    Value* eval() const override;


    /// @brief 获取范围表达式的字符串表示
    /// @param context 上下文对象（可选）
    /// @return 范围表达式的字符串表示
    std::string getExpression(Object *context) const override;

protected:
    SharedPtr<Expr> start_;
    SharedPtr<Expr> stop_;
    SharedPtr<Expr> step_;
};


AST_NAMESPACE_END
