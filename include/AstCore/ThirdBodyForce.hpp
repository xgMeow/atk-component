/// @file      ThirdBodyForce.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-21

#pragma once

#include "AstGlobal.h"
#include "BodyAttraction.hpp"
#include "AstCore/CelestialBody.hpp"
#include "AstCore/PointMassForce.hpp"
#include "AstCore/GravityForce.hpp"
#include "AstUtil/ClonePtr.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/



/// @brief 三体引力模型
class AST_CORE_API ThirdBodyForce: public ForceModel
{
public:
    AST_OBJECT(ThirdBodyForce)

    ThirdBodyForce() = default;

    ThirdBodyForce(CelestialBody* body)
        : body_(body)
    {}

    /// @brief 获取引力场模型
    /// @return 引力场模型
    GravityForce& gravity(){return gravity_;}
    const GravityForce& gravity() const {return gravity_;}

    /// @brief 获取点质量引力模型
    /// @return 点质量引力模型
    PointMassForce& pointMass(){return pointMass_;}
    const PointMassForce& pointMass() const {return pointMass_;}

    /// @brief 获取三体引力模型
    /// @return 三体引力模型
    BodyAttraction& bodyAttraction();

    /// @brief 获取三体引力模型
    /// @return 三体引力模型
    const BodyAttraction& bodyAttraction() const;

    /// @brief 获取三体引力类型
    /// @return 三体引力类型
    EBodyAttractionType bodyAttractionType() const;

    /// @brief 设置三体引力类型
    /// @param type 三体引力类型
    void setAttractionType(EBodyAttractionType type);

    /// @brief 获取三体
    CelestialBody* body() const;

    /// @brief 设置三体
    void setBody(CelestialBody* body);

    /// @brief 获取星历来源
    EEphemerisSource ephemerisSource() const{return ephemerisSource_;}

    /// @brief 设置星历来源
    void setEphemerisSource(EEphemerisSource source){ephemerisSource_ = source;}
private:
    HCelestialBody body_{};                                                       ///< 天体
    EEphemerisSource ephemerisSource_{EEphemerisSource::eBodyEphemeris};        ///< 星历来源
    EBodyAttractionType attractionType_{EBodyAttractionType::ePointMass};       ///< 引力类型
    PointMassForce pointMass_{};                                                ///< 点质量引力模型
    GravityForce gravity_{};                                                    ///< 引力场模型
};


/*! @} */

AST_NAMESPACE_END
