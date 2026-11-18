/// @file      atmos76.hpp
/// @brief     ussa1976 大气模型
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

#ifndef SWIG

/// @brief 计算美国标准大气1976的特性
/// @note 内部函数，不建议直接调用
/// @param alt 几何高度, km
/// @param sigma 密度/海平面标准密度
/// @param delta 压力/海平面标准压力
/// @param theta 温度/海平面标准温度
void Atmosphere(
    const double  alt,    
    double& sigma,        
    double& delta,        
    double& theta
);    


#endif

/*! @} */

AST_NAMESPACE_END
