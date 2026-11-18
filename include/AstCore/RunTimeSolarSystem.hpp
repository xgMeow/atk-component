/// @file      RunTimeSolarSystem.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-02-22

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Data
    @{
*/

class SolarSystem;
class CelestialBody;

/// @brief 获取太阳系
AST_CORE_CAPI SolarSystem* aGetSolarSystem();

/// @brief 获取指定名称的天体
AST_CORE_CAPI CelestialBody* aGetBody(StringView name);

/// @brief 获取默认天体
AST_CORE_CAPI CelestialBody* aGetDefaultBody();

/// @brief 获取水星
AST_CORE_CAPI CelestialBody* aGetMercury();

/// @brief 获取金星
AST_CORE_CAPI CelestialBody* aGetVenus();

/// @brief 获取地球
AST_CORE_CAPI CelestialBody* aGetEarth();

/// @brief 获取火星
AST_CORE_CAPI CelestialBody* aGetMars();

/// @brief 获取木星
AST_CORE_CAPI CelestialBody* aGetJupiter();

/// @brief 获取土星
AST_CORE_CAPI CelestialBody* aGetSaturn();

/// @brief 获取天王星
AST_CORE_CAPI CelestialBody* aGetUranus();

/// @brief 获取海王星
AST_CORE_CAPI CelestialBody* aGetNeptune();

/// @brief 获取冥王星
AST_CORE_CAPI CelestialBody* aGetPluto();

/// @brief 获取月球
AST_CORE_CAPI CelestialBody* aGetMoon();

/// @brief 获取太阳
AST_CORE_CAPI CelestialBody* aGetSun();

/// @brief 获取太阳系质心
AST_CORE_CAPI CelestialBody* aGetSSBarycenter();

/// @brief 获取地月质心
AST_CORE_CAPI CelestialBody* aGetEMBarycenter();



/*! @} */

AST_NAMESPACE_END


