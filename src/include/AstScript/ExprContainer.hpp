/// @file      ExprContainer.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-26

#pragma once

#include "AstGlobal.h"
#include "Expr.hpp"
#include "AstUtil/SharedPtr.hpp"
#include <vector>

AST_NAMESPACE_BEGIN


/// @brief 表达式容器类
/// @ingroup Script
class AST_SCRIPT_API ExprContainer: public Expr
{
public:
    using VectorType = std::vector<SharedPtr<Expr>>;

    ExprContainer() = default;

    explicit ExprContainer(const VectorType& elems)
        : elems_(elems) {}

    /// @brief 获取向量元素
    /// @param index 元素索引
    /// @return 向量元素指针
    Expr* at(size_t index) const { return elems_[index].get(); }

    /// @brief 获取向量元素数量
    /// @return 元素数量
    size_t size() const { return elems_.size(); }

    /// @brief 添加表达式到容器
    /// @param expr 要添加的表达式
    void push_back(Expr* expr) { elems_.push_back(expr); }

    /// @brief 获取表达式容器
    /// @return 表达式容器引用
    const VectorType& children() const { return elems_; }
protected:
    VectorType elems_{};     ///< 表达式容器
};

AST_NAMESPACE_END
