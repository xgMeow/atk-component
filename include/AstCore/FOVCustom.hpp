/// @file      FOVCustom.hpp
/// @brief     自定义视场类
/// @details   实现自定义视场的属性和方法
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-09

#pragma once

#include "FieldOfView.hpp"
#include "AstMath/Vector.hpp"

AST_NAMESPACE_BEGIN

/// @brief 自定义视场类
class AST_CORE_API FOVCustom: public FieldOfView
{
public:
    /// @brief 构造函数
    FOVCustom() = default;

    /// @brief 析构函数
    ~FOVCustom() override = default;

    /// @brief 获取视场类型
    /// @return 视场类型
    EFOVType getFOVType() const override { return EFOVType::eCustom; }

    /// @brief 接受访问者
    /// @param visitor 访问者
    void accept(FieldOfViewVisitor& visitor) override { visitor.visit(*this); }

    /// @brief 计算方向向量到 FOV 边界的角度余量
    /// @param direction 传感器体坐标系中的单位方向向量
    /// @return 调用用户自定义函数，默认返回 -1.0（不在视场内）
    double angularMargin(const Vector3d& direction) const override;

    /// @brief 添加顶点
    /// @param vertex 顶点坐标
    void addVertex(const Vector3d& vertex) { vertices_.push_back(vertex); }

    /// @brief 获取顶点列表
    /// @return 顶点列表
    const std::vector<Vector3d>& getVertices() const { return vertices_; }

private:
    std::vector<Vector3d> vertices_{};  ///< 自定义视场的顶点列表
};

AST_NAMESPACE_END