/// @file      AttitudeAircraftZDown.hpp
/// @brief     对地指向 + ECF 速度约束的机体 Z 朝下姿态
/// @details
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-28

#pragma once

#include "AstGlobal.h"
#include "AttitudeAlignConstrain.hpp"
#include "AttitudeTrajectoryRelated.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Attitude
    @{
*/

/// @brief 对地指向 + ECF 速度约束的机体 Z 朝下姿态
/// @details "ECF Velocity Alignment with Nadir Constraint" 
/// 即飞机、船舶、地面车辆等"大圆弧载体"的默认姿态：
/// 体 X 轴严格对齐地固系速度方向(机头指向)，体 Z 轴在保持 X 轴对齐的前提下尽量指向地心 (机体 Z 朝下)
class AST_CORE_API AttitudeAircraftZDown : public AttitudeTrajectoryRelated
{
public:
    AST_OBJECT(AttitudeAircraftZDown)

    AttitudeAircraftZDown() = default;
    AttitudeAircraftZDown(Point* point, Body* body);
    ~AttitudeAircraftZDown() override = default;
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
