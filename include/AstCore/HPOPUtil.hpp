/// @file      HPOPUtil.hpp
/// @brief     高精度轨道预报的辅助工具函数
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-09-04

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class HPOP;
class HPOPEquation;

/// @brief 在无需重新初始化HPOP方程的情况下设置阻力系数
/// @details 其内部实现可能会随版本变化而更改，但是接口会保持不变
/// @param equation HPOP方程实例
/// @param cd 阻力系数参数值
/// @return 
AST_CORE_CAPI errc_t aHPOPEquation_SetDragCoefficient(HPOPEquation* equation, double cd);


/// @brief 在无需重新初始化HPOP方程的情况下设置SRP光压系数
/// @details 其内部实现可能会随版本变化而更改，但是接口会保持不变
/// @param equation HPOP方程实例
/// @param cr SRP光压系数参数值
/// @return 
AST_CORE_CAPI errc_t aHPOPEquation_SetSRPCoefficient(HPOPEquation* equation, double cr);


/*
note:
为什么不写为 aHPOP_SetSRPCoefficient？
因为这也声明会存在歧义，而该函数并不会修改 HPOP.forceModel() 中的 SRP光压系数，阻力系数同理
*/

/*! @} */

AST_NAMESPACE_END
