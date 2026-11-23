/// @file      RadiationForce.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-21

#pragma once

#include "AstGlobal.h"
#include "ForceModel.hpp"
#include "AstCore/CelestialBody.hpp"
#include <vector>

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


enum class EShadowModel
{
    eNone,
    eCylindrical,
    eDualCone,
};


/// @brief 太阳辐射压力
/// @details 太阳辐射压力模型
class AST_CORE_API SolarRadiationPressure: public ForceModel
{
public:
    AST_OBJECT(SolarRadiationPressure)

    ESunPosition sunPosition_{ESunPosition::eTrue};      ///< 太阳位置
    bool detectShadowBoundaries_{false};                 ///< 是否检测阴影边界[暂不支持该参数]
    EShadowModel shadowModel_{EShadowModel::eDualCone};  ///< 阴影模型类型
    std::vector<HCelestialBody> eclipsingBodies_{};        ///< 遮挡天体列表
    double atmAltForEclipse_{0.0};                       ///< 用于计算阴影边界的大气高度[暂不支持该参数]
};


/*! @} */

AST_NAMESPACE_END
