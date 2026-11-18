/// @file      FOVSAR.hpp
/// @brief     合成孔径雷达视场类
/// @details   实现合成孔径雷达视场的属性和方法
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-09

#pragma once

#include "FieldOfView.hpp"

AST_NAMESPACE_BEGIN

/// @brief 合成孔径雷达视场类
class AST_CORE_API FOVSAR: public FieldOfView
{
public:
    enum EUpdateMode{
        eConstant, ///< 常量模式
        eDynamic,  ///< 动态更新模式
    };
    /// @brief 构造函数
    FOVSAR() = default;

    /// @brief 析构函数
    ~FOVSAR() override = default;

    /// @brief 获取视场类型
    /// @return 视场类型
    EFOVType getFOVType() const override { return EFOVType::eSAR; }

    /// @brief 接受访问者
    /// @param visitor 访问者
    void accept(FieldOfViewVisitor& visitor) override { visitor.visit(*this); }

    /// @brief 计算方向向量到 FOV 边界的角度余量
    /// @param direction 传感器体坐标系中的单位方向向量
    /// @return min(elev - minElev, maxElev - elev, azimuthMargin)
    double angularMargin(const Vector3d& direction) const override;

    /// @brief 设置最小仰角
    /// @param angle 最小仰角（弧度）
    void setMinElevAngle(double angle) { minElevAngle_ = angle; }

    /// @brief 获取最小仰角
    /// @return 最小仰角（弧度）
    double getMinElevAngle() const { return minElevAngle_; }

    /// @brief 设置最大仰角
    /// @param angle 最大仰角（弧度）
    void setMaxElevAngle(double angle) { maxElevAngle_ = angle; }

    /// @brief 获取最大仰角
    /// @return 最大仰角（弧度）
    double getMaxElevAngle() const { return maxElevAngle_; }

    /// @brief 设置前向方位排除角
    /// @param angle 前向方位排除角（弧度）
    void setForwardExcludeAngle(double angle) { forwardExcludeAngle_ = angle; }

    /// @brief 获取前向方位排除角
    /// @return 前向方位排除角（弧度）
    double getForwardExcludeAngle() const { return forwardExcludeAngle_; }

    /// @brief 设置后向方位排除角
    /// @param angle 后向方位排除角（弧度）
    void setBackwardExcludeAngle(double angle) { backwardExcludeAngle_ = angle; }

    /// @brief 获取后向方位排除角
    /// @return 后向方位排除角（弧度）
    double getBackwardExcludeAngle() const { return backwardExcludeAngle_; }

    /// @brief 设置海拔高度
    /// @param altitude 海拔高度（米）
    void setAltitude(double altitude) { altitude_ = altitude; }

    /// @brief 获取海拔高度
    /// @return 海拔高度（米）
    double getAltitude() const { return altitude_; }

    /// @brief 设置更新模式
    /// @param mode 更新模式
    void setUpdateMode(EUpdateMode mode) { updateMode_ = mode; }

    /// @brief 获取更新模式
    /// @return 更新模式
    EUpdateMode getUpdateMode() const { return updateMode_; }

private:
    double minElevAngle_{0.0};          ///< 最小仰角
    double maxElevAngle_{0.0};          ///< 最大仰角
    double forwardExcludeAngle_{0.0};   ///< 前向方位排除角
    double backwardExcludeAngle_{0.0};  ///< 后向方位排除角
    double altitude_{0.0};              ///< 海拔高度
    EUpdateMode updateMode_{EUpdateMode::eConstant}; ///< 更新模式
};

AST_NAMESPACE_END