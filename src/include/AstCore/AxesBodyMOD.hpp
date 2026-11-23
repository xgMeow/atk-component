/// @file      AxesBodyMOD.hpp
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
class AxesBodyMOD;
using PAxesBodyMOD = AxesBodyMOD*;
using HAxesBodyMOD = SharedPtr<AxesBodyMOD>;



/// @brief  天体MOD轴系
class AST_CORE_API AxesBodyMOD : public AxesBodyRelated
{
public:
    static PAxesBodyMOD New(CelestialBody* body);
    static HAxesBodyMOD NewShared(CelestialBody* body);

    using AxesBodyRelated::AxesBodyRelated;
    Axes* getParent() const override;
    errc_t getTransform(const TimePoint& tp, Rotation& rotation) const override;
    errc_t getTransform(const TimePoint& tp, KinematicRotation& rotation) const override;
};



/*! @} */

AST_NAMESPACE_END
