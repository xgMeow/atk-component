/// @file      AttitudeCbiVelSun.hpp
/// @brief     CBI 速度对齐 + 太阳方向约束姿态
/// @details
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-10-04

#pragma once

#include "AstGlobal.h"
#include "AstCore/AttitudeTrajectoryRelated.hpp"
#include "AstCore/AttitudeSunRelated.hpp"
#include "AstCore/CelestialBody.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Attitude
    @{
*/


/// @brief CBI 速度对齐 + 太阳方向约束姿态
/// @details "ECI Velocity Alignment with Sun Constraint"
/// 体 X 轴严格对齐惯性系速度方向，体 Z 轴在保持 X 轴对齐的前提下尽量指向太阳
class AST_CORE_API AttitudeCbiVelSun : public AttitudeSunRelated
{
public:
    AST_OBJECT(AttitudeCbiVelSun)

    AttitudeCbiVelSun() = default;
    AttitudeCbiVelSun(Point* point, Body* body);
    ~AttitudeCbiVelSun() override = default;
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
