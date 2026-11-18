/// @file      EphemerisMultiSegment.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-19

#pragma once

#include "AstGlobal.h"
#include "AstCore/Ephemeris.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 多段星历
class AST_CORE_API EphemerisMultiSegment: public Ephemeris
{
public:
    Frame* getFrame() const override;
    errc_t getPos(const TimePoint& tp, Vector3d& pos) const override;
    errc_t getPosVel(const TimePoint& tp, Vector3d& pos, Vector3d& vel) const override;
public:
    errc_t getInterval(TimeInterval& interval) const override = 0;
};

/*! @} */

AST_NAMESPACE_END

