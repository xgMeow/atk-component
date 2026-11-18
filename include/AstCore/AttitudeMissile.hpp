/// @file      AttitudeMissile.hpp
/// @brief     ECI 速度对齐 + 对地约束姿态
/// @details
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-10-03

#pragma once

#include "AstGlobal.h"
#include "AttitudeTrajectoryRelated.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Attitude
    @{
*/

/// @brief ECI 速度对齐 + 对地约束姿态
/// @details "ECI Velocity Alignment with Nadir Constraint"
/// 体 X 轴严格对齐惯性系速度方向(导弹纵轴指向)，体 Z 轴在保持 X 轴对齐的前提下尽量指向地心
/// 与 @see AttitudeAircraftZDown 的区别在于：计算该姿态的位置速度的参考系为天体惯性系，
/// 而不是天体固连系，故速度中不包含地球自转带来的牵连分量。
class AST_CORE_API AttitudeMissile : public AttitudeTrajectoryRelated
{
public:
    AST_OBJECT(AttitudeMissile)

    AttitudeMissile() = default;
    AttitudeMissile(Point* point, Body* body);
    ~AttitudeMissile() override = default;
public:
    errc_t getTransform(const TimePoint& tp, Rotation& rotation) const override;
    errc_t getTransform(const TimePoint& tp, KinematicRotation& rotation) const override;
private:
    // 屏蔽父类的 setFrame 方法
    void setFrame(Frame* frame) = delete;
public:
    void setBody(Body* body);
};

/*! @} */

AST_NAMESPACE_END
