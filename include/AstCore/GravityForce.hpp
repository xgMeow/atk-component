/// @file      GravityForce.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-21

#pragma once

#include "AstGlobal.h"
#include "BodyAttraction.hpp"
#include <string>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


enum class ESolidTideType{
    eFull,
    ePermanentOnly,
    eNone,
};


class AST_CORE_API GravityForce : public BodyAttraction
{
public:
    AST_OBJECT(GravityForce)
    GravityForce() = default;
    ~GravityForce() = default;
    EBodyAttractionType getBodyAttractionType() const override{return EBodyAttractionType::eGravity;}
    BodyAttraction* clone() const override{return new GravityForce(*this);}
public:
    // 模型与阶次
    std::string model_{};                                  ///< 中心天体重力场模型(模型名称或者引力场文件路径)
    int maxDegree_{0};                                     ///< 中心天体重力场计算阶数
    int maxOrder_{0};                                      ///< 中心天体重力场计算次数
    int maxDegreeForPartial_{-1};                          ///< 用于偏导数计算的重力场最大阶数，-1 表示与 maxDegree_ 相同
    int maxOrderForPartial_{-1};                           ///< 用于偏导数计算的重力场最大次数，-1 表示与 maxOrder_ 相同
    bool useSecularVariations_{false};                     ///< 是否考虑引力场的长期变化
    // 固体潮汐配置参数
    ESolidTideType solidTideType_{ESolidTideType::eNone};  ///< 潮汐类型
    bool includeTimeDependentSolidTides_{false};            ///< 是否考虑时间依赖的潮汐
    double minAmplitudeSolidTides_{0.0};                   ///< 最小潮汐振幅
    bool truncateSolidTides_{false};                       ///< 是否截断潮汐
    // 海洋潮汐配置参数
    bool useOceanTides_{false};                            ///< 是否使用海洋潮汐
    int maxDegreeOceanTides_{2};                           ///< 海洋潮汐计算阶数
    int maxOrderOceanTides_{0};                            ///< 海洋潮汐计算次数
    double minAmplitudeOceanTides_{0.0};                   ///< 最小海洋潮汐振幅
};


/*! @} */

AST_NAMESPACE_END
