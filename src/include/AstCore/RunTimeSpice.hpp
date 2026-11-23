/// @file      RunTimeSpice.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-22

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Data
    @{
*/



AST_CORE_CAPI
errc_t aSpiceGetPosICRF(
    const TimePoint& time,
    int target,
    int referenceBody,
    Vector3d& pos
);


AST_CORE_CAPI
errc_t aSpiceGetPosVelICRF(
    const TimePoint& time,
    int target,
    int referenceBody,
    Vector3d& pos,
    Vector3d& vel
);


/// @brief 获取目标体的时间间隔
/// @param filepath SPK文件路径
/// @param target 目标体ID
/// @param interval 时间间隔
/// @return errc_t 错误码
/// @note 该函数会解析SPK文件，因此在调用前请确保文件存在
AST_CORE_CAPI
errc_t aSpiceGetInterval(
    StringView filepath,
    int target,
    TimeInterval& interval
);


/// @brief 检查SPICE是否包含指定的天体的星历
/// @param bodyId 天体ID
/// @return bool 是否包含
AST_CORE_CAPI
bool aSpiceHasBodyEphemeris(int bodyId);



/*! @} */

AST_NAMESPACE_END
