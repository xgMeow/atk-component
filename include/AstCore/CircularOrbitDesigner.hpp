/// @file      CircularOrbitDesigner.hpp
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

/// @brief 圆轨道设计器
class AST_CORE_API CircularOrbitDesigner final: public BaseOrbitDesigner
{
public:
    CircularOrbitDesigner();
    explicit CircularOrbitDesigner(CelestialBody* body);
    ~CircularOrbitDesigner() = default;
public:

    using BaseOrbitDesigner::getOrbitState;

    errc_t getOrbitState(ModOrbElem &orbElem) const override;

    /// @brief 获取轨道倾角
    double getInclination() const { return inclination_; }

    /// @brief 获取轨道高度
    double getAltitude() const { return altitude_; }

    /// @brief 获取升交点赤经
    double getRAAN() const { return raan_; }

    /// @brief 设置轨道倾角
    void setInclination(double inclination) { inclination_ = inclination; }

    /// @brief 设置轨道高度
    void setAltitude(double altitude) { altitude_ = altitude; }

    /// @brief 设置升交点赤经
    void setRAAN(double raan) { raan_ = raan; }

protected:
    double inclination_{0};    ///< 轨道倾角
    double altitude_{0};       ///< 轨道高度
    double raan_{0};           ///< 升交点赤经
};

/*! @} */

AST_NAMESPACE_END
