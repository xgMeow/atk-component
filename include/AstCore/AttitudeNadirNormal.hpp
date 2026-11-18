/// @file      AttitudeNadirNormal.hpp
/// @brief     对地指向 + 轨道法向约束姿态
/// @details
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-28

#pragma once

#include "AstGlobal.h"
#include "AttitudeAlignConstrain.hpp"
#include "AttitudeProfile.hpp"
#include "AttitudeTrajectoryRelated.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Attitude
    @{
*/

/// @brief 对地指向 + 轨道法向约束姿态
/// @details "Nadir Alignment with Orbit Normal Constraint"
/// 体 Z 轴严格对齐坐标系原点方向(对地指向)，体 X 轴在保持 Z 轴对齐的前提下尽量指向轨道法向(位置叉乘速度)
/// 对圆轨道而言该姿态与 VVLH 系只相差绕对地轴的一个固定转角
class AST_CORE_API AttitudeNadirNormal : public AttitudeTrajectoryRelated
{
public:
    AST_OBJECT(AttitudeNadirNormal)

    AttitudeNadirNormal() = default;
    AttitudeNadirNormal(Point* point, Body* body);
    AttitudeNadirNormal(Point* point, Frame* frame);
    ~AttitudeNadirNormal() override = default;
public:
    errc_t getTransform(const TimePoint& tp, Rotation& rotation) const override;
    errc_t getTransform(const TimePoint& tp, KinematicRotation& rotation) const override;
};

/*! @} */

AST_NAMESPACE_END
