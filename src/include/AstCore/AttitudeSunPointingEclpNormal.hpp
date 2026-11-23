/// @file      AttitudeSunPointingEclpNormal.hpp
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

/// @brief     太阳指向 + 黄道法向约束姿态
/// @details   "Sun Alignment with Ecliptic Normal Constraint"
/// 体 X 轴严格指向太阳方向，体 Z 轴在保持 X 轴对齐的前提下尽量指向黄道面法向
class AST_CORE_API AttitudeSunPointingEclpNormal : public AttitudeSunRelated
{
public:
    AST_OBJECT(AttitudeSunPointingEclpNormal)

    AttitudeSunPointingEclpNormal() = default;
    AttitudeSunPointingEclpNormal(Point* point, Frame* frame);
    AttitudeSunPointingEclpNormal(Point* point, Body* body);
    ~AttitudeSunPointingEclpNormal() override = default;
public:
    errc_t getTransform(const TimePoint& tp, Rotation& rotation) const override;
    errc_t getTransform(const TimePoint& tp, KinematicRotation& rotation) const override;
protected:
    /// @brief 黄道面法向(黄道北极)在参考坐标系下的方向
    errc_t getEclipticNormalLocal(const TimePoint& tp, Vector3d& normal) const;
    /// @brief 黄道面法向在参考坐标系下的方向及其时间变化率
    errc_t getEclipticNormalLocal(const TimePoint& tp, Vector3d& normal, Vector3d& normalRate) const;
};

/*! @} */

AST_NAMESPACE_END
