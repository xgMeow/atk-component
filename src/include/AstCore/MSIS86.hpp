/// @file      MSIS86.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-25

#pragma once

#include "AstGlobal.h"
#include "AtmosphereBase.hpp"
#include "MSISBase.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief MSIS86大气模型
class AST_CORE_API MSIS86 final: public MSISBase
{
public:
    MSIS86(Frame* frame, BodyShape* bodyShape, double f107Daily, double f107Average, double ap);
    MSIS86(Frame* frame, BodyShape* bodyShape, SpaceWeatherProvider* spaceWeather);
    double getDensity(const TimePoint& tp, const Vector3d& posInBodyFixed) const override;

};

/*! @} */

AST_NAMESPACE_END
