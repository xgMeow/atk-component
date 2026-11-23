/// @file      SensorLoader.hpp
/// @brief     传感器加载器
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-07

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class Sensor;

/// @brief 加载传感器对象
/// @details 从文件加载传感器对象
/// @param filepath 文件路径
/// @param sensor 传感器对象引用
/// @return 错误码
AST_LOADER_CAPI errc_t aLoadSensor(StringView filepath, Sensor& sensor);

/*! @} */

AST_NAMESPACE_END