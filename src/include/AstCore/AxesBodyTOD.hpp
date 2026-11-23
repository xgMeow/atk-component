/// @file      AxesBodyTOD.hpp
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
class AxesBodyTOD;
using PAxesBodyTOD = AxesBodyTOD*;
using HAxesBodyTOD = SharedPtr<AxesBodyTOD>;

/// @brief  天体TOD轴系
class AST_CORE_API AxesBodyTOD : public AxesBodyRelated
{
public:
    static PAxesBodyTOD New(CelestialBody* body);
    static HAxesBodyTOD NewShared(CelestialBody* body);

    using AxesBodyRelated::AxesBodyRelated;
    Axes* getParent() const override;
    errc_t getTransform(const TimePoint& tp, Rotation& rotation) const override;
    errc_t getTransform(const TimePoint& tp, KinematicRotation& rotation) const override;
};



/*! @} */

AST_NAMESPACE_END
