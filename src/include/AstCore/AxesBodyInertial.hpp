/// @file      AxesBodyInertial.hpp
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
class AxesBodyInertial;
using PAxesBodyInertial = AxesBodyInertial*;
using HAxesBodyInertial = SharedPtr<AxesBodyInertial>;


/// @brief  天体惯性轴系
class AST_CORE_API AxesBodyInertial : public AxesBodyRelated
{
public:
    static PAxesBodyInertial New(CelestialBody* body);
    static HAxesBodyInertial NewShared(CelestialBody* body);

    using AxesBodyRelated::AxesBodyRelated;
    Axes* getParent() const override;
    errc_t getTransform(const TimePoint& tp, Rotation& rotation) const override;
    errc_t getTransform(const TimePoint& tp, KinematicRotation& rotation) const override;
};

/*! @} */

AST_NAMESPACE_END
