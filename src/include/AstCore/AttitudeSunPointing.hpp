/// @file      AttitudeSunPointing.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-10-05

#pragma once

#include "AstGlobal.h"
#include "AstCore/AttitudeSunRelated.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Attitude
    @{
*/


/// @brief 太阳指向姿态
/// @details "Sun Alignment with Nadir Constraint"
/// 体 X 轴严格指向太阳方向，体 Z 轴在保持 X 轴对齐的前提下尽量指向坐标系原点
class AST_CORE_API AttitudeSunPointing : public AttitudeSunRelated
{
public:
    AST_OBJECT(AttitudeSunPointing)

    AttitudeSunPointing() = default;
    AttitudeSunPointing(Point* point, Frame* frame);
    AttitudeSunPointing(Point* point, Body* body);
    ~AttitudeSunPointing() override = default;
public:
    errc_t getTransform(const TimePoint& tp, Rotation& rotation) const override;
    errc_t getTransform(const TimePoint& tp, KinematicRotation& rotation) const override;
};


/*! @} */

AST_NAMESPACE_END
