/// @file      AxesBodyFixed.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-06

#pragma once

#include "AstGlobal.h"
#include "AstCore/AxesBodyRelated.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Coordinate
    @{
*/

class CelestialBody;
class BodyOrientation;
class AxesBodyFixed;
using HAxesBodyFixed = SharedPtr<AxesBodyFixed>;
using PAxesBodyFixed = AxesBodyFixed*;

/// @brief 天体固连轴系
class AST_CORE_API AxesBodyFixed: public AxesBodyRelated
{
public:
    static PAxesBodyFixed New(CelestialBody* body);
    static HAxesBodyFixed NewShared(CelestialBody* body);

    using AxesBodyRelated::AxesBodyRelated;
    Axes* getParent() const override;
    errc_t getTransform(const TimePoint& tp, Rotation& rotation) const override;
    errc_t getTransform(const TimePoint& tp, KinematicRotation& rotation) const override;
};

/*! @} */

AST_NAMESPACE_END
