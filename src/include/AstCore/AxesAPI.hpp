/// @file      AxesAPI.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-16

#pragma once

#include "AstGlobal.h"
#include "AstCore/Axes.hpp"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/


/// @brief 创建一个历元轴系
/// @details 通过指定一个历元时间，使源轴系相对于参考轴系的旋转关系被固定为常数(即不随时间变换)
/// 如果参考轴系是惯性系，则新创建的历元轴系也将是惯性系，例如历元真赤道系、历元平赤道系等
/// 如果参考轴系不是惯性系，则新创建的历元轴系只是与参考轴系保持旋转关系不变(即不随时间变换)，其并不是惯性系
/// @param sourceAxes 源轴系
/// @param tp 历元时间点
/// @param referenceAxes 参考轴系
/// @return 新的历元轴系统
AST_CORE_API HAxes aMakeEpochAxes(Axes* sourceAxes, const TimePoint& tp, Axes* referenceAxes);


/// @brief 创建一个历元轴系
/// @details 通过指定一个历元时间，使源轴系相对于参考轴系的旋转关系被固定为常数(即不随时间变换)
/// 如果参考轴系是惯性系，则新创建的历元轴系也将是惯性系，例如历元真赤道系、历元平赤道系等
/// 如果参考轴系不是惯性系，则新创建的历元轴系只是与参考轴系保持旋转关系不变(即不随时间变换)，其并不是惯性系
/// @param sourceAxes 源轴系
/// @param time 历元时间点
/// @param referenceAxes 参考轴系
/// @return 新的历元轴系统
AST_CORE_API HAxes aMakeEpochAxes(Axes* sourceAxes, EventTime* time, Axes* referenceAxes);


/*! @} */

AST_NAMESPACE_END
