/// @file      FieldOfViewConstraint.hpp
/// @brief     视场约束
/// @details   检查目标是否在传感器的视场内。
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-07-22

#pragma once

#include "AccessConstraint.hpp"
#include "AstCore/FieldOfView.hpp"

AST_NAMESPACE_BEGIN

class Frame;

/// @brief 视场约束
/// @details 计算目标方向到视场边界的角度余量。
///          正值表示在视场内，负值表示在视场外，零为恰在边界。
class AST_CORE_API FieldOfViewConstraint : public AccessConstraint
{
public:
    AST_OBJECT(FieldOfViewConstraint)

    FieldOfViewConstraint() = default;
    A_DISABLE_COPY(FieldOfViewConstraint);

    /// @brief 构造视场约束
    /// @param frame 传感器坐标系
    /// @param target 待检测的对象
    /// @param fov 视场定义
    FieldOfViewConstraint(Frame* frame, Point* target, FieldOfView* fov);

    double evaluate(const TimePoint& time) const override;

    void setFrame(Frame* f) { frame_ = f; }
    Frame* frame() const { return frame_; }

    void setTarget(Point* p) { target_ = p; }
    Point* target() const { return target_; }

    void setFieldOfView(FieldOfView* fov) { fov_ = fov; }
    FieldOfView* fieldOfView() const { return fov_; }

private:
    Frame*        frame_{};
    Point*        target_{};
    FieldOfView*  fov_{};
};

AST_NAMESPACE_END
