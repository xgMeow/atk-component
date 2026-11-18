/// @file      AttitudeSunPointingCbiZ.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-10-06

#pragma once

#include "AstGlobal.h"
#include "AttitudeSunRelated.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief     太阳指向 + 天体惯性系Z轴方向约束
/// @details   "Sun Alignment with ECI Z Axis Constraint"
/// 体 X 轴严格指向太阳方向，体 Z 轴在保持 X 轴对齐的前提下尽量指向天体惯性系Z轴方向。
/// 参考坐标系固定为天体惯性系，因此约束方向即该系的 Z 轴(极轴方向)。
class AST_CORE_API AttitudeSunPointingCbiZ : public AttitudeSunRelated
{
public:
    AST_OBJECT(AttitudeSunPointingCbiZ)

    AttitudeSunPointingCbiZ() = default;
    AttitudeSunPointingCbiZ(Point* point, Body* body);
    ~AttitudeSunPointingCbiZ() override = default;
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
