/// @file      FrameICRF.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-11

#pragma once

#include "AstGlobal.h"
#include "AstCore/Frame.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Coordinate
    @{
*/

class Point;
class Axes;

class AST_CORE_API FrameICRF : public Frame
{
public:
    FrameICRF() = default;
    ~FrameICRF() override = default;
    static FrameICRF* Instance();

    Frame* getParent() const override;
    Axes* getAxes() const override;
    Point* getOrigin() const override;
    errc_t getTransform(const TimePoint& tp, Transform& transform) const override;
    errc_t getTransform(const TimePoint& tp, KinematicTransform& transform) const override;
    errc_t getTransform(const TimePoint& tp, AccelerationTransform& transform) const override;
};

A_ALWAYS_INLINE Frame* aFrameICRF()
{
    return FrameICRF::Instance();
}

/*! @} */

AST_NAMESPACE_END
