/// @file      OrbitDesign.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-02-25

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Orbit
    @{
*/

/// @brief 计算太阳同步轨道的倾角
/// @param[in] gm 天体引力系数
/// @param[in] j2 天体J2项
/// @param[in] rb 天体半径
/// @param[in] bodyMeanMotion 天体平均公转角速度
/// @param[in] a 轨道半长轴
/// @param[in] ecc 轨道偏心率
/// @param[out] inc 轨道倾角，如果计算失败，则为NaN
/// @return errc_t 错误码
AST_CORE_CAPI errc_t aSunSynchronousInclination(double gm, double j2, double rb, double bodyMeanMotion, double a, double ecc, double& inc);

/// @brief 计算太阳同步轨道的半长轴
/// @param[in] gm 天体引力系数
/// @param[in] j2 天体J2项
/// @param[in] rb 天体半径
/// @param[in] bodyMeanMotion 天体平均公转角速度
/// @param[in] inc 轨道倾角
/// @param[in] ecc 轨道偏心率
/// @param[out] semiMajorAxis 轨道半长轴，如果计算失败，则为NaN
/// @return errc_t 错误码
AST_CORE_CAPI errc_t aSunSynchronousSemiMajorAxis(double gm, double j2, double rb, double bodyMeanMotion, double inc, double ecc, double& semiMajorAxis);


/// @brief 计算太阳同步轨道的倾角
/// @param[in] gm 天体引力系数
/// @param[in] j2 天体J2项
/// @param[in] rb 天体半径
/// @param[in] bodyMeanMotion 天体平均公转角速度
/// @param[in] a 轨道半长轴
/// @param[in] ecc 轨道偏心率
/// @return double 轨道倾角，如果计算失败，则为NaN
A_ALWAYS_INLINE double aSunSynchronousInclination(double gm, double j2, double rb, double bodyMeanMotion, double a, double ecc)
{
    double inc;
    aSunSynchronousInclination(gm, j2, rb, bodyMeanMotion, a, ecc, inc);
    return inc;
}

/// @brief 计算太阳同步轨道的半长轴
/// @param[in] gm 天体引力系数
/// @param[in] j2 天体J2项
/// @param[in] rb 天体半径
/// @param[in] bodyMeanMotion 天体平均公转角速度
/// @param[in] inc 轨道倾角
/// @param[in] ecc 轨道偏心率
/// @return double 轨道半长轴，如果计算失败，则为NaN
A_ALWAYS_INLINE double aSunSynchronousSemiMajorAxis(double gm, double j2, double rb, double bodyMeanMotion, double inc, double ecc)
{
    double semiMajorAxis;
    aSunSynchronousSemiMajorAxis(gm, j2, rb, bodyMeanMotion, inc, ecc, semiMajorAxis);
    return semiMajorAxis;
}

/*! @} */

AST_NAMESPACE_END
