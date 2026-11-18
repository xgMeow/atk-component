/// @file      VectorDisplacement.hpp
/// @brief     位移向量类，用于表示从原点到目标点的向量
/// @details   该类表示两个点之间的位移向量，通过原点(Origin)和目标点(Destination)定义。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-05-14

#pragma once

#include "AstGlobal.h"
#include "AstCore/Vector.hpp"
#include "AstCore/Point.hpp"

AST_NAMESPACE_BEGIN

class AST_CORE_API VectorDisplacement : public Vector
{
public:
    AST_OBJECT(VectorDisplacement)
    AST_PROPERT(Origin)
    AST_PROPERT(Destination)
    VectorDisplacement() = default;
    ~VectorDisplacement() override = default;



    /// @brief 获取向量所在的参考坐标系（使用原点的坐标系）
    /// @return 向量所在的参考坐标系指针
    Axes* getAxes() const override;

    /// @brief 获取位移向量在指定时间点的值
    /// @param tp 时间点
    /// @param vec 输出参数，位移向量（Destination - Origin）
    /// @return 错误码
    errc_t getVector(const TimePoint& tp, Vector3d& vec) const override;

    /// @brief 获取位移向量在指定时间点的值和速度
    /// @param tp 时间点
    /// @param vec 输出参数，位移向量（Destination - Origin）
    /// @param vel 输出参数，位移速度向量
    /// @return 错误码
    errc_t getVector(const TimePoint& tp, Vector3d& vec, Vector3d& vel) const override;
PROPERTIES:
    /// @brief 设置原点
    /// @param origin 原点指针
    void setOrigin(Point* origin);

    /// @brief 获取原点
    /// @return 原点指针
    Point* getOrigin() const;

    /// @brief 设置目标点
    /// @param destination 目标点指针
    void setDestination(Point* destination);

    /// @brief 获取目标点
    /// @return 目标点指针
    Point* getDestination() const;
private:
    /// @brief 获取参考坐标系（返回原点的坐标系）
    /// @return 参考坐标系指针
    Frame* getReferenceFrame() const;

private:
    WeakPtr<Point> origin_{ nullptr };      ///< 原点
    WeakPtr<Point> destination_{ nullptr }; ///< 目标点
};

AST_NAMESPACE_END