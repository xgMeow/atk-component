/// @file      MoonOrientation.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-06

#pragma once

#include "AstGlobal.h"
#include "BodyOrientation.hpp"
#include "RotationalData.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup SolarSystem
    @{
*/

class AST_CORE_API MoonOrientation : public BodyOrientation
{
public:
    AST_OBJECT(MoonOrientation)
    MoonOrientation() = default;
    ~MoonOrientation() override = default;
    void getICRFToFixedTransform(const TimePoint& tp, Rotation &rotation) const override;
    void getICRFToFixedTransform(const TimePoint& tp, KinematicRotation &rotation) const override;
    void getICRFToInertialTransform(const TimePoint& tp, Rotation &rotation) const override;
    Axes* getMODParent() const override;
    void getMODTransform(const TimePoint& tp, Rotation &rot) const override;
    Axes* getTODParent() const override;
    void getTODTransform(const TimePoint& tp, Rotation &rot) const override;
public:
    RotationalData& rotationalData(){return rotation_;}
    const RotationalData& rotationalData() const {return rotation_;}
private:
    RotationalData rotation_{};       ///< 月球的旋转系数
};

/*! @} */

AST_NAMESPACE_END
