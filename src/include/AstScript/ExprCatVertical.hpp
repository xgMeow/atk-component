/// @file      ExprCatVertical.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-26

#pragma once

#include "AstGlobal.h"
#include "ExprContainer.hpp"

AST_NAMESPACE_BEGIN

/// @brief     垂直拼接表达式 (换行或;分隔)，例如[a; b; c]、[1; 2; 3]
/// @details   
/// 每个表达式占一行，或在表达式后添加分号。
/// 向量元素可以是任意表达式，例如 [1 + 2; a * b; c]。
/// @ingroup Script
class AST_SCRIPT_API ExprCatVertical: public ExprContainer
{
public:
    AST_EXPR(ExprCatVertical)

    using ExprContainer::ExprContainer;

    /// @brief 求值
    /// @return Value* 求值结果
    Value* eval() const override;

    /// @brief 获取表达式字符串
    /// @param context 上下文对象
    /// @return 表达式字符串
    std::string getExpression(Object *context) const override;
};



AST_NAMESPACE_END
