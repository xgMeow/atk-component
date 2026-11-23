/// @file      EphemerisNoop.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-08

#pragma once

#include "AstGlobal.h"
#include "AstCore/BodyEphemeris.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup SolarSystem
    @{
*/


class AST_CORE_API BodyEphemerisNoop : public BodyEphemeris
{
public:
    AST_OBJECT(BodyEphemerisNoop)

    BodyEphemerisNoop() = default;
    ~BodyEphemerisNoop() = default;
    errc_t getPosICRF(const TimePoint& time, Vector3d& pos) const override;
    errc_t getPosVelICRF(const TimePoint& time, Vector3d& pos, Vector3d& vel) const override;
    errc_t getInterval(TimeInterval &interval) const override;
};


/*! @} */

AST_NAMESPACE_END
