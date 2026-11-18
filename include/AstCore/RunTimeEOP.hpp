/// @file      RunTimeEOP.hpp
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


/// @brief 获取UT1时间与UTC时间的差值（秒）
/// @param jdUTC 协调世界时（UTC）的儒略日数
/// @return UT1时间与UTC时间的差值（秒）
AST_CORE_CAPI double aUT1MinusUTC_UTC(const JulianDate& jdUTC);


struct PoleMotion
{
    double x, y;            ///< 极移
};

/// @brief 获取给定时间点的极移
/// @param tp 时间点
/// @param x 极移x
/// @param y 极移y
AST_CORE_CAPI void aPoleMotion(const TimePoint& tp, double& x, double& y);


/// @brief 获取给定UTC时间的极移
/// @param jdUTC 协调世界时（UTC）的儒略日数
/// @param x 极移x
/// @param y 极移y
AST_CORE_CAPI void aPoleMotionUTC(const JulianDate& jdUTC, double& x, double& y);


/// @brief 获取给定时间点的极移
/// @param tp 时间点
/// @param pm 极移
A_ALWAYS_INLINE void aPoleMotion(const TimePoint& tp, PoleMotion& pm)
{
    return aPoleMotion(tp, pm.x, pm.y);
}



/// @brief 获取给定时间点的LOD（秒）
/// @param tp 时间点
/// @return LOD（秒）
AST_CORE_CAPI double aLOD(const TimePoint& tp);



/*! @} */

AST_NAMESPACE_END
