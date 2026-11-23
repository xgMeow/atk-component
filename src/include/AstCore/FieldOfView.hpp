/// @file      FieldOfView.hpp
/// @brief     视场基类
/// @details   定义视场的基本接口和属性
/// @author    金柯<jinke18@foxmail.com>
/// @date      2025-12-12

#pragma once

#include "AstGlobal.h"
#include "AstUtil/Object.hpp"
#include "AstUtil/ObjectNamed.hpp"
#include "FieldOfViewVisitor.hpp"

AST_NAMESPACE_BEGIN

/// @brief 视场类型枚举
enum class EFOVType
{
    eSimpleCone,   ///< 简单圆锥视场
    eConical,      ///< 复杂圆锥视场
    eHalfPower,    ///< 半功率视场
    eRectangular,  ///< 矩形视场
    eSAR,          ///< 合成孔径雷达视场
    eCustom        ///< 自定义视场
};

/// @brief 视场基类
class AST_CORE_API FieldOfView: public ObjectNamed
{
public:
    /// @brief 构造函数
    FieldOfView() = default;

    /// @brief 析构函数
    virtual ~FieldOfView() = default;

    /// @brief 获取视场类型
    /// @return 视场类型
    virtual EFOVType getFOVType() const = 0;

    /// @brief 接受访问者
    /// @param visitor 访问者
    virtual void accept(FieldOfViewVisitor& visitor) = 0;

    /// @brief 计算方向向量到 FOV 边界的角度余量（弧度）
    /// @param direction 传感器体坐标系中的方向向量（视轴 = +Z）
    /// @return 角度余量(rad)：>0 在视场内，<0 在视场外，==0 恰在边界
    virtual double angularMargin(const Vector3d& direction) const = 0;

    /// @brief 便捷方法：方向是否在视场内
    /// @param direction 传感器体坐标系中的方向向量
    /// @return 是否在视场内
    bool containsDirection(const Vector3d& direction) const {
        return angularMargin(direction) > 0.0;
    }

    /// @brief 便捷方法：目标点是否在视场内
    /// @param targetPosInSensorFrame 目标在传感器体坐标系中的位置
    /// @return 是否在视场内
    bool containsPoint(const Vector3d& targetPosInSensorFrame) const {
        return angularMargin(targetPosInSensorFrame) > 0.0;
    }

protected:
};

AST_NAMESPACE_END