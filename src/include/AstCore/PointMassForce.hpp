/// @file      TwoBody.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-21

#pragma once

#include "AstGlobal.h"
#include "BodyAttraction.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 点质量引力模型/
class AST_CORE_API PointMassForce: public BodyAttraction
{
public:
    AST_OBJECT(PointMassForce)

    EBodyAttractionType getBodyAttractionType() const override{return EBodyAttractionType::ePointMass;}
    BodyAttraction* clone() const override{return new PointMassForce(*this);}

    /// @brief 根据三体配置获取引力常数
    double getGM(CelestialBody* body) const;
public:
    /// @brief 设置指定的引力常数，并将引力常数来源枚举设置为来自指定值
    /// @param gm 指定的引力常数
    void setSpecifiedGM(double gm){specifiedGM_ = gm; gmSource_ = EGMSource::eSpecifiedValue;}
public:
    EGMSource gmSource_{EGMSource::eBodyGravity};       ///< 引力常数来源
    double specifiedGM_{0.0};                           ///< 指定的引力常数
};


/*! @} */

AST_NAMESPACE_END
