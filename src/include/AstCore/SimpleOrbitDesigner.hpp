/// @file      SimpleOrbitDesigner.hpp
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

/// @brief 基础轨道设计器
class AST_CORE_API SimpleOrbitDesigner final: public BaseOrbitDesigner
{
public:
    SimpleOrbitDesigner();
    explicit SimpleOrbitDesigner(CelestialBody *body);
    ~SimpleOrbitDesigner() = default;
public:
    using BaseOrbitDesigner::getOrbitState;

    errc_t getOrbitState(ModOrbElem &orbElem) const override;

    /// @brief 获取半长轴
    double getSemimajorAxis() const { return semimajorAxis_; }
    /// @brief 获取偏心率
    double getEccentricity() const { return eccentricity_; }
    /// @brief 获取倾角
    double getInclination() const { return inclination_; }
    /// @brief 获取升交点赤经
    double getRightAscensionOfAscendingNode() const { return rightAscensionOfAscendingNode_; }
    /// @brief 获取近点幅角
    double getArgumentOfPeriapsis() const { return argumentOfPeriapsis_; }
    /// @brief 获取真近点角
    double getTrueAnomaly() const { return trueAnomaly_; }

    /// @brief 设置半长轴
    void setSemimajorAxis(double semimajorAxis) { semimajorAxis_ = semimajorAxis; }
    /// @brief 设置偏心率
    void setEccentricity(double eccentricity) { eccentricity_ = eccentricity; }
    /// @brief 设置倾角
    void setInclination(double inclination) { inclination_ = inclination; }
    /// @brief 设置升交点赤经
    void setRightAscensionOfAscendingNode(double rightAscensionOfAscendingNode) { rightAscensionOfAscendingNode_ = rightAscensionOfAscendingNode; }
    /// @brief 设置近点幅角
    void setArgumentOfPeriapsis(double argumentOfPeriapsis) { argumentOfPeriapsis_ = argumentOfPeriapsis; }
        /// @brief 设置真近点角
    void setTrueAnomaly(double trueAnomaly) { trueAnomaly_ = trueAnomaly; }
protected:
    double semimajorAxis_{0.0};                     ///< 半长轴 a
    double eccentricity_{0.0};                      ///< 偏心率 e
    double inclination_{0.0};                       ///< 倾角 i
    double rightAscensionOfAscendingNode_{0.0};     ///< 升交点赤经RAAN Ω
    double argumentOfPeriapsis_{0.0};               ///< 近点幅角 ω
    double trueAnomaly_{0.0};                       ///< 真近点角 f
};

/*! @} */

AST_NAMESPACE_END
