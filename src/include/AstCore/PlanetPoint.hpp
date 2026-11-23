/// @file      PlanetPoint.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-03-11

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup Coordinate
    @{
*/


/// @brief 计算水星在ICRF坐标系中的位置
/// @param tp 时间点
/// @param pos 输出的位置
/// @return 错误码
AST_CORE_CAPI errc_t aMercuryPosInICRF(const TimePoint& tp, Vector3d& pos);


/// @brief 计算金星在ICRF坐标系中的位置
/// @param tp 时间点
/// @param pos 输出的位置
/// @return 错误码
AST_CORE_CAPI errc_t aVenusPosInICRF(const TimePoint& tp, Vector3d& pos);


/// @brief 计算地球在ICRF坐标系中的位置
/// @param tp 时间点
/// @param pos 输出的位置
/// @return 错误码
AST_CORE_CAPI errc_t aEarthPosInICRF(const TimePoint& tp, Vector3d& pos);


/// @brief 计算火星在ICRF坐标系中的位置
/// @param tp 时间点
/// @param pos 输出的位置
/// @return 错误码
AST_CORE_CAPI errc_t aMarsPosInICRF(const TimePoint& tp, Vector3d& pos);


/// @brief 计算木星在ICRF坐标系中的位置
/// @param tp 时间点
/// @param pos 输出的位置
/// @return 错误码
AST_CORE_CAPI errc_t aJupiterPosInICRF(const TimePoint& tp, Vector3d& pos);


/// @brief 计算土星在ICRF坐标系中的位置
/// @param tp 时间点
/// @param pos 输出的位置
/// @return 错误码
AST_CORE_CAPI errc_t aSaturnPosInICRF(const TimePoint& tp, Vector3d& pos);


/// @brief 计算天王星在ICRF坐标系中的位置
/// @param tp 时间点
/// @param pos 输出的位置
/// @return 错误码
AST_CORE_CAPI errc_t aUranusPosInICRF(const TimePoint& tp, Vector3d& pos);


/// @brief 计算海王星在ICRF坐标系中的位置
/// @param tp 时间点
/// @param pos 输出的位置
/// @return 错误码
AST_CORE_CAPI errc_t aNeptunePosInICRF(const TimePoint& tp, Vector3d& pos);


/// @brief 计算冥王星在ICRF坐标系中的位置
/// @param tp 时间点
/// @param pos 输出的位置
/// @return 错误码
AST_CORE_CAPI errc_t aPlutoPosInICRF(const TimePoint& tp, Vector3d& pos);


/// @brief 计算月球在ICRF坐标系中的位置
/// @param tp 时间点
/// @param pos 输出的位置
/// @return 错误码
AST_CORE_CAPI errc_t aMoonPosInICRF(const TimePoint& tp, Vector3d& pos);


/// @brief 计算太阳在ICRF坐标系中的位置
/// @param tp 时间点
/// @param pos 输出的位置
/// @return 错误码
AST_CORE_CAPI errc_t aSunPosInICRF(const TimePoint& tp, Vector3d& pos);


/// @brief 计算地月球质在ICRF坐标系中的位置
/// @param tp 时间点
/// @param pos 输出的位置
/// @return 错误码
AST_CORE_CAPI errc_t aEMBarycenterPosInICRF(const TimePoint& tp, Vector3d& pos);


/// @brief 计算水星在ICRF坐标系中的位置和速度
/// @param tp 时间点
/// @param pos 输出的位置
/// @param vel 输出的速度
/// @return 错误码
AST_CORE_CAPI errc_t aMercuryPosVelInICRF(const TimePoint& tp, Vector3d& pos, Vector3d& vel);


/// @brief 计算金星在ICRF坐标系中的位置和速度
/// @param tp 时间点
/// @param pos 输出的位置
/// @param vel 输出的速度
/// @return 错误码
AST_CORE_CAPI errc_t aVenusPosVelInICRF(const TimePoint& tp, Vector3d& pos, Vector3d& vel);


/// @brief 计算地球在ICRF坐标系中的位置和速度
/// @param tp 时间点
/// @param pos 输出的位置
/// @param vel 输出的速度
/// @return 错误码
AST_CORE_CAPI errc_t aEarthPosVelInICRF(const TimePoint& tp, Vector3d& pos, Vector3d& vel);


/// @brief 计算火星在ICRF坐标系中的位置和速度
/// @param tp 时间点
/// @param pos 输出的位置
/// @param vel 输出的速度
/// @return 错误码
AST_CORE_CAPI errc_t aMarsPosVelInICRF(const TimePoint& tp, Vector3d& pos, Vector3d& vel);


/// @brief 计算木星在ICRF坐标系中的位置和速度
/// @param tp 时间点
/// @param pos 输出的位置
/// @param vel 输出的速度
/// @return 错误码
AST_CORE_CAPI errc_t aJupiterPosVelInICRF(const TimePoint& tp, Vector3d& pos, Vector3d& vel);


/// @brief 计算土星在ICRF坐标系中的位置和速度
/// @param tp 时间点
/// @param pos 输出的位置
/// @param vel 输出的速度
/// @return 错误码
AST_CORE_CAPI errc_t aSaturnPosVelInICRF(const TimePoint& tp, Vector3d& pos, Vector3d& vel);


/// @brief 计算天王星在ICRF坐标系中的位置和速度
/// @param tp 时间点
/// @param pos 输出的位置
/// @param vel 输出的速度
/// @return 错误码
AST_CORE_CAPI errc_t aUranusPosVelInICRF(const TimePoint& tp, Vector3d& pos, Vector3d& vel);


/// @brief 计算海王星在ICRF坐标系中的位置和速度
/// @param tp 时间点
/// @param pos 输出的位置
/// @param vel 输出的速度
/// @return 错误码
AST_CORE_CAPI errc_t aNeptunePosVelInICRF(const TimePoint& tp, Vector3d& pos, Vector3d& vel);


/// @brief 计算冥王星在ICRF坐标系中的位置和速度
/// @param tp 时间点
/// @param pos 输出的位置
/// @param vel 输出的速度
/// @return 错误码
AST_CORE_CAPI errc_t aPlutoPosVelInICRF(const TimePoint& tp, Vector3d& pos, Vector3d& vel);


/// @brief 计算月球在ICRF坐标系中的位置和速度
/// @param tp 时间点
/// @param pos 输出的位置
/// @param vel 输出的速度
/// @return 错误码
AST_CORE_CAPI errc_t aMoonPosVelInICRF(const TimePoint& tp, Vector3d& pos, Vector3d& vel);  


/// @brief 计算太阳在ICRF坐标系中的位置和速度
/// @param tp 时间点
/// @param pos 输出的位置
/// @param vel 输出的速度
/// @return 错误码
AST_CORE_CAPI errc_t aSunPosVelInICRF(const TimePoint& tp, Vector3d& pos, Vector3d& vel);


/// @brief 计算地月球质在ICRF坐标系中的位置和速度
/// @param tp 时间点
/// @param pos 输出的位置
/// @param vel 输出的速度
/// @return 错误码
AST_CORE_CAPI errc_t aEMBarycenterPosVelInICRF(const TimePoint& tp, Vector3d& pos, Vector3d& vel);



/*! @} */

AST_NAMESPACE_END
