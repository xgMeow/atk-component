/// @file      AttitudeRelSunLH.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-10-03

#pragma once

#include "AstGlobal.h"
#include "AstCore/AttitudeTrajectoryRelated.hpp"
#include "AstCore/AttitudeSunRelated.hpp"
#include "AstCore/CelestialBody.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 对原点对齐 + 太阳方向约束
/// @details "Nadir alignment with Sun constraint"
/// 体 Z 轴严格指向坐标系原点，体 X 轴在保持 Z 轴对齐的前提下尽量指向太阳方向，
class AST_CORE_API AttitudeRelSunLH : public AttitudeSunRelated
{
public:
    AttitudeRelSunLH() = default;
    AttitudeRelSunLH(Point* point, Frame* frame);
    ~AttitudeRelSunLH() = default;
public:
    errc_t getTransform(const TimePoint& tp, Rotation& rotation) const override;

    errc_t getTransform(const TimePoint& tp, KinematicRotation& rotation) const override;
};


/*! @} */

AST_NAMESPACE_END


