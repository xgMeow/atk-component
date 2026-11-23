/// @file      HarrisPriester.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-06-26

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

/// @brief 通过HarrisPriester模型计算大气密度
/// @param pos 位置 [m]
/// @param sunpos 太阳位置 [m]
/// @param altitude 海拔高度 [m]
/// @param f107 F10.7 太阳辐射通量
/// @param n 余弦指数 [2-6]
/// @return 大气密度 [kg/m³]
/// @warning 输入的位置向量和太阳位置向量必须在同一个坐标系下
AST_WEATHER_CAPI double aHarrisPriester(
    const Vector3d& pos,
    const Vector3d& sunpos,
    double altitude,
    double f107,
    int n
);

/*! @} */

AST_NAMESPACE_END
