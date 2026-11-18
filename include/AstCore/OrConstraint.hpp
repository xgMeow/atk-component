/// @file      OrConstraint.hpp
/// @brief     或约束组合器
/// @details   max(所有子约束值)，任一满足就算满足，短路计算。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-22

#pragma once

#include "AccessConstraint.hpp"
#include <vector>
#include <limits>

AST_NAMESPACE_BEGIN

/// @brief 或约束组合器
/// @details 任一子约束满足就算满足。
///          evaluate() 返回 max(子约束值)，遇到正立即短路。
class AST_CORE_API OrConstraint : public AccessConstraint
{
public:
    AST_OBJECT(OrConstraint)

    OrConstraint() = default;

    /// @brief 添加子约束
    void add(AccessConstraint* constraint) { constraints_.push_back(constraint); }

    /// @brief 获取子约束数量
    size_t size() const { return constraints_.size(); }

    double evaluate(const TimePoint& time) const override;

private:
    std::vector<SharedPtr<AccessConstraint>> constraints_{};
};

AST_NAMESPACE_END
