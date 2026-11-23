/// @file      CriticallyInclinedSunSyncOrbitDesigner.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-02-22

#pragma once

#include "AstGlobal.h"
#include "AstCore/BaseOrbitDesigner.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief      太阳同步临界倾角轨道/太阳同步冻结轨道设计器
class AST_CORE_API CriticallyInclinedSunSyncOrbitDesigner final: public BaseOrbitDesigner
{
public:
    CriticallyInclinedSunSyncOrbitDesigner();
    explicit CriticallyInclinedSunSyncOrbitDesigner(CelestialBody* body);
    ~CriticallyInclinedSunSyncOrbitDesigner() = default;

    using BaseOrbitDesigner::getOrbitState;

    errc_t getOrbitState(ModOrbElem& orbElem) const override;

    double getPerigeeAltitude() const { return perigeeAltitude_; }

    double getRAAN() const { return raan_; }

    void setPerigeeAltitude(double perigeeAltitude) { perigeeAltitude_ = perigeeAltitude; }

    void setRAAN(double raan) { raan_ = raan; }
protected:
    double perigeeAltitude_{0};     ///< 近地点高度
    double raan_{0};                ///< 升交点赤经
};

/*! @} */

AST_NAMESPACE_END
