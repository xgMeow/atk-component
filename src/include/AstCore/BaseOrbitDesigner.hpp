/// @file      BaseOrbitDesigner.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-02-22

#pragma once

#include "AstGlobal.h"
#include "AstCore/OrbitElement.hpp"
#include "AstCore/Frame.hpp"
#include "AstCore/CelestialBody.hpp"
#include "AstCore/TimePoint.hpp"
#include "AstUtil/SharedPtr.hpp"


AST_NAMESPACE_BEGIN

/*!
    @addtogroup Orbit
    @{
*/

/// @brief 轨道设计器接口
class AST_CORE_API IOrbitDesigner
{
public:
    IOrbitDesigner() = default;
    virtual ~IOrbitDesigner() = default;

    virtual errc_t getOrbitEpoch(TimePoint& orbitEpoch) const = 0;

    /// @brief 获取轨道状态
    /// @param orbitEpoch 轨道历元（可选）
    /// @param orbElem 轨道根数
    virtual errc_t getOrbitState(ModOrbElem &orbElem) const = 0;

    /// @brief 获取坐标系定义
    /// @param useCoordEpoch 是否使用坐标系历元
    /// @param coordEpoch 坐标系历元（可选）
    /// @param coordFrame 坐标系
    virtual errc_t getCoordFrame(bool& useCoordEpoch, TimePoint& coordEpoch, SharedPtr<Frame>& coordFrame) const = 0;
};


/// @brief 轨道设计器基类
class AST_CORE_API BaseOrbitDesigner: public IOrbitDesigner
{
public:
    BaseOrbitDesigner();
    explicit BaseOrbitDesigner(CelestialBody* body);
    ~BaseOrbitDesigner() = default;

    using IOrbitDesigner::getOrbitState;

    static CelestialBody* getDefaultCelestialBody();

    /// @brief 获取天体
    CelestialBody* getCelestialBody() const { return celestialBody_.get(); }

    /// @brief 获取引力参数
    double getGM() const { return celestialBody_?celestialBody_->getGM(): 0; }

    /// @brief 获取J2项
    double getJ2() const {return celestialBody_?celestialBody_->getJ2():0; }

    /// @brief 获取天体半径
    double getBodyRadius() const { return celestialBody_?celestialBody_->getRadius():0; }

    /// @brief 获取轨道历元
    errc_t getOrbitEpoch(TimePoint& orbitEpoch) const final{ orbitEpoch = orbitEpoch_; return 0; };

    /// @brief 获取轨道状态
    /// @param cartState 笛卡尔状态
    errc_t getOrbitState(CartState &cartState) const;

    /// @brief 获取轨道状态
    /// @param orbElem 轨道根数
    errc_t getOrbitState(OrbElem &orbElem) const;

    errc_t getCoordFrame(bool& useCoordEpoch, TimePoint& coordEpoch, SharedPtr<Frame>& coordFrame) const override;
protected:
    SharedPtr<CelestialBody> celestialBody_;    ///< 天体
    TimePoint orbitEpoch_{};    ///< 轨道历元
};


/*! @} */

AST_NAMESPACE_END
