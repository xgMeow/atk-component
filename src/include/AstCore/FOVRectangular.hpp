/// @file      FOVRectangular.hpp
/// @brief     矩形视场类
/// @details   实现矩形视场的属性和方法
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-09

#pragma once

#include "FieldOfView.hpp"

AST_NAMESPACE_BEGIN

/// @brief 矩形视场类
class AST_CORE_API FOVRectangular: public FieldOfView
{
public:
    /// @brief 构造函数
    FOVRectangular() = default;

    /// @brief 析构函数
    ~FOVRectangular() override = default;

    /// @brief 获取视场类型
    /// @return 视场类型
    EFOVType getFOVType() const override { return EFOVType::eRectangular; }

    /// @brief 接受访问者
    /// @param visitor 访问者
    void accept(FieldOfViewVisitor& visitor) override { visitor.visit(*this); }

    /// @brief 计算方向向量到 FOV 边界的角度余量
    /// @param direction 传感器体坐标系中的单位方向向量
    /// @return min(xHalfAngle - |azimuth|, yHalfAngle - |elevation|)
    double angularMargin(const Vector3d& direction) const override;

    /// @brief 设置水平半角
    /// @param angle 水平半角（弧度）
    void setHorizontalHalfAngle(double angle) { horizontalHalfAngle_ = angle; }

    /// @brief 获取水平半角
    /// @return 水平半角（弧度）
    double getHorizontalHalfAngle() const { return horizontalHalfAngle_; }

    /// @brief 设置垂直半角
    /// @param angle 垂直半角（弧度）
    void setVerticalHalfAngle(double angle) { verticalHalfAngle_ = angle; }

    /// @brief 获取垂直半角
    /// @return 垂直半角（弧度）
    double getVerticalHalfAngle() const { return verticalHalfAngle_; }

private:
    double horizontalHalfAngle_{0.0};  ///< 水平半角（弧度）
    double verticalHalfAngle_{0.0};    ///< 垂直半角（弧度）
};

AST_NAMESPACE_END