/// @file      NotConstraint.hpp
/// @brief     非约束组合器
/// @details   对子约束取反：正值变负值、负值变正值，零点不变。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-22

#pragma once

#include "AccessConstraint.hpp"

AST_NAMESPACE_BEGIN

/// @brief 非约束组合器
/// @details evaluate() 返回 -子约束值。
///          子约束满足时为负，子约束违反时为正。
class AST_CORE_API NotConstraint : public AccessConstraint
{
public:
    AST_OBJECT(NotConstraint)

    NotConstraint() = default;
    explicit NotConstraint(AccessConstraint* constraint);

    void setConstraint(AccessConstraint* c) { constraint_ = c; }

    double evaluate(const TimePoint& time) const override;

private:
    SharedPtr<AccessConstraint> constraint_{};
};

AST_NAMESPACE_END
