/// @file      ShooterResult.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-28

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Object.hpp"
#include "AstUtil/ObjectNamed.hpp"
#include "AstScript/Expr.hpp"
#include <string>

AST_NAMESPACE_BEGIN

/// @brief 结果变量，用于定义微分修正中的结果变量
class AST_CORE_API ShooterResult : public ObjectNamed
{
public:
    AST_OBJECT(ShooterResult)
    AST_PROPERT(active)
    AST_PROPERT(desired)
    AST_PROPERT(scale)
    AST_PROPERT(tolerance)
    AST_PROPERT(valid)
    AST_PROPERT(weight)
    AST_PROPERT(expr)
    static ShooterResult* New();

    ShooterResult() = default;
    ~ShooterResult() override = default;

PROPERTIES:
    bool active() const { return active_; }
    void setActive(bool active) { active_ = active; }

    double desired() const { return desired_; }
    void setDesired(double desired) { desired_ = desired; }

    double scale() const { return scale_; }
    void setScale(double scale) { scale_ = scale; }

    double tolerance() const { return tolerance_; }
    void setTolerance(double tolerance) { tolerance_ = tolerance; }

    bool valid() const { return valid_; }
    void setValid(bool valid) { valid_ = valid; }

    double weight() const { return weight_; }
    void setWeight(double weight) { weight_ = weight; }

    /// @brief 获取变量的值
    errc_t getValue(double& value) const;

    Expr* expr() const { return expr_.get(); }
    void setExpr(Expr* expr) { expr_ = expr; }
private:
    bool active_{false};        ///< 是否激活
    bool valid_{true};          ///< 数值是否有效
    WeakPtr<Expr> expr_{};        ///< 计算表达式
    double desired_{0.0};       ///< 目标值
    double scale_{1.0};         ///< 缩放因子
    double tolerance_{0.0};     ///< 容差
    double weight_{1.0};        ///< 权重
};

AST_NAMESPACE_END