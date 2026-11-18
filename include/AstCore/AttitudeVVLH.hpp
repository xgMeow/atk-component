/// @file      AttitudeVVLH.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-30

#pragma once

#include "AstGlobal.h"
#include "AttitudeTrajectoryRelated.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 速度局部水平姿态(对原点定向 + 速度约束)
/// @details 
/// 体 Z 轴严格指向坐标系原点，体 X 轴在保持 Z 轴对齐的前提下尽量指向速度方向，
/// 由此得到的 VVLH(Vehicle Velocity Local Horizontal, 速度局部水平)系的姿态
class AST_CORE_API AttitudeVVLH : public AttitudeTrajectoryRelated
{
public:
    AST_OBJECT(AttitudeVVLH)

    AttitudeVVLH() = default;
    ~AttitudeVVLH() override = default;
public:
    errc_t getTransform(const TimePoint& tp, Rotation& rotation) const override;
    errc_t getTransform(const TimePoint& tp, KinematicRotation& rotation) const override;
};



/*! @} */

AST_NAMESPACE_END
