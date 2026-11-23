/// @file      Vinti.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-01

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief Vinti 解析解轨道预报（含 J2 / J3 扁率项）
/// @param duration  预报时间 [s]
/// @param gm        引力常数 
/// @param j2        J2 系数 
/// @param j3        J3 系数 
/// @param re        天体半径 [m]
/// @param[out] r    位置 [m]
/// @param[out] v    速度 [m/s]
/// @note  当 duration < 1e-15 时直接返回，r 与 v 保持不变。
AST_CORE_CAPI errc_t aVinti(double duration, double gm, double j2, double j3, double re, Vector3d& r, Vector3d& v);

/*! @} */

AST_NAMESPACE_END
