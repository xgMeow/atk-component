/// @file      AttitudeSunRelated.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-10-05

#pragma once

#include "AstGlobal.h"
#include "AttitudeTrajectoryRelated.hpp"
#include "AstCore/CelestialBody.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 太阳相关姿态
class AST_CORE_API AttitudeSunRelated : public AttitudeTrajectoryRelated
{
public:
    AttitudeSunRelated();
    ~AttitudeSunRelated() = default;
public:
    void setSun(Body* sun){sun_ = sun;}
    Body* sun() const { return sun_.get(); }
protected:
    errc_t getSunPosLocal(const TimePoint& tp, Vector3d& sunPos) const;
    errc_t getSunPosVelLocal(const TimePoint& tp, Vector3d& sunPos, Vector3d& sunVel) const;
private:
    WeakPtr<CelestialBody> sun_{};  ///< 太阳(光源天体)
};


/*! @} */

AST_NAMESPACE_END
