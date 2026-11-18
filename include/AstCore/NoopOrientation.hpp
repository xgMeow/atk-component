/// @file      NoopOrientation.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-06

#pragma once

#include "AstGlobal.h"
#include "AstCore/BodyOrientation.hpp"
#include "AstCore/BuiltinAxes.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup SolarSystem
    @{
*/

/// @brief 空操作旋转类
class AST_CORE_API NoopOrientation final: public BodyOrientation
{
public:
    NoopOrientation() = default;
    ~NoopOrientation() override = default;
    void getICRFToFixedTransform(const TimePoint& tp, Rotation &rotation) const override {};
    void getICRFToFixedTransform(const TimePoint& tp, KinematicRotation &rotation) const override {};
    void getICRFToInertialTransform(const TimePoint& tp, Rotation &rotation) const override {};
    Axes* getMODParent() const override { return aAxesICRF(); }
    Axes* getTODParent() const override { return aAxesICRF(); }
    void getMODTransform(const TimePoint& tp, Rotation &rot) const override {};
    void getTODTransform(const TimePoint& tp, Rotation &rot) const override {};
};


/*! @} */

AST_NAMESPACE_END
