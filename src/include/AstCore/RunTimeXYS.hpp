/// @file      RunTimeXYS.hpp
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



/// @brief 获取给定时间点的IAU 理论XYS值（IERS 2010规范）
/// @param tp 时间点
/// @param xys iau xys数据
AST_CORE_API void aTheoreticalXYS_IERS2010(const TimePoint& tp, array3d& xys);


/// @brief 获取给定时间点的IAU 理论XYS值（IERS 2010规范）
/// @param t 时间点（距离J2000.0 TT的儒略日世纪数）
/// @param xys iau xys数据
AST_CORE_API void aTheoreticalXYS_IERS2010(double t, array3d& xys);
AST_CORE_API void aTheoreticalXYS_IERS2010_Cache(double t, array3d& xys);


/// @brief 获取给定时间点的IAU 理论XYS值（IERS 2010规范）
/// @param jdTT 时间点的儒略日数（TT）
/// @param xys iau xys数据
AST_CORE_CAPI void aTheoreticalXYS_IERS2010_TT(const JulianDate& jdTT, array3d& xys);


/// @brief 获取给定时间点的IAU 理论XYS值（预计算数据）
AST_CORE_CAPI errc_t aTheoreticalXYS_IERS2010Precomputed(const TimePoint& tp, array3d& xys);



/// @brief 获取给定时间点的IAU 理论XYS值
/// @param tp 时间点
/// @param xys iau xys数据
AST_CORE_CAPI void aTheoreticalXYS(const TimePoint& tp, array3d& xys);


/// @brief 获取给定时间点的IAU 理论XYS值的修正项
/// @param tp 时间点
/// @param xyCorrection iau xys修正项
AST_CORE_CAPI void aXYCorrection(const TimePoint& tp, array2d& xyCorrection);


/// @brief 获取给定时间点的IAU XYS值（IERS 2010规范，包含修正项）
/// @param tp 时间点
/// @param xys iau xys数据
AST_CORE_CAPI void aXYS_IERS2010(const TimePoint& tp, array3d& xys);


/// @brief 获取给定时间点的IAU XYS值（包含修正项）
/// @param tp 时间点
/// @param xys iau xys数据
AST_CORE_CAPI void aXYS(const TimePoint& tp, array3d& xys);


/*! @} */

AST_NAMESPACE_END
