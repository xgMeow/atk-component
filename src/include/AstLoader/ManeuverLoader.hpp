/// @file      ManeuverLoader.hpp
/// @brief     
/// @details   
/// @author    金柯<jinke18@foxmail.com>
/// @date      2026-04-15

#pragma once

#include "AstGlobal.h"

AST_NAMESPACE_BEGIN

/*!
    @addtogroup 
    @{
*/

class Maneuver;

/// @brief 从值加载 maneuver maneuver任务
/// @param value 值
/// @param maneuver 输出的 maneuver 对象
/// @return errc_t 错误码，0表示成功
AST_LOADER_API errc_t aLoadManeuver(const Value& value, Maneuver& maneuver);


/// @brief 加载 maneuver 任务
/// @param filepath maneuver 文件名
/// @param maneuver 输出的 maneuver 对象
/// @return errc_t 错误码，0表示成功
AST_LOADER_API errc_t aLoadManeuver(StringView filepath, Maneuver& maneuver);

/*! @} */

AST_NAMESPACE_END
