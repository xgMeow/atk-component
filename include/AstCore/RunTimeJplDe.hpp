/// @file      RunTimeJplDe.hpp
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


/// @brief 获取JPL DE星历数据的位置和速度（ICRF）
/// @param time 
/// @param target 
/// @param referenceBody 
/// @param pos 
/// @param vel 
/// @return 
AST_CORE_CAPI errc_t aJplDeGetPosVelICRF(
    const TimePoint& time, 
    int target, 
    int referenceBody, 
    Vector3d& pos,
    Vector3d& vel
);

/// @brief 获取JPL DE星历数据的位置（ICRF）
/// @param time 
/// @param target 
/// @param referenceBody 
/// @param pos 
/// @return 
AST_CORE_CAPI errc_t aJplDeGetPosICRF(
    const TimePoint& time,
    int target,
    int referenceBody,
    Vector3d& pos
);


/// @brief 获取JPL DE星历数据的中章动角数据
/// @param time 
/// @param dpsi 
/// @param deps 
/// @return 
AST_CORE_CAPI errc_t aJplDeGetNutation(
    const TimePoint& time,
    double& dpsi,
    double& deps
);


/// @brief 获取JPL DE星历数据的月球天平动相关角度（Euler）
/// @param time 
/// @param ang  - 从ICRF到月球惯性主轴坐标系的转角(rad)
///             - [omega,i,u],[进动角,章动角,自转角],按照313顺序旋转
/// @param angRate - 旋转角速度(rad/s)
/// @return 
AST_CORE_API errc_t aJplDeGetLibration(
    const TimePoint &time, 
    Euler &ang, 
    Euler& angRate
);


/// @brief 获取JPL DE星历数据的月面天平动相关角度（Euler）
/// @param time 
/// @param ang  - 从ICRF到月球惯性主轴坐标系的转角(rad)
///             - [omega,i,u],[进动角,章动角,自转角],按照313顺序旋转
/// @return 
AST_CORE_API errc_t aJplDeGetLibration(
    const TimePoint& time,
    Euler& ang
);


/// @brief 获取JPL DE星历数据的时间间隔
/// @param interval 
/// @return 
AST_CORE_CAPI errc_t aJplDeGetInterval(
    TimeInterval& interval
);


/// @brief 获取JPL DE星历数据的版本号
/// @return 星历版本号
AST_CORE_CAPI int aJplDeNum();


/// @brief 获取JPL DE星历数据的引力常数（m³/s²）
/// @param bodyIndex 
/// @param GM 
/// @return 
AST_CORE_CAPI errc_t aJplDeGetBodyGM(int bodyIndex, double& GM);


A_ALWAYS_INLINE double aJplDeGetBodyGM(int bodyIndex)
{
    double GM{};
    aJplDeGetBodyGM(bodyIndex, GM);
    return GM;
}


/// @brief 打开JPL DE星历数据文件
/// @param filepath 
/// @return 
AST_CORE_CAPI errc_t aJplDeOpen(const char* filepath);



/// @brief 关闭JPL DE星历数据文件
AST_CORE_CAPI void aJplDeClose();


/*! @} */

AST_NAMESPACE_END
