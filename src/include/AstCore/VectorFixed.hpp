/// @file      VectorFixed.hpp
/// @brief     固定向量类，用于表示在指定轴系中分量保持不变的向量 (对应STK的Fixed in Axes)
/// @details   该类表示一个在指定Axes参考系中具有恒定分量的三维向量。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-15

#pragma once

#include "AstGlobal.h"
#include "AstCore/Vector.hpp"
#include "AstCore/Axes.hpp"

AST_NAMESPACE_BEGIN

/// @brief 固定向量类 (Fixed in Axes)
/// @details 表示一个在指定轴系(Axes)中分量保持不变的向量。
///          无论何时查询，向量值和速度都保持不变。
///          典型用途：在航天器本体坐标系中表示固定的天线指向、
///          在体固连坐标系中表示固定的位置偏移等。
class AST_CORE_API VectorFixed : public Vector
{
public:
    AST_OBJECT(VectorFixed)
    AST_PROPERT(Axes)
    AST_PROPERT(Value)

    VectorFixed() = default;
    ~VectorFixed() override = default;

    /// @brief 获取向量所在的参考坐标系
    /// @return 向量所在的参考轴系指针
    Axes* getAxes() const override;

    /// @brief 获取向量在指定时间点的值 (始终返回恒定的向量值)
    /// @param tp 时间点 (本类中不使用，向量值恒定)
    /// @param vec 输出参数，向量的值
    /// @return 错误码
    errc_t getVector(const TimePoint& tp, Vector3d& vec) const override;

    /// @brief 获取向量在指定时间点的位置和速度 (速度始终为零向量)
    /// @param tp 时间点 (本类中不使用，向量值恒定)
    /// @param vec 输出参数，向量的值
    /// @param vel 输出参数，向量的速度向量 (始终为零)
    /// @return 错误码
    errc_t getVector(const TimePoint& tp, Vector3d& vec, Vector3d& vel) const override;

PROPERTIES:
    /// @brief 设置参考轴系
    /// @param axes 参考轴系指针
    void setAxes(Axes* axes);

    /// @brief 设置向量值
    /// @param value 向量值
    void setValue(const Vector3d& value);

    /// @brief 获取向量值
    /// @return 向量值
    const Vector3d& getValue() const;

private:
    WeakPtr<Axes> axes_{ nullptr };     ///< 参考轴系 (向量所在的坐标系)
    Vector3d      value_{ 0, 0, 0 };    ///< 恒定的向量值
};

AST_NAMESPACE_END
