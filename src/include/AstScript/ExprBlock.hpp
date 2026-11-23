/// @file      ExprBlock.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-24

#pragma once

#include "AstGlobal.h"
#include "ExprContainer.hpp"
#include <vector>

AST_NAMESPACE_BEGIN

/// @brief     代码块表达式
/// @ingroup Script
class AST_SCRIPT_API ExprBlock: public ExprContainer
{
public:
    AST_EXPR(ExprBlock)

    using ExprContainer::ExprContainer;

    ~ExprBlock() override = default;

    /// @brief 求值
    /// @return Value* 求值结果
    Value* eval() const override;

    /// @brief 设置表达式的值
    errc_t setValue(Value* val) override;

    /// @brief 获取表达式的字符串表示
    /// @param context 可选的上下文对象，用于解析变量等
    /// @return std::string 表达式的字符串表示
    std::string getExpression(Object* context=nullptr) const override;

    /// @brief 添加表达式到代码块
    /// @param expr 要添加的表达式
    void addExpr(Expr* expr);

};



AST_NAMESPACE_END