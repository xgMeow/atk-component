/// @file      OrbitManeuver.hpp
/// @brief     轨道机动相关计算函数
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-08-29

#pragma once

#include "AstGlobal.h"
#include "AstCore/OrbitElement.hpp"

AST_NAMESPACE_BEGIN

/*!
    @ingroup   
    @defgroup  
    @brief     
*/


/// @brief 计算在拱点施加切向冲量使对向拱点达到指定半径所需的切向速度增量
/// @details 二体轨道下，在拱点（径向速度为0）处沿速度方向施加瞬时切向冲量，
///          不改变机动点半径，仅改变对向拱点半径。速度由 vis-viva 求得：
///          拱点速度 v = sqrt(2·gm·r_other / (r_burn·(r_burn + r_other)))。
///          目标速度以 r_target 替换 r_other 得到，ΔV = v_target − v_current。
///          公式对机动点在近拱点或远拱点均成立（半长轴 = 两拱点半径均值），
///          调用者保证 burnRadius 为机动施加处拱点、currentOtherRadius 为对向拱点即可。
/// @param burnRadius 机动施加处拱点半径 [m]（机动后保持不变）
/// @param currentOtherRadius 当前对向拱点半径 [m]
/// @param targetRadius 目标对向拱点半径 [m]
/// @param gm 引力参数 [m^3/s^2]
/// @return 切向速度增量 [m/s]；正=沿速度方向加速（对向拱点半径增大），负=减速；函数为纯计算，调用方需保证输入合法
AST_CORE_API double aApsisDeltaV(double burnRadius, double currentOtherRadius, double targetRadius, double gm);

/// @brief 计算在拱点施加切向冲量使对向拱点达到指定半径所需的切向速度增量
/// @details 与 aApsisDeltaV 相同，但输入为轨道元素。
/// @param modOrbElem 轨道根数
/// @param targetRadius 目标对向拱点半径 [m]
/// @param gm 引力参数 [m^3/s^2]
/// @return 切向速度增量 [m/s]；正=沿速度方向加速（对向拱点半径增大），负=减速；函数为纯计算，调用方需保证输入合法
AST_CORE_API double aApsisDeltaV(const ModOrbElem& modOrbElem, double targetRadius, double gm);

/// @brief 计算在拱点施加切向冲量使对向拱点达到指定半径所需的切向速度增量
/// @details 与 aApsisDeltaV 相同，但输入为状态量。
/// @param state 状态量
/// @param targetRadius 目标对向拱点半径 [m]
/// @param gm 引力参数 [m^3/s^2]
/// @return 切向速度增量 [m/s]；正=沿速度方向加速（对向拱点半径增大），负=减速；函数为纯计算，调用方需保证输入合法
AST_CORE_API double aApsisDeltaV(const CartState& state, double targetRadius, double gm);



/*! @} */

AST_NAMESPACE_END
