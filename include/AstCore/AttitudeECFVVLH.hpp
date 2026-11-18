/// @file      AttitudeECFVVLH.hpp
/// @brief     对地指向 + ECF 速度约束姿态
/// @details
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-28

#pragma once

#include "AstGlobal.h"
#include "AttitudeAlignConstrain.hpp"
#include "AttitudeVVLH.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Attitude
    @{
*/

/// @brief 对地指向 + ECF 速度约束姿态
/// @details "Nadir alignment with ECF velocity constraint"
/// 体 Z 轴严格对齐地心对地方向，体 X 轴在保持 Z 轴对齐的前提下尽量指向地固系速度方向。
/// 注意 ECF 速度与 ECI 速度在大偏心率轨道上差异很大(逼近远地点时尤为明显)
/// 与 @see AttitudeECIVVLH 的区别在于：计算该姿态的位置速度的参考系为天体固连系
class AST_CORE_API AttitudeECFVVLH : public AttitudeVVLH
{
public:
    AST_OBJECT(AttitudeECFVVLH)

    AttitudeECFVVLH();
    AttitudeECFVVLH(Point* point, Body* body);
    ~AttitudeECFVVLH() override = default;
private:
    // 屏蔽父类的 setFrame 方法
    void setFrame(Frame* frame) = delete;
public:
    void setBody(Body* body);
};

/*! @} */

AST_NAMESPACE_END
