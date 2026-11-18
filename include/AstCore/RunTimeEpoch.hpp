/// @file      RunTimeEpoch.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-16

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Data
    @{
*/

/// @brief 将时间点转换为相对参考历元的秒数
/// @param tp 时间点
/// @return 参考历元秒数
AST_CORE_CAPI double aTimePointToEpochSecond(const TimePoint& tp);

/// @brief 将相对参考历元的秒数转换为时间点
/// @param epochSecond 参考历元秒数
/// @param tp 时间点
AST_CORE_CAPI void aEpochSecondToTimePoint(double epochSecond, TimePoint& tp);

/// @brief 设置参考历元
/// @param tp 时间点
AST_CORE_CAPI void aSetEpoch(const TimePoint& tp);

/// @brief 获取参考历元
/// @return 参考历元
AST_CORE_CAPI void aGetEpoch(TimePoint& tp);



/*! @} */

AST_NAMESPACE_END
