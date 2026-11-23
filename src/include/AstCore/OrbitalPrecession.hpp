/// @file      OrbitalPrecession.hpp
/// @brief     轨道进动
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-02-27

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Orbit
    @{
*/


/// @brief 计算轨道升交点赤经漂移速率
/// @param gm 天体的引力参数
/// @param j2 天体的J2项
/// @param rb 天体的半径
/// @param a 轨道的半长轴
/// @param ecc 轨道的偏心率
/// @param inc 轨道的倾角
/// @return 轨道升交点赤经漂移速率
AST_CORE_CAPI double aRAANRate(double gm, double j2, double rb, double a, double ecc, double inc);

/// @brief 计算轨道近点幅角变化率
/// @param gm 天体的引力参数
/// @param j2 天体的J2项
/// @param rb 天体的半径
/// @param a 轨道的半长轴
/// @param ecc 轨道的偏心率
/// @param inc 轨道的倾角
/// @return 轨道近点幅角变化率
AST_CORE_CAPI double aArgPeriRate(double gm, double j2, double rb, double a, double ecc, double inc);


/// @brief 计算轨道平近点角变化率
/// @param gm 天体的引力参数
/// @param j2 天体的J2项
/// @param rb 天体的半径
/// @param a 轨道的半长轴
/// @param ecc 轨道的偏心率
/// @param inc 轨道的倾角
/// @return 轨道平近点角变化率
AST_CORE_CAPI double aMeanAnomalyRate(double gm, double j2, double rb, double a, double ecc, double inc);



/// @brief 计算维度幅角平均变化率(平近点角变化率 + 近点幅角变化率)
/// @param gm 天体的引力参数
/// @param j2 天体的J2项
/// @param rb 天体的半径
/// @param a 轨道的半长轴
/// @param ecc 轨道的偏心率
/// @param inc 轨道的倾角
/// @return 轨道平近点幅角变化率
AST_CORE_CAPI double aMeanArgLatRate(double gm, double j2, double rb, double a, double ecc, double inc);


/// @brief 计算轨道在J2长期项影响下的轨道周期/交点周期
/// @param gm 天体的引力参数
/// @param j2 天体的J2项
/// @param rb 天体的半径
/// @param a 轨道的半长轴
/// @param ecc 轨道的偏心率
/// @param inc 轨道的倾角
/// @return J2长期项影响下的轨道周期/交点周期
AST_CORE_CAPI double aJ2Period(double gm, double j2, double rb, double a, double ecc, double inc);


/*! @} */

AST_NAMESPACE_END
