/// @file      EarthOrientation.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-06

#pragma once

#include "AstGlobal.h"
#include "AstCore/BodyOrientation.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup SolarSystem
    @{
*/


/// @brief 地球旋转类
class AST_CORE_API EarthOrientation final: public BodyOrientation
{
public:
    AST_OBJECT(EarthOrientation)
    EarthOrientation() = default;
    ~EarthOrientation() override = default;
    void getICRFToFixedTransform(const TimePoint& tp, Rotation &rotation) const override;
    void getICRFToFixedTransform(const TimePoint& tp, KinematicRotation &rotation) const override;
    void getICRFToInertialTransform(const TimePoint& tp, Rotation &rotation) const override;
    Axes* getMODParent() const override;
    void getMODTransform(const TimePoint& tp, Rotation &rot) const override;
    Axes* getTODParent() const override;
    void getTODTransform(const TimePoint& tp, Rotation &rot) const override;
};



/*! @} */

AST_NAMESPACE_END
