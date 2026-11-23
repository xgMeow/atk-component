/// @file      HarrisPriester.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-27

#pragma once

#include "AstGlobal.h"
#include "AtmosphereBase.hpp"
#include "AstCore/SunPosition.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class AST_CORE_API HarrisPriester: public AtmosphereBase
{
public:
    HarrisPriester(Frame* frame, BodyShape* bodyShape, CelestialBody* sun, double f107);

    HarrisPriester(const HarrisPriester&) = delete;
    HarrisPriester& operator=(const HarrisPriester&) = delete;

    double getDensity(const TimePoint& tp, const Vector3d& posInBodyFixed) const override;

    void setSunPosition(ESunPosition sunPosition){sunPosition_ = sunPosition;}
    ESunPosition getSunPosition() const {return sunPosition_;}
private:
    CelestialBody* sun_{nullptr};
    double f107_{0};
    ESunPosition sunPosition_{ESunPosition::eTrue};
    int n_{6};  ///< 余弦指数 [2-6]
};

/*! @} */

AST_NAMESPACE_END
