/// @file      AttitudeECFVelRadial.hpp
/// @brief     ECF 速度对齐 + 径向约束姿态
/// @details
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-28

#pragma once

#include "AstGlobal.h"
#include "AttitudeAlignConstrain.hpp"
#include "AstCore/AttitudeTrajectoryRelated.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Attitude
    @{
*/

/// @brief ECF 速度对齐 + 径向约束姿态
/// @details "ECF Velocity Alignment with Radial Constraint"
/// 体 X 轴严格对齐地固系速度方向，体 Z 轴在保持 X 轴对齐的前提下尽量指向径向(远离地心)
/// 常用于飞机、地面车辆等大气层内载体
class AST_CORE_API AttitudeECFVelRadial : public AttitudeTrajectoryRelated
{
public:
    AST_OBJECT(AttitudeECFVelRadial)

    AttitudeECFVelRadial() = default;
    AttitudeECFVelRadial(Point* point, Body* body);
    ~AttitudeECFVelRadial() override = default;
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
