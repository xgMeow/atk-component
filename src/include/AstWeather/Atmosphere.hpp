/// @file      Atmosphere.hpp
/// @brief     ~
/// @details   ~
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-01-22

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @ingroup Weather
    @defgroup Atmosphere 大气模型
    @brief  包括MSIS系列大气模型、USSA1976大气模型等。
*/


/*!
    @addtogroup Atmosphere
    @{
*/


/// @brief USSA1976大气模型
/// @param alt 高度 [m]
/// @return 大气密度 [kg/m³]
AST_WEATHER_CAPI double aUSSA1976(double alt);


/// @brief JaciachiaRoberts大气模型
/// @details 函数的注释原文请参考 val_atm_jr.cpp 和 val_atm_jr.h
/// @param height 地理高度 [m]
/// @param space_craft TOD GCI 坐标系下的卫星位置 [m]
/// @param sun TOD GCI 坐标系下的太阳向量 [m] 
/// @param a1_time 儒略日减去2430000（即相对于1941-01-05 12:00:00的天数）[A.1 时间系统]
/// @param tkp 地磁指数 [Kp]
/// @param xtemp 外大气层温度[K]
/// @return 大气密度 [kg/m³]
AST_WEATHER_CAPI double aJacchiaRoberts(
    double height, const Vector3d& space_craft, const Vector3d& sun, 
    double a1_time, double tkp, double xtemp
);


/*! @} */

AST_NAMESPACE_END
