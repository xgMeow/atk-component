/// @file      MSISE90.hpp
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

/// @brief MSISE90大气模型
class AST_CORE_API MSISE90 final: public MSISBase
{
public:
    MSISE90(Frame* frame, BodyShape* bodyShape, double f107Daily, double f107Average, double ap);
    MSISE90(Frame* frame, BodyShape* bodyShape, SpaceWeatherProvider* spaceWeather);

    double getDensity(const TimePoint& tp, const Vector3d& posInBodyFixed) const override;
private:

};


/*! @} */

AST_NAMESPACE_END
