/// @file      AndConstraint.hpp
/// @brief     与约束组合器
/// @details   min(所有子约束值)，全部满足才算满足，短路计算。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-22

#pragma once

#include "AccessConstraint.hpp"
#include <vector>
#include <limits>

AST_NAMESPACE_BEGIN

/// @brief 与约束组合器
/// @details 所有子约束同时满足才算满足。
///          evaluate() 返回 min(子约束值)，遇到非正立即短路。
class AST_CORE_API AndConstraint : public AccessConstraint
{
public:
    AST_OBJECT(AndConstraint)

    AndConstraint() = default;

    /// @brief 添加子约束
    void add(AccessConstraint* constraint) { constraints_.push_back(constraint); }

    /// @brief 获取子约束数量
    size_t size() const { return constraints_.size(); }

    double evaluate(const TimePoint& time) const override;

private:
    std::vector<SharedPtr<AccessConstraint>> constraints_{};
};

AST_NAMESPACE_END
