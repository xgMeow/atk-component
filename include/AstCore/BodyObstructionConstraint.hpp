/// @file      BodyObstructionConstraint.hpp
/// @brief     天体遮挡约束
/// @details   检查两个对象之间的视线是否被中心天体遮挡。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-22



#pragma once

#include "AccessConstraint.hpp"
#include "AstCore/CelestialBody.hpp"

AST_NAMESPACE_BEGIN

/// @brief 天体遮挡约束
/// @details 计算从观测者到目标的视线到天体表面的最短有符号距离。
///          正值表示无遮挡，负值表示被遮挡，零为相切。
class AST_CORE_API BodyObstructionConstraint : public AccessConstraint
{
public:
    AST_OBJECT(BodyObstructionConstraint)

    BodyObstructionConstraint() = default;
    A_DISABLE_COPY(BodyObstructionConstraint);

    /// @brief 构造天体遮挡约束
    /// @param fromObject 观测者
    /// @param toObject 目标
    /// @param centralBody 中心天体
    BodyObstructionConstraint(Point* fromObject, Point* toObject, CelestialBody* centralBody);

    double evaluate(const TimePoint& time) const override;

    void setFromObject(Point* obj) { fromObject_ = obj; }
    Point* fromObject() const { return fromObject_; }

    void setToObject(Point* obj) { toObject_ = obj; }
    Point* toObject() const { return toObject_; }

    void setCentralBody(CelestialBody* body) { centralBody_ = body; }
    CelestialBody* centralBody() const { return centralBody_; }

private:
    Point*          fromObject_{};
    Point*          toObject_{};
    CelestialBody*  centralBody_{};
};

AST_NAMESPACE_END
