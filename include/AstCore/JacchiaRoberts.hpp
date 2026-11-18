/// @file      JacchiaRoberts.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-26

#pragma once

#include "AstGlobal.h"
#include "AstCore/AtmosphereBase.hpp"
#include "AstCore/SunPosition.hpp"


AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief Jacchia Roberts大气模型
class AST_CORE_API JacchiaRoberts final: public AtmosphereBase
{
public:
    JacchiaRoberts(Frame* frame, BodyShape* bodyShape, CelestialBody* sun, double f107Daily, double f107Average, double kp);

    JacchiaRoberts(const JacchiaRoberts&) = delete;
    JacchiaRoberts& operator=(const JacchiaRoberts&) = delete;

    double getDensity(const TimePoint& tp, const Vector3d& posInBodyFixed) const override;

    void setSunPosition(ESunPosition sunPosition){sunPosition_ = sunPosition;}
    ESunPosition getSunPosition() const {return sunPosition_;}
private:
    CelestialBody* sun_{nullptr};
    double F107Daily_{0.0};
    double F107Average_{0.0};
    double kp_{0};
    ESunPosition sunPosition_{ESunPosition::eTrue};
};

/*! @} */

AST_NAMESPACE_END
