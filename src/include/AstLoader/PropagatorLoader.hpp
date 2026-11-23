/// @file      PropagatorLoader.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-21

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class HPOP;

/// @brief 加载轨道预报器
/// @param filename 轨道预报器文件配置文件
/// @param propagator 轨道预报器
/// @return 错误码
AST_LOADER_API errc_t aLoadPropagator(StringView filename, HPOP& propagator);

/// @brief 载入轨道预报器
/// @param value 配置值
/// @param propagator 轨道预报器
/// @return 错误码
AST_LOADER_API errc_t aLoadPropagator(const Value& value, HPOP& propagator);


/*! @} */

AST_NAMESPACE_END
