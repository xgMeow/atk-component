/// @file      DistanceConstraint.hpp
/// @brief     两点距离约束
/// @details   计算主、次两点之间的距离，并返回阈值减去距离的有符号特征值。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-08-19

#pragma once

#include "AccessConstraint.hpp"

AST_NAMESPACE_BEGIN

class Point;

/// @brief 两点距离约束
/// @details 特征值 = 阈值 - 两点距离。两点须在同一坐标系下给出位置
///          （典型用法：两个 SGP4 预报器，均输出 TEME 系）。
class AST_CORE_API DistanceConstraint : public AccessConstraint
{
public:
    AST_OBJECT(DistanceConstraint)

    DistanceConstraint() = default;
    A_DISABLE_COPY(DistanceConstraint);

    /// @brief 构造两点距离约束
    /// @param primary   主对象
    /// @param secondary 次对象
    /// @param threshold 距离阈值 [m]
    DistanceConstraint(Point* primary, Point* secondary, double threshold);

    double evaluate(const TimePoint& time) const override;

    void setPrimary(Point* p) { primary_ = p; }
    Point* primary() const { return primary_; }

    void setSecondary(Point* p) { secondary_ = p; }
    Point* secondary() const { return secondary_; }

    void setThreshold(double v) { threshold_ = v; }
    double threshold() const { return threshold_; }

private:
    Point*  primary_{};     ///< 主对象
    Point*  secondary_{};   ///< 次对象
    double  threshold_{0.0};///< 距离阈值 [m]
};

AST_NAMESPACE_END
