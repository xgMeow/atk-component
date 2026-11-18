/// @file      StationaryOrbitDesigner.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-02-22

#pragma once

#include "AstGlobal.h"
#include "BaseOrbitDesigner.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Orbit
    @{
*/


/// @brief 静止轨道设计器
class AST_CORE_API StationaryOrbitDesigner final: public BaseOrbitDesigner
{
public:
    StationaryOrbitDesigner();
    explicit StationaryOrbitDesigner(CelestialBody *body);
    ~StationaryOrbitDesigner() = default;

    using BaseOrbitDesigner::getOrbitState;

    errc_t getOrbitState(ModOrbElem &orbElem) const override;

    /// @brief 获取星下点经度
    double getSubsatellitePoint() const { return subsatellitePoint_; }

    /// @brief 获取轨道倾角
    double getInclination() const { return inclination_; }

    /// @brief 设置星下点经度
    void setSubsatellitePoint(double subsatellitePoint) { subsatellitePoint_ = subsatellitePoint; }

    /// @brief 设置轨道倾角
    void setInclination(double inclination) { inclination_ = inclination; }
protected:
    double subsatellitePoint_{0};       ///< 星下点经度
    double inclination_{0};             ///< 轨道倾角
};

/*! @} */

AST_NAMESPACE_END
