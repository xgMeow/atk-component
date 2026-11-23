/// @file      AttitudeECIVVLH.hpp
/// @brief     对地指向 + ECI 速度约束姿态
/// @details
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-28

#pragma once

#include "AstGlobal.h"
#include "AttitudeProfile.hpp"
#include "AttitudeTrajectoryRelated.hpp"
#include "AttitudeVVLH.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Attitude
    @{
*/

/// @brief 对地指向 + ECI 速度约束姿态
/// @details "Nadir alignment with ECI velocity constraint"
/// 体 Z 轴严格对齐地心对地方向，体 X 轴在保持 Z 轴对齐的前提下尽量指向惯性系速度方向，
/// 由此得到的姿态即 VVLH(Vehicle Velocity Local Horizontal, 速度局部水平)系在惯性系下的姿态
/// 与 @see AttitudeVVLH 的区别在于：计算该姿态的位置速度的参考系为天体惯性系
class AST_CORE_API AttitudeECIVVLH : public AttitudeVVLH
{
public:
    AST_OBJECT(AttitudeECIVVLH)

    AttitudeECIVVLH();
    AttitudeECIVVLH(Point* point, Body* body);
    ~AttitudeECIVVLH() override = default;
private:
    // 屏蔽父类的 setFrame 方法
    void setFrame(Frame* frame) = delete;
public:
    void setBody(Body* body);
};

/*! @} */

AST_NAMESPACE_END
