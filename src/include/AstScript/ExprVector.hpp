/// @file      ExprVector.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-26

#pragma once

#include "AstGlobal.h"
#include "ExprContainer.hpp"
#include <vector>

AST_NAMESPACE_BEGIN


/// @brief 向量表达式，逗号分隔，例如 [1, 2, 3]、[a, b, c]
/// @details 
/// 每个向量元素之间用逗号分隔。
/// 向量元素可以是任意表达式，例如 [1 + 2, a * b, c]。
/// @ingroup Script
class AST_SCRIPT_API ExprVector: public ExprContainer
{
public:
    AST_EXPR(ExprVector)

    using ExprContainer::ExprContainer;

    /// @brief 求值
    /// @return Value* 求值结果
    Value* eval() const override;

    /// @brief 获取表达式字符串
    /// @param context 上下文对象
    /// @return std::string 表达式字符串
    std::string getExpression(Object* context) const override;

};

AST_NAMESPACE_END
