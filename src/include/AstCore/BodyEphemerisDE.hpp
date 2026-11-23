/// @file      EphemerisDE.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-06

#pragma once

#include "AstGlobal.h"
#include "AstCore/BodyEphemeris.hpp"
#include "AstCore/CelestialBody.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup SolarSystem
    @{
*/


class AST_CORE_API BodyEphemerisDE : public BodyEphemeris
{
public:
    AST_OBJECT(BodyEphemerisDE)
    AST_PROPERT(JplIndex)
    BodyEphemerisDE() = default;

    BodyEphemerisDE(const BodyEphemerisDE&) = delete;
    BodyEphemerisDE& operator=(const BodyEphemerisDE&) = delete;

    BodyEphemerisDE(int jplIndex)
        : jplIndex_(jplIndex)
    {}
    BodyEphemerisDE(CelestialBody* body)
        : body_(body)
        , jplIndex_(body->getJplIndex())
    {}

    ~BodyEphemerisDE() override = default;

    errc_t getPosICRF(const TimePoint& tp, Vector3d& pos) const override;

    errc_t getPosVelICRF(const TimePoint& tp, Vector3d& pos, Vector3d& vel) const override;

    errc_t getInterval(TimeInterval& interval) const override;

PROPERTIES:
    int getJplIndex() const;

    void setJplIndex(int jplIndex){jplIndex_ = jplIndex;}
protected:
    CelestialBody* body_{nullptr};
    int jplIndex_{-1};
};


/*! @} */

AST_NAMESPACE_END
