/// @file      FOVConical.hpp
/// @brief     复杂圆锥视场类
/// @details   实现复杂圆锥视场的属性和方法
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-09

#pragma once

#include "FieldOfView.hpp"

AST_NAMESPACE_BEGIN

/// @brief 复杂圆锥视场类
class AST_CORE_API FOVConical: public FieldOfView
{
public:
    /// @brief 构造函数
    FOVConical() = default;

    /// @brief 析构函数
    ~FOVConical() override = default;

    /// @brief 获取视场类型
    /// @return 视场类型
    EFOVType getFOVType() const override { return EFOVType::eConical; }

    /// @brief 接受访问者
    /// @param visitor 访问者
    void accept(FieldOfViewVisitor& visitor) override { visitor.visit(*this); }

    /// @brief 计算方向向量到 FOV 边界的角度余量
    /// @param direction 传感器体坐标系中的单位方向向量
    /// @return min(outerCone - angle, angle - innerCone, clockMargin)
    double angularMargin(const Vector3d& direction) const override;

    /// @brief 设置内锥角
    /// @param angle 内锥角（弧度）
    void setInnerConeAngle(double angle) { innerConeAngle_ = angle; }

    /// @brief 获取内锥角
    /// @return 内锥角（弧度）
    double getInnerConeAngle() const { return innerConeAngle_; }

    /// @brief 设置外锥角
    /// @param angle 外锥角（弧度）
    void setOuterConeAngle(double angle) { outerConeAngle_ = angle; }

    /// @brief 获取外锥角
    /// @return 外锥角（弧度）
    double getOuterConeAngle() const { return outerConeAngle_; }

    /// @brief 设置最小时钟角
    /// @param angle 最小时钟角（弧度）
    void setMinClockAngle(double angle) { minClockAngle_ = angle; }

    /// @brief 获取最小时钟角
    /// @return 最小时钟角（弧度）
    double getMinClockAngle() const { return minClockAngle_; }

    /// @brief 设置最大时钟角
    /// @param angle 最大时钟角（弧度）
    void setMaxClockAngle(double angle) { maxClockAngle_ = angle; }

    /// @brief 获取最大时钟角
    /// @return 最大时钟角（弧度）
    double getMaxClockAngle() const { return maxClockAngle_; }

private:
    double innerConeAngle_{0.0};  ///< 内锥角（弧度）
    double outerConeAngle_{0.0};  ///< 外锥角（弧度）
    double minClockAngle_{0.0};   ///< 最小时钟角（弧度）
    double maxClockAngle_{0.0};   ///< 最大时钟角（弧度）
};

AST_NAMESPACE_END